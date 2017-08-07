/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:06:16 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/06 23:21:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnum(long long n, int base, char letter_case, long width)
{
	int		i;
	int		chars_printed;
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
	chars_printed = 0;
	while (chars_printed < i && (chars_printed < width || width <= 0))
		ft_putchar(buf[i - (++chars_printed)]);
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
	if (arg.flags.special)
	{
		write(1, (arg.specifier == 'x' ? "0x" : "0X"), 2);
		ret = 2;
	}
	arg.arg.num_val = val;
	return ((int)ft_numlen(val, 16) + ft_padnbr(arg, ret) + ret);
}

int		print_digit_arg(t_argfmt arg, char *prefix)
{
	size_t	ret;
	size_t	val;
	int		base;

	ret = 0;
	base = get_base(arg.specifier);
	if (arg.length_specified)
		val = convert_value(arg.arg.num_val, arg.length, 1);
	else
		val = (int)arg.arg.num_val;
	if (prefix != (void *)0)
		write(1, prefix, (ret = ft_strlen(prefix)));
	//if ((offset = arg.precision - ft_numlen(val, 10)) > 0)
		//while (offset--)
			//write((++ret != 0), "0" , 1);
	arg.arg.num_val = val;
	return ((int)ft_numlen(val, base) + ft_padnbr(arg, ret) + ret);
}

int		ftp_printnum(t_argfmt arg)
{
	size_t	ret;

	ret = 0;
	if (arg.specifier == 'd' || arg.specifier == 'i')
		return (print_digit_arg(arg, (void *)0));
	else if (arg.specifier == 'x')
		return (print_digit_arg(arg, arg.flags.special ? "0x" : (void *)0));
	else if (arg.specifier == 'X')
		return (print_digit_arg(arg, arg.flags.special ? "0X" : (void *)0));
	else if (arg.specifier == 'o')
	{
		if (arg.flags.special)
		{
			write(1, "0", 1);
			ret = 1;
		}
		ft_putnum(arg.arg.num_val, 8, 'a', 0);
		return ((int)ft_numlen(arg.arg.num_val, 8) + ret);
	}
	else if (arg.specifier == 'O')
	{
		if (arg.flags.special)
		{
			write(1, "0", 1);
			ret = 1;
		}
		ft_putnum(arg.arg.num_val, 8, 'A', 0);
		return ((int)ft_numlen(arg.arg.num_val, 8) + ret);
	}
	return (ret);
}
