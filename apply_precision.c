/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:32:28 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 13:46:43 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_prec_str(t_argfmt info, char **text)
{
	char	*new;

	if (info.prec < ft_strlen(*text))
	{
		new = ft_strnew(info.prec);
		ft_strncat(new, *text, info.prec);
	}
	else
		return ;
	ft_strdel(text);
	*text = new;
	new = (void *)0;
}

static void	adjust_prec_nbr(t_argfmt info, char **text)
{
	char	*new;
	int		to_add;

	new = (void *)0;
	if ((info.flags.pad_with_zeros && info.flags.special) || !is_nonzero(*text))
		return ;
	if (info.prec > 0 && (to_add = info.prec - ft_strlen(info.text)) > 0)
	{
		new = ft_strnew(to_add + ft_strlen(info.text));
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
		ft_strdel(text);
		*text = new;
	}
}

void		apply_precision(t_argfmt info, char **text)
{
	if (ft_toupper(info.spec) == 'C' || info.prec <= 0)
		return ;
	else if (ft_toupper(info.spec) == 'S')
		adjust_prec_str(info, text);
	else
		adjust_prec_nbr(info, text);
}
