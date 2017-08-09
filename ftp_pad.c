/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:56:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 10:36:57 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int	ftp_print_special(t_argfmt arg)
{
	if (arg.arg.num_val == 0 || !arg.flags.special)
		return (0);
	write(1, "0", 1);
	if (ft_toupper(arg.specifier) == 'O')
		return (1);
	else if (ft_toupper(arg.specifier) == 'X')
	{
		write(1, arg.specifier == 'x' ? "x" : "X", 1);
		return (2);
	}
	return (0);
}


int			ftp_lpad(t_argfmt arg, int arg_len)
{
	size_t	chars_written;
	int		padding;

	if (arg.width == 0 || arg.flags.left_justify)
		return (0);
	chars_written = 0;
	padding = arg.width - (arg_len > arg.precision ? arg_len : arg.precision);
	if (is_numeric_specifier(arg.specifier))
	{
		if (arg.flags.special && arg.arg.num_val > 0)
		{
			padding -= (ft_toupper(arg.specifier) == 'X' || ft_toupper(arg.specifier) == 'O');
			padding -= (ft_toupper(arg.specifier) == 'X');
		}
		padding -= (arg.flags.show_sign == 1);
	}
	while (padding-- > 0)
		write((++chars_written != 0), arg.flags.pad_with_zeros ? "0" : " ", 1);
	return (chars_written);
}

int			ftp_lpad(t_argfmt arg, int arg_len)
{
	int		padding;
	size_t	chars_written;

	chars_written = 0;
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


int			ftp_rpad(t_argfmt arg, int arg_len)
{
	int		padding;
	int		chars_written;

	chars_written = 0;
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
*/
