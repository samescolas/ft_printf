/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:31:11 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 12:13:53 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_min_value(void)
{
	char	*tmp;

	tmp = ft_strdup("9223372036854775808");
	ft_putstr(tmp);
	ft_strdel(&tmp);
}

void		ft_putnbr(intmax_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == INTMAX_MIN)
		{
			print_min_value();
			return ;
		}
		else
			n *= -1;
	}
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}
