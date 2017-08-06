/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 17:26:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/

void	ft_putnum(long n, char b)
{
	char	buf[32];
	int		i;
	int		base;
	char	offset;

	if (b == 'd')
		n = (int)n;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (b == 'o' || b == 'O')
		base = 8;
	else if (b == 'x' || b == 'X')
		base = 16;
	else
		base = 10;
	if (b == 'X' || b == 'O')
		offset = 'A';
	else
		offset = 'a';
	i = 0;
	if (n % base < 10)
		buf[i++] = ((n % base) + '0');
	else
		buf[i++] = ((n % base) - 10 + offset);
	while (n /= base)
	{
		if (n % base < 10)
			buf[i++] = ((n % base) + '0');
		else
			buf[i++] = ((n % base) - 10 + offset);
	}
	while (i)
		ft_putchar(buf[--i]);
}

static int	print_arg(t_argfmt arg)
{
	/*
	ft_putstr("inside print_arg\n");
	ft_putstr("flag: ");
	ft_putchar(arg.flag);
	ft_putstr("\nwidth: ");
	ft_putnbr((int)arg.width);
	ft_putstr("\nprecision: ");
	ft_putnbr((int)arg.precision);
	ft_putstr("\nlength: ");
	ft_putnbr((int)arg.length);
	ft_putstr("\nspecifier: ");
	ft_putchar(arg.specifier);
	ft_putstr("\n");
	*/

	if (ft_toupper(arg.specifier) == 'S')
	{
		ft_putstr(arg.arg.str_val);
		return (ft_strlen(arg.arg.str_val));
	}
	else if (is_numeric_specifier(arg.specifier))
		return (ft_printnum(arg));
	else if (ft_toupper(arg.specifier) == 'D')
	{
		ft_putnum(arg.arg.num_val, arg.length == 'l' ? '\0' : arg.specifier);
		return (ft_numlen(arg.arg.num_val, 10));
	}
	else if (ft_toupper(arg.specifier) == 'X')
	{
		ft_putnum(arg.arg.num_val, arg.specifier);
		return (ft_numlen(arg.arg.num_val, 16));
	}
	return (0);
}

static int	parse_arg(char *fmt, void *arg)
{
	t_argfmt	options;
	long		*num;
	//ft_putstr("\ninside parse_arg...\n");
	//ft_putstr("format string: ");
	//ft_putendl(fmt);
	ft_bzero(&options, sizeof(options));
	options.flag = (is_flag(*fmt) ? *fmt++ : '\0');
	options.width = ft_atoi(fmt);
	while (*fmt && ft_isdigit(*fmt))
		++fmt;
	if (*fmt == '.')
		options.precision = ft_atoi(++fmt);
	while (*fmt && ft_isdigit(*fmt))
		++fmt;
	if (is_length_specifier(*fmt))
		options.length = *fmt++;
	ft_bzero(&options.arg, sizeof(long));
	if (is_numeric_specifier(*fmt))
	{
		num = (long *)arg;
		options.arg.num_val = *num;
	}
	else if (*fmt == 's')
		options.arg.str_val = (char *)arg;
	else
		return (-1);
	options.specifier = *fmt;
	return (print_arg(options));
}

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
				str = va_arg(a_list, char *);
				printed += parse_arg(arg_fmt, str);
			}
			else
			{
				num = va_arg(a_list, long);
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
/*
void	ft_printf(char *fmt, ... )
{
	va_list	a_list;
	int		lflag;
	char	*ptr;
	long	num;

	va_start( a_list, fmt);
	while (*fmt)
	{
		lflag = 0;
		if (*fmt == '%')
		{
			if (*(++fmt) == 'l')
			{
				lflag = 1;
				++fmt;
			}
			if (*fmt == 's')
			{
				ptr = va_arg(a_list, char *);
				while (*ptr)
					ft_putchar(*ptr++);
			}
			else if (*fmt == 'd' || *fmt == 'o' || *fmt == 'x')
			{
				if (lflag)
					num = va_arg(a_list, long);
				else
					num = va_arg(a_list, int);
				if (num < 0)
				{
					if (*fmt == 'd')
						ft_putchar('-');
					num *= -1;
				}
				ft_putnbr(num, *fmt);
			}
			else
				ft_putchar(*fmt);
			++fmt;

		}
		else
			ft_putchar(*fmt++);
	}
}
*/
