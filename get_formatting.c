/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:49:26 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 10:58:46 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_width(char **fmt, size_t *width)
{
	if (ft_isdigit(**fmt))
		*width = ft_atoi(*fmt);
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
}

static void	get_precision(char **fmt, size_t *precision)
{
	if (**fmt != '.' || !ft_isdigit(*(++(*fmt))))
	{
		*precision = 0;
		return ;
	}
	*precision = ft_atoi(*fmt);
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
}

static void	get_specifier(char **fmt, char *specifier)
{
	if (!is_specifier(**fmt))
	{
		if (**fmt == '%')
			*specifier = *(*fmt)++;
		else
			*specifier = '\0';
	}
	*specifier = *(*fmt)++;
}

void		get_formatting(char **fmt, t_argfmt *fmt_info)
{
	get_flags(fmt, &fmt_info->flags);
	get_width(fmt, &fmt_info->width);
	get_precision(fmt, &fmt_info->prec);
	get_length(fmt, &fmt_info->len);
	get_specifier(fmt, &fmt_info->spec);
}
