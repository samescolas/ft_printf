/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 11:10:27 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		toggle_flag(t_flags *flags, char flag)
{
	if (flag == '#')
		flags->special = 1;
	if (flag == '0')
		flags->pad_with_zeros = 1;
	if (flag == '-')
		flags->left_justify = 1;
	if (flag == '+')
		flags->show_sign = 1;
	if (flag == ' ')
		flags->space = 1;
}

void		get_flags(char **fmt, t_flags *flags)
{
	while (**fmt && is_flag(**fmt))
		toggle_flag(flags, *(*fmt)++);
}
