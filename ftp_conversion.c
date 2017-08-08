/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:23:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/08 16:04:33 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	convert_value(void *n, t_length len, char specifier)
{
	t_bool	is_unsigned;

	if ((is_unsigned = !is_signed_specifier(specifier)))
		ft_putstr("converting to unsigned...\n");
	else
		ft_putstr("converting to signed...\n");
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
		return ((is_unsigned ? (size_t)n : (ssize_t)n));
	return (0);
}

intmax_t	convert_fmt(t_argfmt arg, void *n)
{
	if (arg.length_specified)
		return (convert_value(n, arg.length, arg.specifier));
	else if (is_signed_specifier(arg.specifier) || arg.specifier == 'C')
		return ((int)n);
	else if (arg.specifier == 'c')
		return ((char)n);
	return ((unsigned int)n);
}
