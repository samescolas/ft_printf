/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:30:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 12:32:41 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	convert_num(uintmax_t n, short base, char base_case)
{
	if (n % base < 10)
		return ((n % base) + '0');
	else
		return ((n % base) - 10 + base_case);
}

char		*ft_itoa_base_u(uintmax_t n, short base, char base_case)
{
	char	*bkwds_num;
	char	*head;

	bkwds_num = ft_strnew(ft_numlen_u(n, base));
	if (!bkwds_num)
		return (NULL);
	head = &bkwds_num[0];
	*bkwds_num++ = convert_num(n, base, base_case);
	while (n /= base)
		*bkwds_num++ = convert_num(n, base, base_case);
	*bkwds_num = '\0';
	return (ft_strrev(head));
}
