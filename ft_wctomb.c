/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 11:18:35 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 11:32:12 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wctomb(wchar_t wc, char **buf)
{
	ft_bzero(*buf, 4 * sizeof(char));
	if (wc <= 0x7f)
	{
		(*buf)[0] = (char)wc;
		return (1);
	}
	else if (wc <= 0x7ff)
	{
		(*buf)[0] = (wc >> 6) + 0xc0;
		(*buf)[1] = (wc & 0x3f) + 0x80;
		return (2);
	}
	else if (wc <= 0xffff)
	{
		(*buf)[0] = (wc >> 12) + 0xe0;
		(*buf)[1] = ((wc >> 6) & 0x3f) + 0x80;
		(*buf)[2] = (wc & 0x3f) + 0x80;
		return (3);
	}
	else if (wc <= 0x10ffff)
	{
		(*buf)[0] = (wc >> 18) + 0xf0;
		(*buf)[1] = ((wc >> 12) & 0x3f) + 0x80;
		(*buf)[2] = ((wc >> 6) & 0x3f) + 0x80;
		(*buf)[3] = (wc & 0x3f) + 0x80;
		return (4);
	}
	return (0);
}
