/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/09 09:44:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
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
	ssize_t		num;
	char		*str;

	str = (void *)0;
	if (*(*fmt + 1) && is_numeric_specifier(get_specifier(*fmt)))
	{
		num = (ssize_t)arg;
		ft_putstr("in print_arg: ");
		ft_putnbr(num);
		ft_putendl("");
		return (print_parsed_arg(parse_arg(fmt, &num)));
	}
	else if (*(*fmt + 1))
	{
		str = (char *)arg;
		if (str)
			return (print_parsed_arg(parse_arg(fmt, str)));
		else
			return (write(1, "(null)", 6));
	}
	return (0);
}
*/
static void	print_arg(char **fmt, size_t *chars_printed, va_list args)
{
	//t_argfmt	fmt_info;
	if (!fmt || !args)
		write(1, "not here\n", *chars_printed);

	write(1, "here\n", 5);
	//fmt_info = get_formatting(fmt);
	//convert_arg(&fmt_info, args);
	//format_arg(&fmt_info);
	//chars_printed = write(1, fmt_info.formatted, ft_strlen(fmt_info.formatted));
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

static void	ft_printf_va(const char *fmt, size_t *chars_printed, va_list args)
{
	while (*fmt)
	{
		if (*fmt == '%' && !is_double_percent((char **)&fmt, chars_printed))
		{
			print_arg((char **)&fmt, chars_printed, args);
		}
		else if (*fmt)
			write(++(*chars_printed) != 0, fmt++, 1);
	}
}

int			ft_printf(const char *fmt, ...)
{
	va_list	arg_list;
	size_t	chars_printed;

	chars_printed = 0;
	va_start(arg_list, fmt);
	ft_printf_va(fmt, &chars_printed, arg_list);
	va_end(arg_list);
	return (chars_printed);
}
