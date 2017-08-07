/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:34:07 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/06 17:53:30 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		toggle(t_bool *flag)
{
	if (*flag)
		ft_fatal("duplicate flag found\n");
	*flag = 1;
}

void		toggle_flag(t_flags *flags, char flag)
{
	if (flag == '#')
		toggle(&flags->special);
	if (flag == '0')
		toggle(&flags->pad_with_zeros);
	if (flag == '-')
		toggle(&flags->left_justify);
	if (flag == '+')
		toggle(&flags->show_sign);
	if (flag == ' ')
		toggle(&flags->space);
}

void		ftp_parse_flags(t_flags *flags, char **fmt)
{
	while (**fmt && is_flag(**fmt))
		toggle_flag(flags, *(*fmt)++);
}
