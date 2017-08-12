/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:01:39 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 12:26:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_sign(t_argfmt info, char **text, size_t *len)
{
	char	*new;

	if (!is_signed_specifier(info.spec))
		return ;
	if (info.sign == '-' || info.flags.show_sign)
	{
		*len += 1;
		new = ft_strnew(ft_strlen(*text) + 1);
		ft_strcat(new, &info.sign);
		ft_strcat(new, *text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
}

static void	remove_sign(t_argfmt info, char **text, size_t *len)
{
	char	*sign;

	if (!is_numeric_specifier(info.spec) ||
							(info.flags.pad_with_zeros && info.flags.special))
		return ;
	if ((sign = ft_strchr(*text, '-')))
	{
		*len -= 1;
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

static void	remove_zeros(t_argfmt info, char **text, size_t *len)
{
	if (!is_nonzero(*text) && info.prec == 0 && info.flags.prec_specified &&
						info.flags.special && is_numeric_specifier(info.spec))
	{
		ft_strdel(text);
		*text = ft_strdup("");
		*len = 0;
	}
}

static void	add_prefix(t_argfmt info, char **text, size_t *len)
{
	char	*new;

	if (info.flags.special &&
						is_hex_or_oct(info.spec) && is_nonzero(info.text))
	{
		*len += 1;
		new = ft_strnew(ft_strlen(*text) + (ft_toupper(info.spec) == 'X') + 1);
		ft_strncat(new, "0", 1);
		if (ft_toupper(info.spec) == 'X')
		{
			*len += 1;
			ft_strncat(new, &info.spec, 1);
		}
		ft_strcat(new, *text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
}

void		apply_formatting(t_argfmt info, char **text, size_t *len)
{
	remove_sign(info, text, len);
	remove_zeros(info, text, len);
	apply_precision(info, text, len);
	add_prefix(info, text, len);
	apply_sign(info, text, len);
	apply_padding(info, text, len);
}
