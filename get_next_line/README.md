*Este proyecto ha sido creado como parte del currículo de 42 por jucortes.*

# get_next_line

## Descripción

`get_next_line` devuelve **una línea cada vez** de un descriptor de archivo.
Llamándola en bucle se recorre el contenido entero, línea a línea, hasta el final.

```c
char	*get_next_line(int fd);
```

- Devuelve la línea leída, **incluyendo el `\n`**, en memoria del heap que debe
  liberar quien llama.
- La última línea llega **sin `\n`** si el archivo no termina en salto.
- Devuelve `NULL` cuando no queda nada por leer o si hay un error.

La gracia del proyecto no es partir cadenas: es que la función tiene que
**recordar entre llamadas** lo que leyó de más. `read` no lee líneas, lee
bloques de `BUFFER_SIZE` bytes, así que casi siempre se lee más allá del `\n`.
Ese sobrante hay que guardarlo para la llamada siguiente, y el único sitio donde
guardarlo sin usar variables globales (prohibidas) es una **variable estática**.

## Instrucciones

El proyecto no entrega binario ni `Makefile`: el enunciado solo pide
`get_next_line.c`, `get_next_line_utils.c` y `get_next_line.h`, más los tres
`_bonus` del capítulo VI. La función se compila junto al programa que la use.

```sh
# parte obligatoria
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c tu_main.c -o gnl

# parte bonus (varios descriptores a la vez)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line_bonus.c get_next_line_utils_bonus.c tu_main.c -o gnl_bonus
```

`-D BUFFER_SIZE=n` es opcional: si no se pasa, el header usa `1024`. La parte
obligatoria y la bonus definen las dos `get_next_line`, así que **nunca pueden
enlazarse en el mismo binario**: elige un juego de fuentes por compilación.

```c
#include "get_next_line.h"

char	*line;

line = get_next_line(fd);
while (line != NULL)
{
	printf("%s", line);
	free(line);                 /* la línea es tuya: libérala */
	line = get_next_line(fd);
}
```

No se guarda ningún programa de prueba en el repositorio: el enunciado dice que
no se entregan ni se evalúan. Escribe tu `main` fuera y compílalo como arriba.

---

## Cómo funciona

### La idea en una frase

Hay un único `char *` estático, `save`, que guarda **los bytes leídos pero
todavía no entregados**. Cada llamada: lee bloques hasta que en `save` aparezca
un `\n`, corta por ahí, devuelve la primera parte y deja el resto en `save`.

```
                      ┌─────────── save (static) ───────────┐
read() ──bloques──▶   │  "Hola\nmun"                        │
                      └──────┬──────────────────┬───────────┘
                             │ hasta el \n      │ el resto
                             ▼                  ▼
                       devuelve "Hola\n"    save = "mun"
```

### Reparto de funciones

`get_next_line.c` — el algoritmo:

| Función | Qué hace |
|---|---|
| `get_next_line` | Valida `fd` y `BUFFER_SIZE`, y es **la dueña del `static char *save`**. Nada más. |
| `gnl_fill` | El bucle de lectura: llena `save` hasta que haya un `\n` o se acabe el archivo. |
| `gnl_read_buffer` | Un `malloc` + un `read` de `BUFFER_SIZE` bytes, terminado en `\0`. |
| `gnl_split_line` | Corta `save` en dos: la línea que se devuelve y el sobrante que se guarda. |
| `gnl_copy_n` | Copia los primeros `n` bytes a una cadena nueva. |

`get_next_line_utils.c` — herramientas:

| Función | Qué hace |
|---|---|
| `gnl_strlen` | Longitud de una cadena. |
| `gnl_strdup` | Duplica una cadena en el heap. |
| `gnl_join` | Concatena `s1` y `s2` en una cadena nueva **y libera `s1`**. |
| `gnl_has_nl` | ¿Hay un `\n` en esta cadena? (tolera `NULL`) |
| `gnl_line_len` | Bytes hasta el `\n` **incluido**; si no hay, hasta el final. |

### El recorrido, paso a paso

**1. `get_next_line` guarda el estado y delega.**

```c
static char	*save;

if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
return (gnl_fill(fd, &save));
```

`save` es `static`, así que **sobrevive entre llamadas** y se inicializa a `NULL`
la primera vez. Se pasa por dirección (`&save`) para que `gnl_fill` pueda
modificarlo.

**2. `gnl_fill` lee solo lo necesario.**

```c
bytes = 1;
while (bytes > 0 && !gnl_has_nl(*save))
{
	buffer = gnl_read_buffer(fd, &bytes);   /* un read de BUFFER_SIZE */
	...
	*save = gnl_join(*save, buffer);        /* acumula en save */
	free(buffer);
}
return (gnl_split_line(*save, save));
```

Las dos condiciones son las que gobiernan todo:

- `!gnl_has_nl(*save)` — **en cuanto hay un `\n` se para**. No se lee el archivo
  entero: es un requisito explícito del enunciado.
- `bytes > 0` — si `read` devuelve `0` se ha llegado al final del archivo y se
  sale aunque no haya `\n` (último renglón sin salto).

`bytes` arranca en `1` para que el bucle entre al menos una vez. Si `save` ya
traía un `\n` de la llamada anterior, `gnl_has_nl` lo detecta y **no se lee
nada**: se sirve directamente de lo guardado.

**3. `gnl_split_line` hace el corte.**

