/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:30:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 16:11:36 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		convert_num(ssize_t n, short base, char base_case)
{
	if (n % base < 10)
		return ((n % base) + '0');
	else
		return ((n % base) - 10 + base_case);
}

char		*ft_itoa_base(ssize_t n, short base, char base_case)
{
	char	*bkwds_num;
	char	*head;
	int		sign;

	bkwds_num = ft_strnew(ft_numlen(n, base));
	if (!bkwds_num)
		return (NULL);
	head = &bkwds_num[0];
	sign = (n < 0 ? -1 : 1);
	n *= sign;
	*bkwds_num++ = convert_num(n, base, base_case);
	while (n /= base)
		*bkwds_num++ = convert_num(n, base, base_case);
	if (sign < 0)
		*bkwds_num++ = '-';
	*bkwds_num = '\0';
	return (ft_strrev(head));
}
