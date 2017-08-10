/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 10:01:30 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 13:53:27 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_double_spec(char **fmt, t_length *len)
{
	if (is_length_specifier(*(*fmt + 1)))
	{
		if (**fmt == *(*fmt + 1) && **fmt == 'l')
			*len = LL;
		else if (**fmt == *(*fmt + 1) && **fmt == 'h')
			*len = HH;
		else
			ft_fatal("invalid conversion specifier\n");
		*fmt += 2;
		return (1);
	}
	return (0);
}

void		get_length(char **fmt, t_length *len)
{
	if (is_length_specifier(**fmt))
	{
		if (!check_double_spec(fmt, len))
		{
			if (**fmt == 'l')
				*len = L;
			else if (**fmt == 'h')
				*len = H;
			else if (**fmt == 'j')
				*len = J;
			else if (**fmt == 'z')
				*len = Z;
			else
				*len = X;
			if (*len != X)
				*fmt += 1;
		}
	}
	else
		*len = X;
}
