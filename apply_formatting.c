/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:01:39 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 14:42:05 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_sign(t_argfmt info, char **text)
{
	char	*new;

	ft_putstr("entering apply_sign\n");
	ft_putstr("text: ");
	ft_putendl(*text);
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
	ft_putstr("text: ");
	ft_putendl(*text);
	ft_putstr("leaving apply_sign\n");
}
static void	remove_sign(t_argfmt info, char **text)
{
	char	*sign;

	ft_putstr("entering remove_sign\n");
	ft_putstr("text: ");
	ft_putendl(*text);
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
	ft_putstr("text: ");
	ft_putendl(*text);
	ft_putstr("leaving remove_sign\n");
}

static void	apply_left_padding(t_argfmt info, char **text)
{
	ft_putstr("entering apply_lpadding\n");
	ft_putstr("text: ");
	ft_putendl(*text);
	if (info.flags.pad_with_zeros && info.flags.special)
		return ;

	ft_putstr("text: ");
	ft_putendl(*text);
	ft_putstr("leaving apply_lpadding\n");
}

static void	apply_precision(t_argfmt info, char **text)
{
	int		to_add;
	char	*new;
	ft_putstr("entering apply_precision\n");
	ft_putstr("text: ");
	ft_putendl(*text);
	if (info.flags.pad_with_zeros && info.flags.special)
		return ;
	if (info.prec > 0 && (to_add = info.prec - ft_strlen(info.text)) > 0)
	{
		//to_add = info.prec - ft_strlen(info.text);
		ft_putstr("adding ");
		ft_putnbr(to_add);
		ft_putstr(" 0's\n");
		new = ft_strnew(to_add + ft_strlen(info.text));
		while (to_add--)
			ft_strcat(new, "0");
		ft_strcat(new, info.text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
	ft_putstr("text: ");
	ft_putendl(*text);
	ft_putstr("leaving apply_precision\n");
}

void	apply_formatting(t_argfmt info, char **text)
{
	remove_sign(info, text);
	if (is_numeric_specifier(info.spec))
		apply_precision(info, text);
	if (info.flags.pad_with_zeros)
		apply_sign(info, text);
	apply_left_padding(info, text);
	if (!info.flags.pad_with_zeros)
		apply_sign(info, text);

}
