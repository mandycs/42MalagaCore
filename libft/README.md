*Este proyecto ha sido creado como parte del currículo de 42 por mancorte.*

# Libft

## Descripción

**Libft** es una librería estática en C (`libft.a`) que reimplementa desde cero un
conjunto de funciones de propósito general: parte de ellas son funciones estándar
de la `libc`, y el resto son utilidades adicionales de manejo de cadenas, memoria,
salida por descriptor de fichero y listas enlazadas.

El objetivo del proyecto es entender cómo funcionan por dentro las funciones que
normalmente se dan por sentadas, escribirlas manualmente respetando sus prototipos
y su comportamiento documentado en el `man`, y construir una base propia reutilizable
en el resto de proyectos del cursus (`ft_printf`, `get_next_line`, `push_swap`,
`so_long`, `pipex`, `philosophers`...).

Todas las funciones llevan el prefijo `ft_`, no dependen de funciones externas más
allá de `malloc`, `free` y `write`, y el código cumple la **Norma** de 42.

## Instrucciones

### Compilación

```sh
make          # genera libft.a
make clean    # elimina los ficheros objeto (.o)
make fclean   # elimina los .o y libft.a
make re       # fclean + all
```

Se compila con `cc` y las flags `-Wall -Wextra -Werror`, y el archivo se genera
con `ar rcs`. El `Makefile` no hace relink.

### Uso

Incluye la cabecera y enlaza contra la librería:

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hola, libft!", 1);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -I. -o programa
```

## Contenido de la librería

### Parte 1 — Funciones de la libc

| Función | Prototipo | Descripción |
| --- | --- | --- |
| `ft_isalpha` | `int ft_isalpha(int c)` | 1 si `c` es una letra, 0 si no. |
| `ft_isdigit` | `int ft_isdigit(int c)` | 1 si `c` es un dígito decimal, 0 si no. |
| `ft_isalnum` | `int ft_isalnum(int c)` | 1 si `c` es letra o dígito, 0 si no. |
| `ft_isascii` | `int ft_isascii(int c)` | 1 si `c` pertenece a la tabla ASCII (0–127). |
| `ft_isprint` | `int ft_isprint(int c)` | 1 si `c` es un carácter imprimible (32–126). |
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Longitud de la cadena sin contar el `\0`. |
| `ft_memset` | `void *ft_memset(void *b, int c, size_t len)` | Rellena `len` bytes de `b` con `c`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Pone a cero `n` bytes de `s`. |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copia `n` bytes sin solapamiento. |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len)` | Copia `len` bytes de forma segura aunque haya solapamiento. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Copia con truncado seguro; devuelve la longitud de `src`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | Concatena con truncado seguro; devuelve la longitud que habría tenido el resultado. |
| `ft_toupper` | `int ft_toupper(int c)` | Convierte a mayúscula. |
| `ft_tolower` | `int ft_tolower(int c)` | Convierte a minúscula. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Primera aparición de `c` en `s`. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Última aparición de `c` en `s`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compara hasta `n` bytes de dos cadenas. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Busca `c` en los primeros `n` bytes. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compara `n` bytes de dos zonas de memoria. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Busca la subcadena `little` dentro de los primeros `len` bytes de `big`. |
| `ft_atoi` | `int ft_atoi(const char *str)` | Convierte el prefijo numérico de una cadena en `int`. |
| `ft_calloc` | `void *ft_calloc(size_t count, size_t size)` | Reserva e inicializa a cero. Con `count` o `size` a 0 devuelve un puntero único liberable. |
| `ft_strdup` | `char *ft_strdup(const char *s1)` | Duplica una cadena reservando memoria. |

### Parte 2 — Funciones adicionales

| Función | Prototipo | Descripción |
| --- | --- | --- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Subcadena de `s` desde `start` con longitud máxima `len`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Nueva cadena resultado de concatenar `s1` y `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Copia de `s1` sin los caracteres de `set` al principio y al final. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Divide `s` por el delimitador `c` en un array terminado en `NULL`. |
| `ft_itoa` | `char *ft_itoa(int n)` | Representación en cadena de un entero, incluidos los negativos. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Nueva cadena aplicando `f(índice, carácter)` a cada carácter. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Aplica `f(índice, &carácter)` sobre `s`, modificándola in situ. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Escribe un carácter en el descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Escribe una cadena en el descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Escribe una cadena seguida de un salto de línea. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Escribe un entero en el descriptor `fd`. |

### Parte 3 — Listas enlazadas

La estructura de nodo definida en `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```

| Función | Prototipo | Descripción |
| --- | --- | --- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Crea un nodo con `content` y `next` a `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Añade un nodo al principio de la lista. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst)` | Número de nodos de la lista. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Último nodo de la lista. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Añade un nodo al final de la lista. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Libera el contenido con `del` y el nodo, sin tocar el siguiente. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Libera el nodo dado y todos los siguientes, dejando el puntero a `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Aplica `f` al contenido de cada nodo. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Crea una lista nueva aplicando `f` al contenido de cada nodo; usa `del` si hay que liberar en caso de error. |

## Decisiones técnicas

- Las funciones auxiliares internas (`ft_numlen` e `ft_invert` en `ft_itoa.c`,
  `ft_count_words` y `ft_fill_array` en `ft_split.c`) se declaran `static` para
  limitar su alcance al fichero y no contaminar el espacio de símbolos de la
  librería, tal y como exige el enunciado.
- `ft_atoi` acumula el resultado en un `long` y aplica el signo al final, en lugar
  de ir negando sobre un `int`.
- `ft_itoa` guarda el valor en un `long` antes de cambiarle el signo, de modo que
  `-2147483648` no desborda; después calcula la longitud necesaria, escribe los
  dígitos en orden inverso y da la vuelta a la cadena.
- `ft_lstmap` comprueba el resultado de cada `ft_lstnew` y libera la lista
  parcialmente construida con `ft_lstclear` si falla una reserva.
- El `Makefile` usa una regla de patrón `%.o: %.c libft.h`, de modo que solo se
  recompilan los ficheros modificados y no se produce relink.

## Recursos

- Páginas del manual (`man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`,
  `man 3 calloc`...) como referencia principal de prototipos y comportamiento.
- *The C Programming Language*, Kernighan & Ritchie.
- [cppreference — C standard library](https://en.cppreference.com/w/c/header)
- Código fuente de la libc de BSD y de glibc, para comparar implementaciones y
  entender por qué `strlcpy`, `strlcat` y `bzero` no están en glibc por defecto.
- La Norma de 42 (`norminette`) y `valgrind` para verificar estilo y ausencia de
  leaks de memoria.

### Uso de IA

- La implementación de todas las funciones de la librería se escribió a mano, sin
  asistencia de IA.
- Se utilizó un asistente de IA (Claude) en una única tarea puntual: **revisar el
  código ya escrito contra la versión 19.3 del enunciado** para localizar
  desviaciones (prototipo de `ft_lstsize`, paso de las funciones de listas de
  bonus a parte obligatoria, funciones auxiliares sin `static`, uso de `cc` en el
  `Makefile`) y aplicar esas correcciones, además de redactar este `README.md`.
- No se ha usado IA para resolver la lógica de ninguna función ni para generar
  algoritmos.
