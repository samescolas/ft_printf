/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:23:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 12:39:48 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	convert_value(size_t n, t_length len, char specifier)
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
