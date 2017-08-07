/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:09:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 11:10:57 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_specifier(char *fmt)
{
	char	*ptr;

	ptr = fmt;
	while (*ptr && !is_specifier(*ptr))
		++ptr;
	return (*ptr);
}

int		get_base(char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		return (10);
	else if (specifier == 'x' || specifier == 'X')
		return (16);
	else if (specifier == 'o' || specifier == 'O')
		return (8);
	else
		return (0);
}
