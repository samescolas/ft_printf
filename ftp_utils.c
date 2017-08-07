/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:09:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 14:04:18 by sescolas         ###   ########.fr       */
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
	specifier = ft_toupper(specifier);
	if (specifier == 'D' || specifier == 'I' || specifier == 'U')
		return (10);
	else if (specifier == 'X')
		return (16);
	else if (specifier == 'O')
		return (8);
	else
		return (1);
}
