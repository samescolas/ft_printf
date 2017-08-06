/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:06:16 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 17:24:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnum(long long n, int base, char letter_case)
{
	int		i;
	char	buf[32];

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;
	if (n % base < 10)
		buf[i++] = ((n % base) + '0');
	else
		buf[i++] = (n % base) - 10 + letter_case;
	while (n /= base)
	{
		if (n % base < 10)
			buf[i++] = ((n % base) + '0');
		else
			buf[i++] = (n % base) - 10 + letter_case;
	}
	while (i)
		ft_putchar(buf[--i]);
}

int		ft_printnum(t_argfmt arg)
{
	if (arg.specifier == 'd' || arg.specifier == 'i')
		ft_putnum(arg.num_val, 10, 0);
	else if (arg.specifier == 'x')
		ft_putnum(arg.num_val, 16, 'a');
	else if (arg.specifier == 'X')
		ft_putnum(arg.num_val, 16, 'A');
	else if (arg.specifier == 'o')
		ft_putnum(arg.num_val, 8, 'a');
	else if (arg.specifier == 'O')
		ft_putnum(arg.num_val, 8, 'A');
}
