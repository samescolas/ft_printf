/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:32:28 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/13 23:15:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cleanup_strs(char **text, char **replacement)
{
	ft_strdel(text);
	*text = *replacement;
	*replacement = (void *)0;
}

static void	adjust_prec_str(t_argfmt info, char **text, size_t *len)
{
	char	*new;

	if (info.prec < ft_strlen(*text))
	{
		new = ft_strnew(info.prec);
		ft_strncat(new, *text, info.prec);
		*len = info.prec;
	}
	else
		return ;
	cleanup_strs(text, &new);
}

static void	adjust_prec_nbr(t_argfmt info, char **text, size_t *len)
{
	char	*new;
	int		to_add;

	if ((info.flags.pad_with_zeros && info.flags.special) ||
		(!is_nonzero(*text) && ft_toupper(info.spec) != 'D'))
		return ;
	if ((to_add = info.prec - *len) > 0)
	{
		*len += to_add;
		new = ft_strnew(*len);
		if (ft_toupper(info.spec) == 'X'
									&& info.flags.special && is_nonzero(*text))
		{
			ft_strncat(new, "0", 1);
			ft_strncat(new, &info.spec, 1);
		}
		while (to_add--)
			ft_strncat(new, "0", 1);
		if (ft_toupper(info.spec) == 'X' && info.flags.special
														&& is_nonzero(*text))
			ft_strcat(new, (info.text + 2));
		else
			ft_strcat(new, info.text);
		cleanup_strs(text, &new);
	}
}

void		apply_precision(t_argfmt info, char **text, size_t *len)
{
	if (ft_toupper(info.spec) == 'C' || info.prec <= 0)
		return ;
	else if (ft_toupper(info.spec) == 'S')
		adjust_prec_str(info, text, len);
	else
		adjust_prec_nbr(info, text, len);
}
