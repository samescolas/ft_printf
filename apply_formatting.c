/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:01:39 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 11:16:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_sign(t_argfmt info, char **text)
{
	char	*new;

	if (!is_signed_specifier(info.spec))
		return ;
	if (info.sign == '-' || info.flags.show_sign)
	{
		new = ft_strnew(ft_strlen(*text) + 1);
		ft_strcat(new, &info.sign);
		ft_strcat(new, *text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
}

static void	remove_sign(t_argfmt info, char **text)
{
	char	*sign;

	if (info.flags.pad_with_zeros && info.flags.special)
		return ;
	if ((sign = ft_strchr(*text, '-')))
	{
		while (*sign)
		{
			if (*(sign + 1))
				*sign = *(sign + 1);
			else
				*sign = '\0';
			sign += 1;
		}
	}
}
/*
static void	the_space_flag(t_argfmt info, char **text)
{
	char	*new;

	if (is_signed_specifier(info.spec) && ft_toupper(info.spec) != 'C' &&
								!info.flags.show_sign && info.flags.space &&
											ft_strchr(*text, '-') == (void *)0)
	{
		new = ft_strnew(ft_strlen(info.text + 1));
		ft_strncat(new, " ", 1);
		ft_strcat(new, *text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
}
*/

void	apply_formatting(t_argfmt info, char **text)
{
	char	*new;

	remove_sign(info, text);
	apply_precision(info, text);
	if (info.flags.special &&
						is_hex_or_oct(info.spec) && is_nonzero(info.text))
	{
		new = ft_strnew(ft_strlen(*text) + (ft_toupper(info.spec) == 'X') + 1);
		ft_strncat(new, "0", 1);
		if (ft_toupper(info.spec) == 'X')
			ft_strncat(new, &info.spec, 1);
		ft_strcat(new, *text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
	apply_sign(info, text);
	apply_padding(info, text);
	//the_space_flag(info, text);
}
