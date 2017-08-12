/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 21:55:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 12:09:31 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_zeros(char *text, char **new, int len)
{
	char	*ptr;

	ptr = *new;
	if (*text == '+' || *text == '-')
		*ptr++ = *text++;
	else if (*text == '0' && *(text + 1) && ft_toupper(*(text + 1)) == 'X')
	{
		*ptr++ = *text++;
		*ptr++ = *text++;
	}
	while (len--)
		*ptr++ = '0';
	ft_strcat(*new, text);
}

static void	apply_right_padding(char *text, char **new, char padding, int len)
{
	if (padding == '0')
		apply_zeros(text, new, len);
	else
	{
		while (len--)
			ft_strncat(*new, &padding, 1);
		ft_strcat(*new, text);
	}
}

static void	apply_left_padding(char *text, char **new, char padding, int len)
{
	ft_strcat(*new, text);
	while (len--)
		ft_strncat(*new, &padding, 1);
}

static void	the_space_flag(t_argfmt info, char **text, size_t *len)
{
	char	*new;

	if (is_signed_specifier(info.spec) && ft_toupper(info.spec) != 'C' &&
								!info.flags.show_sign && info.flags.space &&
											ft_strchr(*text, '-') == (void *)0)
	{
		*len += 1;
		new = ft_strnew(ft_strlen(info.text + 1));
		ft_strncat(new, " ", 1);
		ft_strcat(new, *text);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
}

void		apply_padding(t_argfmt info, char **text, size_t *len)
{
	char	padding;
	char	*new;
	int		to_add;

	padding = info.flags.pad_with_zeros ? '0' : ' ';
	if (info.flags.left_justify ||
			(is_numeric_specifier(info.spec) && info.prec))
		padding = ' ';
	//if ((to_add = info.width - ft_strlen(*text)) > 0)
	if ((to_add = info.width - *len) > 0)
	{
		new = ft_strnew(*len + to_add);
		*len += to_add;
		if (info.flags.left_justify)
			apply_left_padding(*text, &new, padding, to_add);
		else
			apply_right_padding(*text, &new, padding, to_add);
		ft_strdel(text);
		*text = new;
		new = (void *)0;
	}
	else
		the_space_flag(info, text, len);
}
