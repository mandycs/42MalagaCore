/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com>          +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:40:00 by jucortes         #+#    #+#              */
/*   Updated: 2026/09/28 17:45:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

static void	test_basic1(void)
{
	char	*s;

	s = "hola mundo";
	ft_printf("c: %c s: %s\n", 'x', s);
	ft_printf("i: %i d: %d\n", 42, -42);
	ft_printf("d max: %d min: %d\n", INT_MAX, INT_MIN);
	ft_printf("u full: %u zero: %u\n", 4294967295u, 0u);
	ft_printf("p null: %p val: %p\n", (void *)0, (void *)0xdeadbeef);
	ft_printf("s null: %s empty: <%s>\n", (char *)0, "");
}

static void	test_basic2(void)
{
	ft_printf("x: %x X: %X\n", 255, 65535);
	ft_printf("x full: %x zero: %x\n", 4294967295u, 0);
	ft_printf("pct: %% end\n");
	ft_printf("mix: d %d u %u x %x c %c s %s p %p %%\n",
		-12345, 999u, 222, 'z', "xyz", (void *)1);
}

static void	test_ret1(void)
{
	int	r;

	r = ft_printf("abc");
	printf("ret=%d (exp 3)\n", r);
	r = ft_printf("%d", 0);
	printf("ret=%d (exp 1)\n", r);
	r = ft_printf("%d", INT_MIN);
	printf("ret=%d (exp 11)\n", r);
	r = ft_printf("%d", INT_MAX);
	printf("ret=%d (exp 10)\n", r);
	r = ft_printf("%u", 4294967295u);
	printf("ret=%d (exp 10)\n", r);
}

static void	test_ret2(void)
{
	int	r;

	r = ft_printf("%x", 255);
	printf("ret=%d (exp 2)\n", r);
	r = ft_printf("%X", 65535);
	printf("ret=%d (exp 4)\n", r);
	r = ft_printf("%p", (void *)0);
	printf("ret=%d (exp 5)\n", r);
	r = ft_printf("%s", (char *)0);
	printf("ret=%d (exp 6)\n", r);
	r = ft_printf("%s", "hola");
	printf("ret=%d (exp 4)\n", r);
	r = ft_printf("%c", 'A');
	printf("ret=%d (exp 1)\n", r);
	r = ft_printf("empty %c tail", 'A');
	printf("ret=%d (exp 12)\n", r);
}

int	main(void)
{
	test_basic1();
	test_basic2();
	printf("== return values ==\n");
	test_ret1();
	test_ret2();
	printf("done\n");
	return (0);
}
