#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int		r;
	char	*s;

	s = "hola mundo";
	ft_printf("c: %c s: %s\n", 'x', s);
	ft_printf("c nul: %c\n", 0);
	ft_printf("i: %i d: %d\n", 42, -42);
	ft_printf("d max: %d min: %d\n", INT_MAX, INT_MIN);
	ft_printf("u: %u full: %u zero: %u\n", 42, 4294967295u, 0u);
	ft_printf("x: %x X: %X\n", 255, 65535);
	ft_printf("x full: %x zero: %x\n", 4294967295u, 0);
	ft_printf("p null: %p val: %p\n", (void*)0, (void*)0xdeadbeef);
	ft_printf("s null: %s\n", (char*)0);
	ft_printf("s empty: <%s>\n", "");
	ft_printf("pct: %% end\n");
	ft_printf("mix: d %d u %u x %x c %c s %s p %p %%\n",
		-12345, 999u, 222, 'z', "xyz", (void*)1);
	r = ft_printf("abc");
	printf("ret=%d (exp 3)\n", r);
	fflush(stdout);
	r = ft_printf("pct %% now");
	printf("ret=%d (exp 9)\n", r);
	fflush(stdout);
	r = ft_printf("%d", 0);
	printf("ret=%d (exp 1)\n", r);
	fflush(stdout);
	r = ft_printf("%d", 123456789);
	printf("ret=%d (exp 9)\n", r);
	fflush(stdout);
	r = ft_printf("%d", INT_MIN);
	printf("ret=%d (exp 11)\n", r);
	fflush(stdout);
	r = ft_printf("%d", INT_MAX);
	printf("ret=%d (exp 10)\n", r);
	fflush(stdout);
	r = ft_printf("%i", -7);
	printf("ret=%d (exp 2)\n", r);
	fflush(stdout);
	r = ft_printf("%u", 4294967295u);
	printf("ret=%d (exp 10)\n", r);
	fflush(stdout);
	r = ft_printf("%u", 0);
	printf("ret=%d (exp 1)\n", r);
	fflush(stdout);
	r = ft_printf("%x", 255);
	printf("ret=%d (exp 2)\n", r);
	fflush(stdout);
	r = ft_printf("%x", 4294967295u);
	printf("ret=%d (exp 8)\n", r);
	fflush(stdout);
	r = ft_printf("%X", 65535);
	printf("ret=%d (exp 4)\n", r);
	fflush(stdout);
	r = ft_printf("%p", (void*)0);
	printf("ret=%d (exp 5)\n", r);
	fflush(stdout);
	r = ft_printf("%p", (void*)0xdeadbeef);
	printf("ret=%d (exp 10)\n", r);
	fflush(stdout);
	r = ft_printf("%s", (char*)0);
	printf("ret=%d (exp 6)\n", r);
	fflush(stdout);
	r = ft_printf("%s", "");
	printf("ret=%d (exp 0)\n", r);
	fflush(stdout);
	r = ft_printf("%s", "hola");
	printf("ret=%d (exp 4)\n", r);
	fflush(stdout);
	r = ft_printf("%c", 'A');
	printf("ret=%d (exp 1)\n", r);
	fflush(stdout);
	r = ft_printf("nothing");
	printf("ret=%d (exp 7)\n", r);
	fflush(stdout);
	r = ft_printf("empty %c tail", 'A');
	printf("ret=%d (exp 12)\n", r);
	fflush(stdout);
	r = ft_printf("nothing at all");
	printf("ret=%d (exp 14)\n", r);
	fflush(stdout);
	printf("== invalid conversion (ft returns -1) ==\n");
	r = ft_printf("trail %");
	printf("trail %% -> ret=%d\n", r);
	fflush(stdout);
	printf("done\n");
	return (0);
}
