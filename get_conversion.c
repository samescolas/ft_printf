/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 11:56:19 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 11:42:40 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_unsigned(t_argfmt *fmt_info, va_list arg)
{
	short	base;
	char	b_case;

	base = get_base(fmt_info->spec);
	b_case = fmt_info->spec >= 97 ? 'a' : 'A';
	if (fmt_info->len == HH)
		fmt_info->text = ft_itoa_base_u(
							(unsigned char)va_arg(arg, int), base, b_case);
	else if (fmt_info->len == H)
		fmt_info->text = ft_itoa_base_u(
							(unsigned short)va_arg(arg, int), base, b_case);
	else if (fmt_info->len == L)
		fmt_info->text = ft_itoa_base_u(
					(unsigned long)va_arg(arg, unsigned long), base, b_case);
	else if (fmt_info->len == LL)
		fmt_info->text = ft_itoa_base_u(
			(unsigned long long)va_arg(arg, unsigned long long), base, b_case);
	else if (fmt_info->len == J)
		fmt_info->text = ft_itoa_base_u(
							(uintmax_t)va_arg(arg, uintmax_t), base, b_case);
	else if (fmt_info->len == Z)
		fmt_info->text = ft_itoa_base_u(
								(size_t)va_arg(arg, size_t), base, b_case);
}

static void	convert_signed(t_argfmt *fmt_info, va_list arg)
{
	short	base;
	char	b_case;

	base = get_base(fmt_info->spec);
	b_case = fmt_info->spec >= 97 ? 'a' : 'A';
	if (fmt_info->len == HH)
		fmt_info->text = ft_itoa_base((char)va_arg(arg, int), base, b_case);
	else if (fmt_info->len == H)
		fmt_info->text = ft_itoa_base((short)va_arg(arg, int), base, b_case);
	else if (fmt_info->len == L)
		fmt_info->text = ft_itoa_base((long)va_arg(arg, long), base, b_case);
	else if (fmt_info->len == LL)
		fmt_info->text =
				ft_itoa_base((long long)va_arg(arg, long long), base, b_case);
	else if (fmt_info->len == J)
		fmt_info->text =
				ft_itoa_base((intmax_t)va_arg(arg, intmax_t), base, b_case);
	else if (fmt_info->len == Z)
		fmt_info->text =
				ft_itoa_base((ssize_t)va_arg(arg, ssize_t), base, b_case);
}

static void	convert_numeric(t_argfmt *fmt_info, va_list arg)
{
	char	b_case;

	b_case = fmt_info->spec >= 'a' ? 'a' : 'A';
	if (fmt_info->len > 0)
	{
		if (is_signed_specifier(fmt_info->spec))
			convert_signed(fmt_info, arg);
		else
			convert_unsigned(fmt_info, arg);
	}
	else if (ft_toupper(fmt_info->spec) == 'D' || fmt_info->spec == 'i')
		fmt_info->text = ft_itoa_base(va_arg(arg, int), 10, b_case);
	else if (ft_toupper(fmt_info->spec) == 'U')
		fmt_info->text = ft_itoa_base(va_arg(arg, unsigned int), 10, b_case);
	else if (ft_toupper(fmt_info->spec) == 'X')
		fmt_info->text = ft_itoa_base(va_arg(arg, unsigned int), 16, b_case);
	else if (ft_toupper(fmt_info->spec) == 'O')
		fmt_info->text = ft_itoa_base(va_arg(arg, unsigned int), 8, b_case);
}

static void	convert_pointer(t_argfmt *fmt_info, va_list arg)
{
	char	*prefix;
	char	*val;
	long	p;

	prefix = ft_strdup("0x");
	if ((p = (long)va_arg(arg, void *)) == 0)
		fmt_info->text = ft_strjoin(prefix, "0");
	else
	{
		val = ft_itoa_base(p, 16, 'a');
		fmt_info->text = ft_strjoin(prefix, val);
		ft_strdel(&val);
	}
	ft_strdel(&prefix);
}

void		get_conversion(t_argfmt *fmt_info, va_list arg)
{
	if (fmt_info->spec == 'c')
	{
		fmt_info->text = ft_strnew(1);
		fmt_info->text[0] = va_arg(arg, int);
		fmt_info->arg_len = ft_isprint(fmt_info->text[0]);
	}
	else if (fmt_info->spec == 'C')
	{
		fmt_info->text = ft_strnew(4);
		fmt_info->arg_len = ft_wctomb((wchar_t)va_arg(arg, int), &fmt_info->text);
	}
	else if (is_numeric_specifier(fmt_info->spec))
		convert_numeric(fmt_info, arg);
	else if (ft_toupper(fmt_info->spec) == 'S')
	{
		if (!(fmt_info->text = ft_strdup(va_arg(arg, char *))))
			fmt_info->text = ft_strdup("(null)");
		return ;
	}
	else if (ft_toupper(fmt_info->spec) == 'P')
		convert_pointer(fmt_info, arg);
}
