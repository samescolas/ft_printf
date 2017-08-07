/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:31:06 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 12:09:24 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '+' || c == '-'
			|| c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int		is_length_specifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		is_signed_specifier(char c)
{
	if (ft_toupper(c) != 'X' && ft_toupper(c) != 'U' &&
			ft_toupper(c) != 'O')
		return (1);
	return (0);
}

int		is_specifier(char c)
{
	if (is_numeric_specifier(c) || c == 's' || c == 'S' || c == 'p')
		return (1);
	return (0);
}

int		is_numeric_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x'
					|| c == 'X' || c == 'O')
		return (1);
	return (0);
}

