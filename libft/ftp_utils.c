/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 16:31:06 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 16:31:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '.' || c == '+' || c == '-'
			|| c == ' ' || c == '0')
		return (1);
	return (0);
}

int		is_length_specifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'L')
		return (1);
	return (0);
}

int		is_numeric_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x'
			|| c == 'X')
		return (1);
	return (0);
}
