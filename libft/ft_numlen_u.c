/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:39:45 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 11:40:02 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numlen_u(uintmax_t num, short base)
{
	short	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= base;
		++len;
	}
	return (len);
}
