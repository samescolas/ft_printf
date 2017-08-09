/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:30:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 09:34:16 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(ssize_t n, short base, char base_case)
{
	char	*bkwds_num;
	char	*head;

	bkwds_num = ft_strnew(ft_numlen(n, base));
	if (!bkwds_num)
		return (NULL);
	head = &bkwds_num[0];
	if (n < 0)
		n *= -1;
	while (n >= base)
	{
		if (n % base < 10)
			*bkwds_num++ = (n % base) + '0';
		else
			*bkwds_num++ = (n % base) - 10 + base_case;
		n /= base;
	}
	if (n < 10)
		*bkwds_num++ = n + '0';
	else
		*bkwds_num++ = n - 10 + base_case;
	*bkwds_num = '\0';
	return (ft_strrev(head));
}
