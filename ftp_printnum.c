/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:06:16 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 09:45:29 by sescolas         ###   ########.fr       */
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

void	ft_putnum(ssize_t n, int base, char letter_case)
{
	int		i;
	int		chars_printed;
	char	buf[32];

	if (n < 0)
		n *= -1;
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

int		ftp_printnum(t_argfmt arg)
{
	int		ret;

	ret = 0;
	//arg.arg.num_val = convert_fmt(arg);
	if (arg.flags.pad_with_zeros && arg.flags.show_sign)
		write((++ret != 0), arg.arg.num_val > 0 ? "+" : "-", 1);
	ret = ftp_lpad(arg, get_arglen(arg));
	ret += ftp_print_special(arg);
	if (arg.flags.space && arg.arg.num_val > 0)
		write((++ret != 0), " ", 1);
	if (ft_toupper(arg.specifier) == 'C' && arg.arg.num_val > 0)
		write(1, &arg.arg.num_val, 1);
	else if (ft_toupper(arg.specifier) != 'C')
	{
		if (!arg.precision_specified || arg.arg.num_val != 0 || arg.flags.special)
		{
			if (!arg.flags.show_sign && arg.arg.num_val < 0)
				write((++ret != 0), "-", 1);
			ft_putnum(arg.arg.num_val,
					get_base(arg.specifier), arg.specifier < 97 ? 'A' : 'a');
		}
		//else
			//write(1, " ", 1);
	}
	if (ft_toupper(arg.specifier) == 'C')
		ret += 1;
	else
		ret += ft_numlen(arg.arg.num_val, get_base(arg.specifier));
	ret += ftp_rpad(arg, get_arglen(arg));
	return (ret);
}
*/
