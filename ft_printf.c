/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 11:59:05 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_parsed_arg(t_argfmt arg)
{
	if (ft_toupper(arg.specifier) == 'S')
	{
		ft_putstr(arg.arg.str_val);
		return (ft_strlen(arg.arg.str_val));
	}
	else if (is_numeric_specifier(arg.specifier))
		return (ftp_printnum(arg));
	return (0);
}

static int	print_arg(char **fmt, void *arg)
{
	size_t	num;
	char	*str;

	if (*(*fmt + 1) && is_numeric_specifier(get_specifier(*fmt)))
	{
		num = (size_t)arg;
		return (print_parsed_arg(parse_arg(fmt, &num)));
	}
	else if (*(*fmt + 1))
	{
		str = (char *)arg;
		return (print_parsed_arg(parse_arg(fmt, str)));
	}
	return (0);
}

static	int	is_double_percent(char **fmt, size_t *chars_printed)
{
	if (*(*fmt + 1) && *(*fmt + 1) == '%')
	{
		ft_putchar('%');
		*fmt += 2;
		*chars_printed += 1;
		return (1);
	}
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	a_list;
	size_t	chars_printed;

	chars_printed = 0;
	va_start(a_list, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && !is_double_percent((char **)&fmt, &chars_printed))
			chars_printed += print_arg((char **)&fmt, va_arg(a_list, void*));
		else if (*fmt)
			write(++chars_printed != 0, fmt++, 1);
	}
	return (chars_printed);
}
