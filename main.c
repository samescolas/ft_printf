/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 11:23:25 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 10:47:58 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	ft_putstr("----------------------\n");
	ft_putstr("----------------------\n");
	ft_putstr("\tPRINTF\n");
	ft_putstr("----------------------\n");
	ft_putstr("----------------------\n");
	printf("%%10x: %10x\n", 255);
	printf("%%-15x: %-15x\n", 255);
	printf("%%s: %s\n", "test string");
	printf("%%p: %p\n", &main);
	printf("%%d: % 4d\n", 42);
	printf("%%d: %.4d\n", 42);
	printf("%%D: %D\n", 42);
	printf("%%jx: %jx\n", 4200000000000);
	printf("%%o: %#o\n", 42);
	printf("%%O: %#O\n", 42);
	printf("%%u: %u\n", 42);
	printf("%%U: %U\n", 42);
	printf("%%x: %#x\n", 42);
	printf("%%X: %X\n", 42);
	printf("%%c: %c\n", 'a');
	printf("%%C: %C\n", 420);
	printf("%%zd%%zd: %zd%zd\n", 42, 0);
	ft_putstr("----------------------\n");
	ft_putstr("----------------------\n");
	ft_putstr("\tFT_PRINTF\n");
	ft_putstr("----------------------\n");
	ft_putstr("----------------------\n");
	ft_printf("%%10x: %10x\n", 255);
	ft_printf("%%-15x: %-15x\n", 255);
	ft_printf("%%s: %s\n", "test string");
	ft_printf("%%p: %p\n", &main);
	ft_printf("%%d: % 4d\n", 42);
	ft_printf("%%d: %.4d\n", 42);
	ft_printf("%%D: %D\n", 42);
	ft_printf("%%jx: %jx\n", 4200000000000);
	ft_printf("%%o: %#o\n", 42);
	ft_printf("%%O: %#O\n", 42);
	ft_printf("%%u: %u\n", 42);
	ft_printf("%%U: %U\n", 42);
	ft_printf("%%x: %#x\n", 42);
	ft_printf("%%X: %X\n", 42);
	ft_printf("%%c: %c\n", 'a');
	ft_printf("%%C: %C\n", 420);
	ft_printf("%%zd%%zd: %zd%zd\n", 42, 0);
}
