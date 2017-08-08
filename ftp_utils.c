/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:09:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 17:07:05 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_arglen(t_argfmt arg)
{
	int		ret;

	if (ft_toupper(arg.specifier) == 'C')
		return (1);
	else if (is_numeric_specifier(arg.specifier))
		ret = ft_numlen(arg.arg.num_val, get_base(arg.specifier));
	else if (arg.specifier == 'S')
		return (0); /* need a strlen for wchar_t or something...? */
	else
		return (ft_strlen(arg.arg.str_val));
	if (arg.flags.special && (
		ft_toupper(arg.specifier) == 'O' || ft_toupper(arg.specifier) == 'X'))
		ret += 1 + (ft_toupper(arg.specifier) == 'X');
	return (ret);
}

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
