/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:26:54 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 10:24:26 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *ptr;

	if (!src || !dst)
		return ((void *)0);
	ptr = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (ptr);
}
