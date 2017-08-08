/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:06:16 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 17:24:33 by sescolas         ###   ########.fr       */
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

int		ftp_print_special(t_argfmt arg)
{
	if (arg.flags.special && ft_toupper(arg.specifier) == 'O')
	{
		write(1, "0", 1);
		return (1);
	}
	else if (arg.flags.special && ft_toupper(arg.specifier) == 'X')
	{
		if (arg.specifier == 'x' && arg.arg.num_val != 0)
			write(1, "0x", 2);
		else if (arg.arg.num_val != 0)
			write(1, "0X", 2);
		return (2);
	}
	return (0);
}

int		ftp_lpad(t_argfmt arg)
{
	int		padding;
	int		arg_len;
	size_t	chars_written;

	chars_written = 0;
	arg_len = get_arglen(arg);
	if ((padding = (arg.precision > arg_len ? arg.precision - arg_len : 0))
								&& arg.flags.show_sign && arg.arg.num_val >= 0)
			write((++chars_written != 0), "+", 1);
	while (padding--)
		write((++chars_written != 0), "0", 1);
	if (arg.precision > arg_len)
		padding = arg.width - arg.precision - arg_len;
	else if (arg.width > arg.precision && arg.width > arg_len)
		padding = arg.width - arg_len;
	else
		padding = 0;
	if (arg.flags.pad_with_zeros)
	{
		if (arg.precision < arg_len && arg.flags.show_sign && arg.arg.num_val >= 0)
			write((++chars_written != 0), "+", 1);
		chars_written += ftp_print_special(arg);
	}
	if (!arg.flags.left_justify && arg.arg.num_val > 0)
		while (padding-- > 0)
			write((++chars_written != 0),
								arg.flags.pad_with_zeros ? "0" : " ", 1);
	if (!arg.flags.pad_with_zeros)
	{
		if (arg.precision < arg_len && arg.flags.show_sign && arg.arg.num_val >= 0)
			write((++chars_written != 0), "+", 1);
		chars_written += ftp_print_special(arg);
	}
	return (chars_written);
}

int		ftp_rpad(t_argfmt arg)
{
	int		padding;
	int		arg_len;
	int		chars_written;

	chars_written = 0;
	arg_len = get_arglen(arg);
	if (arg.precision > arg_len)
		padding = arg.width - arg.precision - arg_len;
	else if (arg.width > arg.precision && arg.width > arg_len)
		padding = arg.width - arg_len;
	else
		padding = 0;
	if (arg.flags.left_justify)
		while (padding-- > 0)
			write((++chars_written != 0), " ", 1);
	return (chars_written);
}

int		ftp_printnum(t_argfmt arg)
{
	int		ret;

	if (arg.length_specified)
		arg.arg.num_val = convert_fmt(arg);
	else if (is_signed_specifier(arg.specifier))
		arg.arg.num_val = (int)arg.arg.num_val;
	else if (arg.specifier == 'c')
		arg.arg.num_val = (char)arg.arg.num_val;
	else
		arg.arg.num_val = (unsigned int)arg.arg.num_val;
	ret = ftp_lpad(arg);
	//if (arg.flags.show_sign && arg.arg.num_val >= 0)
		//write((++ret != 0), "+", 1);
	if (arg.flags.space && arg.arg.num_val > 0)
		write((++ret != 0), " ", 1);
	if (ft_toupper(arg.specifier) == 'C' && arg.arg.num_val > 0)
		write(1, &arg.arg.num_val, 1);
	else if (ft_toupper(arg.specifier) != 'C')
		ft_putnum(arg.arg.num_val,
					get_base(arg.specifier), arg.specifier < 97 ? 'A' : 'a');
	ret += ft_numlen(arg.arg.num_val, get_base(arg.specifier));
	ret += ftp_rpad(arg);
	return (ret);
}
