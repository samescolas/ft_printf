/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 11:55:58 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 14:02:28 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(long long n, size_t base, char b)
{
	char	buf[32];
	short	i;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	if (n % base < 10)
		buf[i++] = (n % base) + '0';
	else
		buf[i++] = (n % base) - 10 + b;
	while (n /= base)
	{
		if (n % base < 10)
			buf[i++] = (n % base) + '0';
		else
			buf[i++] = (n % base) - 10 + b;
	}
	while (i >= 0)
		write(1, &buf[--i], 1);
}

size_t	ft_padnbr(t_argfmt arg, int written)
{
	long	offset;
	size_t	ret;

	ret = 0;
	if (arg.width != 0)
		offset = ft_numlen(arg.arg.num_val, get_base(arg.specifier)) - arg.width + written;
	else 
		offset = 0;
	if (offset > 0)
		offset = 0;
	if (offset && arg.flags.left_justify)
		offset *= -1;
	while (offset++ < 0)
		write((++ret != 0), (arg.flags.pad_with_zeros ? "0" : " "), 1);
	--offset;
	ft_putnbr_base(arg.arg.num_val, get_base(arg.specifier),
		(arg.specifier == 'X' || arg.specifier == 'O' ? 'A' : 'a'));

	while (offset-- > 0)
		//write((++ret != 0), (arg.flags.pad_with_zeros ? "0" : " "), 1);
		write((++ret != 0), " ", 1);
	return (ret);
}
