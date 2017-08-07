/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:06:16 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 14:36:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnum(long long n, int base, char letter_case)
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
	while (--i >= 0)
		ft_putchar(buf[i]);
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
	int		offset;
	int		base;

	ret = 0;
	base = get_base(arg.specifier);
	if (arg.length_specified)
		arg.arg.num_val = convert_value(arg.arg.num_val, arg.length, arg.specifier);
	else if (is_signed_specifier(arg.specifier))
		arg.arg.num_val = (int)arg.arg.num_val;
	else
		arg.arg.num_val = (unsigned int)arg.arg.num_val;
	if (prefix != (void *)0)
		write(1, prefix, (ret = ft_strlen(prefix)));
	if ((offset = arg.precision - ft_numlen(arg.arg.num_val, 10)) > 0)
		while (offset--)
			write((++ret != 0), "0" , 1);
	return ((int)ft_numlen(arg.arg.num_val, base) + ft_padnbr(arg, ret) + ret);
}

int		ftp_pad(t_argfmt arg)
{
	int		padding;
	int		arg_len;
	size_t	chars_written;

	chars_written = 0;
	if (is_numeric_specifier(arg.specifier))
		arg_len = ft_numlen(arg.arg.num_val, get_base(arg.specifier));
	else
		arg_len = ft_strlen(arg.arg.str_val);
	if (arg.flags.special &&
		(ft_toupper(arg.specifier) == 'O' || ft_toupper(arg.specifier) == 'X'))
		arg_len += 1 + (ft_toupper(arg.specifier) == 'X');
	if (is_numeric_specifier(arg.specifier) && arg.precision > arg_len)
		padding = arg.precision - arg_len;
	else
		padding = 0;
	while (padding--)
		write((++chars_written != 0), "0", 1);
	if ((padding = arg.width - arg.precision) > 0 && !arg.flags.left_justify)
		while (padding--)
			write((++chars_written != 0), arg.flags.pad_with_zeros ? "0" : " ", 1);
	return (chars_written);
}

int		ftp_print_special(t_argfmt arg)
{
	if (ft_toupper(arg.specifier) == 'O')
	{
		write(1, "0", 1);
		return (1);
	}
	else if (ft_toupper(arg.specifier) == 'X')
	{
		if (arg.specifier == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		return (2);
	}
	return (0);
}

int		ftp_printnum(t_argfmt arg)
{
	int		ret;

	if (arg.length_specified)
		arg.arg.num_val = convert_value(arg.arg.num_val, arg.length, arg.specifier);
	else if (is_signed_specifier(arg.specifier))
		arg.arg.num_val = (int)arg.arg.num_val;
	else
		arg.arg.num_val = (unsigned int)arg.arg.num_val;
	ret = ftp_pad(arg);
	if (arg.flags.show_sign)
		write((++ret != 0), arg.arg.num_val >= 0 ? "+" : "-", 1);
	else if (arg.flags.space)
		write((++ret != 0), " ", 1);
	ret += ftp_print_special(arg);
	ft_putnum(arg.arg.num_val, get_base(arg.specifier), arg.specifier < 97 ? 'A' : 'a');
	ret += ft_numlen(arg.arg.num_val, get_base(arg.specifier));
	return (ret);
}
/*
int		ftp_printnum(t_argfmt arg)
{
	size_t	ret;

	ret = 0;
	if (ft_toupper(arg.specifier) == 'D' || ft_toupper(arg.specifier) == 'I' ||
									ft_toupper(arg.specifier) == 'U')
		return (print_digit_arg(arg, (void *)0));
	else if (arg.specifier == 'x')
		return (print_digit_arg(arg, arg.flags.special ? "0x" : (void *)0));
	else if (arg.specifier == 'X')
		return (print_digit_arg(arg, arg.flags.special ? "0X" : (void *)0));
	else if (ft_toupper(arg.specifier) == 'O')
		return (print_digit_arg(arg, arg.flags.special ? "0" : (void *)0));
	return (ret);
}
*/
