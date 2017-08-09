/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 10:01:30 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 11:04:34 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	get_length(char **fmt, t_length *len)
{
	if (is_length_specifier(**fmt))
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
		}
		else
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

/*
void	get_length(char **fmt, t_length *len)
{
	if (is_length_specifier(*(*fmt)))
	{
		*fmt += 2;
		if (*(*fmt - 1) == 'l' && *(*fmt) == 'l')
			*len = LL;
		else if (*(*fmt - 1) == 'h' && *(*fmt) == 'h')
			*len = HH;
		else
		{
			write(1, (*fmt - 1), 2);
			ft_fatal("invalid length specifier");
		}
	}
	else
	{
		*fmt += 1;
		if (*(*fmt - 1) == 'l')
			*len = L;
		else if (*(*fmt - 1) == 'h')
			*len = H;
		else if (*(*fmt - 1) == 'j')
			*len = J;
		else if (*(*fmt - 1) == 'z')
			*len = Z;
	}
	*len = X;
}
*/
