/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:06:16 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/06 17:07:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnum(long long n, int base, char letter_case)
{
	int		i;
	char	buf[32];

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	if (n % base < 10)
		buf[i++] = ((n % base) + '0');
	else
		buf[i++] = (n % base) - 10 + letter_case;
	while (n /= base)
	{
		if (n % base < 10)
			buf[i++] = ((n % base) + '0');
		else
			buf[i++] = (n % base) - 10 + letter_case;
	}
	while (i)
		ft_putchar(buf[--i]);
}

size_t	convert_value(size_t n, t_length len, t_bool is_unsigned)
{
	if (len == HH)
		return ((is_unsigned ? (unsigned char)n : (char)n));
	else if (len == H)
		return ((is_unsigned ? (unsigned short)n : (short)n));
	else if (len == L)
		return ((is_unsigned ? (unsigned long)n : (long)n));
	else if (len == LL)
		return ((is_unsigned ? (unsigned long long)n : (long long)n));
	else if (len == J)
		return ((is_unsigned ? (uintmax_t)n : (intmax_t)n));
	else if (len == Z)
		return ((size_t)n);
	return (0);
}

int		print_hex_arg(t_argfmt arg)
{
	size_t	ret;
	size_t	val;

	ret = 0;
	if (arg.length_specified)
		val = convert_value(arg.arg.num_val, arg.length, 1);
	else
		val = (unsigned int)arg.arg.num_val;
	if (arg.specifier == 'x')
	{
		if (arg.flag == '#')
		{
			write(1, "0x", 2);
			ret = 2;
		}
		//ft_putnum((unsigned int)arg.arg.num_val, 16, 'a');
		ft_putnum(val, 16, 'a');
		return ((int)ft_numlen(val, 16) + ret);
		//return ((int)ft_numlen((unsigned int)arg.arg.num_val, 16));
	}
	else
	{
		if (arg.flag == '#')
		{
			write(1, "0X", 2);
			ret = 2;
		}
		//ft_putnum((unsigned int)arg.arg.num_val, 16, 'A');
		ft_putnum(val, 16, 'A');
		return ((int)ft_numlen(val, 16) + ret);
		//return (ft_numlen((unsigned int)arg.arg.num_val, 16));
	}
}

int		ftp_printnum(t_argfmt arg)
{
	size_t	ret;

	ret = 0;
	if (arg.specifier == 'd' || arg.specifier == 'i')
	{
		ft_putnum((int)arg.arg.num_val, 10, 0);
		return ((int)ft_numlen((int)arg.arg.num_val, 10));
	}
	else if (arg.specifier == 'x' || arg.specifier == 'X')
		return (print_hex_arg(arg));
	else if (arg.specifier == 'o')
	{
		if (arg.flag == '#')
		{
			write(1, "0", 1);
			ret = 1;
		}
		ft_putnum(arg.arg.num_val, 8, 'a');
		return ((int)ft_numlen(arg.arg.num_val, 8) + ret);
	}
	else if (arg.specifier == 'O')
	{
		if (arg.flag == '#')
		{
			write(1, "0", 1);
			ret = 1;
		}
		ft_putnum(arg.arg.num_val, 8, 'A');
		return ((int)ft_numlen(arg.arg.num_val, 8) + ret);
	}
	return (ret);
}
