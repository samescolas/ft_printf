/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:41:39 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 13:18:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *str)
{
	wchar_t *new_str;

	if (!str)
		return ((void *)0);
	new_str = (wchar_t *)ft_strnew(ft_wstrlen(str));
	if (new_str)
		ft_memcpy(new_str, str, ft_wstrlen(str));
	return (new_str);
}