```c
n = gnl_line_len(buffer);          /* bytes hasta el \n incluido */
line = gnl_copy_n(buffer, n);      /* la línea que se devuelve */
if (buffer[n] == '\0')
	*save = NULL;                  /* no sobraba nada */
else
	*save = gnl_strdup(buffer + n);/* el resto, para la próxima */
free(buffer);
return (line);
```

Si `buffer` está vacío o es `NULL` (no hay nada que entregar), devuelve `NULL` y
deja `save` en `NULL`: así la llamada siguiente también devuelve `NULL` en lugar
de reventar.

### Traza real

Archivo `"Hola\nmundo"` (sin salto final) con `BUFFER_SIZE=4`. Esta tabla es la
salida de ejecutar el código, no un ejemplo escrito a mano:

| Llamada | `save` al entrar | reads | Devuelve | `save` al salir |
|---|---|---|---|---|
| 1 | `NULL` | `"Hola"`, `"\nmun"` | `"Hola\n"` | `"mun"` |
| 2 | `"mun"` | `"do"`, `""` | `"mundo"` | `NULL` |
| 3 | `NULL` | `""` | `NULL` | `NULL` |

Fíjate en la llamada 1: hicieron falta **dos** `read` porque el primer bloque
(`"Hola"`) no contenía el `\n`. Y en la 2 ya había `"mun"` guardado, así que la
línea se completó leyendo solo `"do"`.

### Casos límite

| Entrada | Resultado |
|---|---|
| Archivo vacío | `NULL` en la primera llamada |
| `"\n\n\n"` | tres líneas, cada una `"\n"` |
| Sin salto final | la última línea llega sin `\n` |
| Llamar después del final | `NULL` indefinidamente, sin crash |
| `fd` negativo, cerrado, o un directorio | `NULL` |
| `BUFFER_SIZE` 1 … 10000000 | mismo resultado, solo cambia el número de `read` |

---

## Decisiones técnicas y justificación del algoritmo

**1. Variable estática para el estado.** Un solo `static char *save` guarda el
sobrante. Es el corazón del proyecto y la razón de que las variables globales
estén prohibidas: obliga a usar `static`, que tiene el mismo tiempo de vida pero
alcance limitado al fichero.

**2. El buffer de lectura va al heap, nunca a la pila.** Un
`char buf[BUFFER_SIZE + 1]` local sería una reserva automática en la pila. La
pila de usuario está limitada (`ulimit -s`, unos pocos MiB), así que con
`BUFFER_SIZE = 10000000` ese array pide ~10 MiB y **el programa revienta con
segfault**. Aquí se reserva con `malloc` en el heap:

```c
buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
```

Por eso la función aguanta `1`, `42`, `9999` o `10000000` sin tocar una línea de
código: el tamaño solo afecta a una reserva del heap. Es exactamente la pregunta
que plantea el enunciado.

**3. Leer lo mínimo.** El bucle se corta en cuanto aparece un `\n`. Nunca se
carga el archivo completo en memoria para después trocearlo.

**4. Disciplina de memoria.** La única reserva de vida larga es `save`, que hace
falta para la llamada siguiente. Todo buffer temporal se libera en el mismo
sitio donde se creó, y la línea devuelta pasa a ser propiedad de quien llama.
Los caminos de error también limpian: si `read` falla o un `malloc` falla, se
libera lo que hubiera y `save` queda en `NULL` para no dejar punteros colgantes.

**5. El bonus (varios descriptores).** Un único array estático,
`char *saves[GNL_MAX_FD]` con `GNL_MAX_FD = 512`, donde el índice `fd` guarda el
estado de ese descriptor:

```c
static char	*saves[GNL_MAX_FD];

if (fd < 0 || fd >= GNL_MAX_FD || BUFFER_SIZE <= 0)
	return (NULL);
return (gnl_fill(fd, &saves[fd]));
```

Sigue siendo **una sola variable estática** (un array es una variable), que es lo
que pide el bonus, y permite leer del fd 3, luego del 4, luego del 5 de forma
alterna sin que ninguno pierda su posición ni devuelva la línea de otro. La
comprobación `fd >= GNL_MAX_FD` es imprescindible: sin ella, un descriptor alto
escribiría fuera del array.

## Recursos

- `man 2 read` — la llamada al sistema `read` y su valor de retorno.
- `man 3 malloc`, `man 3 free` — gestión de memoria dinámica.
- *The C Programming Language*, Kernighan & Ritchie — punteros y cadenas.
- [Beej's Guide to C](https://beej.us/guide/bgc/) — `static`, pila frente a heap.
- La Norma de 42 (`norminette`) y `valgrind`.

### Comprobarlo

```sh
valgrind --leak-check=full --error-exitcode=9 ./gnl <fichero>
norminette get_next_line*.c get_next_line*.h
```

Con una lectura completa valgrind no reporta nada. Si el programa termina **sin
llegar al final** del archivo, el sobrante sigue en `save` y valgrind lo marca
como `still reachable` (no `definitely lost`): es inevitable con una variable
estática y se acepta en la evaluación.

### Uso de la IA

La IA se usó como **asistente de desarrollo y revisión**: proponer una
estructura inicial, explicar conceptos de C (variables estáticas, diferencia
entre pila y heap, `malloc`/`free`), y reescribir el código hasta pasar la Norma
y `valgrind`. También se usó para revisar el código contra el enunciado y para
redactar este README. Cada línea del código final está revisada y entendida: soy
capaz de explicar el flujo completo, el papel de la variable estática, cómo se
corta la línea del buffer y por qué el buffer de lectura va al heap y no a la
pila. No se usó IA para resolver la lógica del algoritmo.
