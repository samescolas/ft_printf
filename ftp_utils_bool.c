/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:31:06 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 15:59:44 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	return(c == '+' || c == '-' || c == ' ' || c == '0' || c == '#');
}

int		is_length_specifier(char c)
{
	return (c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z');
}

int		is_signed_specifier(char c)
{
	return (ft_toupper(c) != 'X' && ft_toupper(c) != 'U'
												&& ft_toupper(c) != 'O');
}

int		is_specifier(char c)
{
	return (is_numeric_specifier(c) || c == 's' || c == 'S' || c == 'p');
}

int		is_numeric_specifier(char c)
{
	return (ft_toupper(c) == 'C' || ft_toupper(c) == 'D' || ft_toupper(c) == 'U'
				|| c == 'i' || ft_toupper(c) == 'O' || ft_toupper(c) == 'X');
}

