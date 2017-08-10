/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:09:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 10:33:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_blank(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
	}
	return (1);
}

int		is_nonzero(char *num)
{
	int		i;

	i = -1;
	while (num[++i] != '\0')
	{
		if (num[i] != '0')
			return (1);
	}
	return (0);
}

int		get_base(char specifier)
{
	specifier = ft_toupper(specifier);
	if (specifier == 'C' || specifier == 'D' || specifier == 'I' ||
															specifier == 'U')
		return (10);
	else if (specifier == 'X')
		return (16);
	else if (specifier == 'O')
		return (8);
	else
		return (1);
}
