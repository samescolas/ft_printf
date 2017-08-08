/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:23:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 17:00:48 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	convert_value(intmax_t n, t_length len, char specifier)
{
	t_bool	is_unsigned;

	is_unsigned = !is_signed_specifier(specifier);
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

intmax_t	convert_fmt(t_argfmt arg)
{
	if (arg.length_specified)
		return (convert_value(arg.arg.num_val, arg.length, arg.specifier));
	else if (is_signed_specifier(arg.specifier) || arg.specifier == 'C')
		return ((int)arg.arg.num_val);
	else if (arg.specifier == 'c')
		return ((char)arg.arg.num_val);
	else
		return ((unsigned int)arg.arg.num_val);
}
