#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n, char b)
{
	char	buf[32];
	int		i;
	int		base;

	if (b == 'o')
		base = 8;
	else if (b == 'x')
		base = 16;
	else
		base = 10;
	i = 0;
	if (n % base < 10)
		buf[i++] = ((n % base) + '0');
	else
		buf[i++] = ((n % base) - 10 + 'a');
	while (n /= base)
	{
		if (n % base < 10)
			buf[i++] = ((n % base) + '0');
		else
			buf[i++] = ((n % base) - 10 + 'a');
	}
	while (i)
		ft_putchar(buf[--i]);
}

static int	print_arg(char *fmt, void *arg)
{
	long	arg_num;
	char	*arg_str;
	long	length;
	long	width;
	float	precision;
	char	flag;
	int		verbose;

	verbose = 1;

	if (is_flag(*fmt))
		flag = *fmt++;
	if (verbose)
	{
		write(1, "flag: ", 6);
		write(1, &flag, 1);
		write(1, "\n", 1);
	}
	width = ft_atoi(fmt);
	if (verbose)
	{
		write(1, "length: ", 8);
		ft_putnbr(width);
		write(1, "\n", 1);
	}
	while (*fmt && *fmt >= '0' && *fmt <= '9')
		++fmt;
	if (*fmt == '.')
		precision = ft_atoi(++(*fmt));
	while (*fmt && *fmt >= '0' && *fmt <= '9')
		++fmt;
	if (is_length_specifier(*fmt))
		length = *fmt++;
}

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
