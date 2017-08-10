/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/10 10:35:52 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_info(char *fmt, t_argfmt fmt_info)
{
	ft_putstr(fmt);
	ft_putstr(": \n");
	ft_putstr("flags: ");
	if (fmt_info.flags.space)
		ft_putstr(" ");
	if (fmt_info.flags.special)
		ft_putstr("#");
	if (fmt_info.flags.pad_with_zeros)
		ft_putstr("0");
	if (fmt_info.flags.left_justify)
		ft_putstr("-");
	if (fmt_info.flags.show_sign)
		ft_putstr("+");
	ft_putendl("");
	ft_putstr("width: ");
	ft_putnbr(fmt_info.width);
	ft_putendl("");
	ft_putstr("length: ");
	ft_putnbr(fmt_info.len);
	ft_putendl("");
	ft_putstr("precision: ");
	ft_putnbr(fmt_info.prec);
	ft_putendl("");
	ft_putstr("specifier: ");
	ft_putchar(fmt_info.spec);
	ft_putstr("\nraw arg: ");
	ft_putstr(fmt_info.text);
	ft_putstr("\nsign: ");
	ft_putchar(fmt_info.sign);
	ft_putstr("\n\n");
}

static void	print_arg(char **fmt, size_t *chars_printed, va_list args)
{
	t_argfmt	fmt_info;
	char		*ptr;

	if (!fmt || !args)
		write(1, "not here\n", *chars_printed);
	ptr = (*fmt)++;

	ft_bzero(&fmt_info, sizeof(fmt_info));
	get_formatting(fmt, &fmt_info);
	get_conversion(&fmt_info, args);
	if (ft_strchr(fmt_info.text, '-') == (void *)0)
		fmt_info.sign = '+';
	else
		fmt_info.sign = '-';
	apply_formatting(fmt_info, &fmt_info.text);
	if (ft_toupper(fmt_info.spec) == 'C' && is_blank(fmt_info.text))
		write((++*chars_printed != 0), fmt_info.text, ft_strlen(fmt_info.text));
	else
		*chars_printed += write(1, fmt_info.text, ft_strlen(fmt_info.text));
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
