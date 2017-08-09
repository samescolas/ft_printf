/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:01:39 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 15:03:14 by sescolas         ###   ########.fr       */
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

static void	apply_padding(t_argfmt info, char **text)
{
	char	padding;
	char	*new;
	int		to_add;

	padding = info.flags.pad_with_zeros ? '0' : ' ';
	if ((to_add = info.width - ft_strlen(*text)) > 0)
	{
		new = ft_strnew(ft_strlen(*text) + to_add);
		if (info.flags.left_justify)
		{
			while (to_add--)
				ft_strncat(new, &padding, 1);
			ft_strcat(new, *text);
		}
		else
		{
			ft_strcat(new, *text);
			while (to_add--)
				ft_strncat(new, &padding, 1);
		}
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
}

static void	apply_precision(t_argfmt info, char **text)
{
	int		to_add;
	char	*new;
	if (info.flags.pad_with_zeros && info.flags.special)
		return ;
	if (info.prec > 0 && (to_add = info.prec - ft_strlen(info.text)) > 0)
	{
		new = ft_strnew(to_add + ft_strlen(info.text));
		while (to_add--)
			ft_strncat(new, "0", 1);
		ft_strcat(new, info.text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
}

void	apply_formatting(t_argfmt info, char **text)
{
	remove_sign(info, text);
	if (is_numeric_specifier(info.spec))
		apply_precision(info, text);
	apply_sign(info, text);
	apply_padding(info, text);

}
