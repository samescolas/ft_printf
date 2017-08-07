/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/06 22:47:36 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(t_argfmt arg)
{
	if (ft_toupper(arg.specifier) == 'S')
	{
		ft_putstr(arg.arg.str_val);
		return (ft_strlen(arg.arg.str_val));
	}
	else if (is_numeric_specifier(arg.specifier))
	{
		return (ftp_printnum(arg));
	}
	return (0);
}

t_length	get_length(char **fmt, t_argfmt *options)
{
	options->length_specified = 1;
	if (is_length_specifier(*(*fmt + 1)))
	{
		*fmt += 2;
		if (*(*fmt - 2) == 'l' && *(*fmt - 1) == 'l')
			return (LL);
		else if (*(*fmt - 2) == 'h' && *(*fmt - 1) == 'h')
			return (HH);
		else
		{
			write(1, (*fmt - 2), 2);
			ft_fatal("invalid length specifier");
		}
	}
	*fmt += 1;
	if (*(*fmt - 1) == 'l')
		return (L);
	else if (*(*fmt - 1) == 'h')
		return (H);
	else if (*(*fmt - 1) == 'j')
		return (J);
	else if (*(*fmt - 1) == 'z')
		return (Z);
	return (0);
}

static int	parse_arg(char **fmt, void *arg)
{
	t_argfmt	options;
	size_t		*num;

	*fmt += 1;
	ft_bzero(&options, sizeof(options));
	ftp_parse_flags(&options.flags, fmt);
	options.width = ft_atoi(*fmt);
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
	if (**fmt && **fmt == '.')
		options.precision = ft_atoi(++(*fmt));
	while (**fmt && ft_isdigit(**fmt))
		++(*fmt);
	if (is_length_specifier(**fmt))
		options.length = get_length(fmt, &options);
	ft_bzero(&options.arg, sizeof(options.arg));
	if (is_numeric_specifier(**fmt))
	{
		num = (size_t *)arg;
		options.arg.num_val = *num;
	}
	else if (**fmt == 's')
		options.arg.str_val = (char *)arg;
	options.specifier = **fmt;
	++(*fmt);
	return (print_arg(options));
}

char	get_specifier(char *fmt)
{
	char	*ptr;

	ptr = fmt;
	while (*ptr && !is_specifier(*ptr))
		++ptr;
	return (*ptr);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	a_list;
	char	*str;
	size_t	num;
	size_t	chars_printed;

	chars_printed = 0;
	str = (void *)0;
	va_start(a_list, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) && *(fmt + 1) == '%')
			{
				ft_putchar('%');
				fmt += 2;
				chars_printed += 1;
			}
			else if (*(fmt + 1) && is_numeric_specifier(get_specifier((char *)fmt)))
			{
				num = va_arg(a_list, size_t);
				chars_printed += parse_arg((char **)&fmt, &num);
			}
			else if (*(fmt + 1))
			{
				str = va_arg(a_list, char *);
				chars_printed += parse_arg((char **)&fmt, str);
			}
			else
				ft_fatal("whatcha doin?\n");
		}
		else
		{
			ft_putchar(*fmt++);
			chars_printed += 1;
		}
	}
	return (chars_printed);
}

/*
int		ft_printf(const char *fmt, ... )
{
	va_list	a_list;
	char	*arg_fmt;
	char	*str;
	long	num;
	long	printed;

	printed = 0;
	va_start( a_list, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			arg_fmt = (char *)(fmt + 1);
			if (*(++fmt) == '%')
			{
				ft_putchar('%');
				++printed;
				++fmt;
				continue ;
			}
			if (is_flag(*fmt))
					++fmt;
			while (*fmt && *fmt >= '0' && *fmt <= '9')
				++fmt;
			if (*fmt == '.')
				++fmt;
			while (*fmt && *fmt >= '0' && *fmt <= '9')
				++fmt;
			if (is_length_specifier(*fmt))
				++fmt;
			if (*fmt == 's')
			{
				printed += parse_arg(arg_fmt, str);
			}
			else
			{
				printed += parse_arg(arg_fmt, (void *)&num);
			}
			++fmt;
		}
		else
		{
			ft_putchar(*fmt++);
			printed += 1;
		}
	}
	return (printed);
}
*/
