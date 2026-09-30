*Este proyecto ha sido creado como parte del currículo de 42 por jucortes.*

## Descripción

`ft_printf` reimplementa la función `printf()` de la libc en C. El prototipo es idéntico al
original:

```c
int ft_printf(char const *str, ...);
```

Devuelve el **número exacto de caracteres escritos**, igual que `printf`, y soporta las
conversiones obligatorias del enunciado: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` y `%`.

**Objetivo.** Aprender a utilizar funciones variádicas (`va_start`, `va_arg`, `va_end`),
manejar memoria dinámicamente sin fugas y estructurar una librería de C extensible de la que
disfrutar en futuros proyectos (puede incluirse en la libft).

**Visión general.** La librería se construye como `libftprintf.a` mediante un Makefile que
compila primero `libft` (incluida en `libft/`) y después las fuentes de `src/` con
`-Wall -Wextra -Werror`, usando `cc` y `ar`.

El comportamiento ha sido validado contra el `printf` de glibc en los casos del subject:
misma salida y mismo valor de retorno, incluyendo `(nil)` para `%p` con puntero nulo,
`INT_MIN`/`INT_MAX`, `UINT_MAX`, y conversión inválida (se devuelve `-1` sin imprimir,
como glibc).

## Instrucciones

Compilación:

```sh
make         # compila libft/ y las fuentes de src/ y genera libftprintf.a
make clean   # borra los objetos
make fclean  # borra también la librería
make re      # fclean + all
```

Verificación de la norma:

```sh
norminette src include
```

Uso. Por ejemplo, crear un `main_test.c`:

```c
#include <ft_printf.h>

int main(void)
{
    ft_printf("entero: %d, string: %s, hex: %x\n", 42, "hola", 255);
}
```

Enlazar:

```sh
cc -Wall -Wextra -Werror -I./include main_test.c libftprintf.a -o main_test
./main_test
```

> Nota: no hay parte bonus. No existen ficheros `src/ft_*bonus.c` ni regla `make bonus`;
> las flags `-0.# +` y el ancho de campo no están implementadas.

## Recursos

- *man 3 printf* — especificación de las conversiones soportadas.
- [Beej's Guide to C](http://www.beej.us/guide/) — variádicas, punteros, memoria.
- [linux man pages: va_list](https://man7.org/linux/man-pages/man3/va_list.3.html).
- 42 Norme (student's handbook, C).
- `man 3 write`, `man 3 malloc`, `man 3 free`.

### Uso de la IA (IA usage)

AI was used as a *development assistant*: to propose an initial structure, to understand
the variadic mechanism (`va_apis`), and to review C snippets and debug compiler warnings.
Every line of the final code was understood and re-implemented by me. I can fully explain
the algorithm, the role of each file, the `malloc`/`free` discipline, and why the return
value of `ft_printf` matches `printf` exactly (it is a count of written bytes, not a
count of `write` calls).

### Del algoritmo y estructura de datos (algorithm justification)

**Parser de la cadena de formato.** `ft_printf` recorre `str` una vez, de izquierda a
derecha. En cada iteración distingue dos casos: o el carácter es literal (se escribe a
`stdout` con un `write` de 1 byte) o es `%` (se pasa el siguiente carácter a `ft_cases`).
Esta separación *literal vs conversión* con un solo bucle hace la función simple, fácil de
testear y extensible: añadir una conversión nueva significa añadir un `else if` en
`ft_cases`, sin tocar nada más.

**Despacho `ft_cases` (una función por tipo de conversión).** Cada conversión tiene su
propia función (`ft_printstr`, `ft_printnbr`, `ft_printunbr`, `ft_printhex`,
`ft_printptr`) que recibe **ya** el valor apropiado de su tipo (gracias a `va_arg` con el
tipo correspondiente) y devuelve la cantidad de caracteres escritos. Esto es la clave de
la extensibilidad: el dispatcher no conoce el resto de funciones, y cada conversión está
aislada en su fichero. Si un día hay que modificar el manejo de `x`/`X` no se toca el
parser, ni `s`, ni `p`, etc.

**Estructura de datos.** No se usa ninguna estructura de datos compleja ni ningún buffer
interno (el enunciado prohíbe explícitamente la gestión interna del buffer de `printf`).
Los datos pasan siempre por parámetros y retorno: los argumentos salen de `va_list`, la
string que se imprime (si existe) se *construye* con `malloc` para las conversiones que lo
necesitan (`%u`, `%d`), se imprime y se `free`a. Este patrón es intencional: no hay estado
oculto, no hay buffers estáticos, y así la función es reentrante y thread-safe para un
fd concreto.

**`%d`/`%i` y `%u`.** Estos dos casos son los que requieren `malloc`. `ft_unumlen`
calcula la longitud en base 10 sin convertir el número, y
`ft_uitoa` lo convierte a string (invertida al final). Al conocer la longitud exacta, la
`malloc` tiene el tamaño justo, sin desborde ni memoria desperdiciada, y el retorno de
`ft_printf` (que es la suma de todos los `write`s y de las longitudes devueltas por cada
conversión) coincide con el número de caracteres escritos, igual que en `printf`.

**`%x`/`%X` y `%p`.** Se implementan recursivamente (`ft_puthex`, `ft_putptr`): dividir
por 16 y recursar hasta llegar a un dígito es natural y legible, y no requiere memoria
dinámica. `%p` añade el prefijo `0x` y, para `(nil)`, devuelve `"(nil)"` como el
`printf` original de glibc.

## Notas técnicas

- La librería se construye como un archivo estático (`ar rcs`). Los objetos intermedios
  se eliminan con `make fclean`, de ahí `re` para rearmar todo desde cero.
- El Makefile compila `libft/` primero (con su propio Makefile) y después las fuentes de
  `src/` con `-I./include`. `libftprintf.a` se construye en el directorio raíz del
  proyecto.
- `test_printf.c` es un programa de prueba mínimo (no se entrega) que cubre las 8
  conversiones y los NULLs, y verifica que el retorno coincide con el de `printf`.
