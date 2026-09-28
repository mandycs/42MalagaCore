#include <stdio.h>
#include "include/ft_printf.h"

int	main(void)
{
	char			*str;
	int				a;
	unsigned int	u;
	int				r1;
	int				r2;

	str = "hola mundo";
	a = 42;
	u = 4294967295;
	ft_printf("c: %c s: %s\n", 'x', str);
	ft_printf("i: %i d: %d\n", 42, -42);
	ft_printf("u: %u\n", u);
	ft_printf("x: %x\n", 255);
	ft_printf("X: %X\n", 255);
	ft_printf("d neg: %d\n", -12345);
	ft_printf("u full: %u\n", 4294967295);
	ft_printf("p null: %p\n", NULL);
	ft_printf("s null: %s\n", NULL);
	ft_printf("pct: %%\n");
	ft_printf("d: %d u: %u x: %x c:%c s:%s\n", a, 10, 222, 'z', "xyz");
	r1 = ft_printf("abc");
	printf("ret = %d\n", r1);
	r2 = ft_printf("%s%d", "hola", 7);
	printf("ret = %d\n", r2);
	return (0);
}
