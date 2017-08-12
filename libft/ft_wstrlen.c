/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:43:18 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 12:45:12 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wchar_t *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		if (*str <= 0x7f)
			len += 1;
		else if (*str <= 0x7ff)
			len += 2;
		else if (*str <= 0xffff)
			len += 3;
		else if (*str <= 0x10ffff)
			len += 4;
		str += 1;
	}
	return (len);
}
