/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 13:25:19 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_arg(char **fmt, size_t *chars_printed, va_list args)
{
	t_argfmt	fmt_info;

	ft_bzero(&fmt_info, sizeof(fmt_info));
	get_formatting(fmt, &fmt_info);
	get_conversion(&fmt_info, args);
	if (ft_toupper(fmt_info.spec) != 'C')
		fmt_info.arg_len = ft_strlen(fmt_info.text);
	if (ft_strchr(fmt_info.text, '-') == (void *)0)
		fmt_info.sign = '+';
	else
		fmt_info.sign = '-';
	apply_formatting(fmt_info, &fmt_info.text, &fmt_info.arg_len);
	if (ft_toupper(fmt_info.spec) == 'C' && is_blank(fmt_info.text))
		write((++(*chars_printed) != 0),
								fmt_info.text, ft_strlen(fmt_info.text));
	else
	{
		write(1, fmt_info.text, fmt_info.arg_len);
		*chars_printed += fmt_info.arg_len;
	}
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
			print_arg((char **)&fmt, chars_printed, args);
		else if (*fmt)
			write((++(*chars_printed) != 0), fmt++, 1);
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
