#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n)
{
	char	buf[32];
	int		i;

	i = 0;
	buf[i++] = ((n % 10) + '0');
	while (n /= 10)
		buf[i++] = ((n % 10) + '0');
	while (i)
		ft_putchar(buf[--i]);
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
			else if (*fmt == 'd')
			{
				if (lflag)
					num = va_arg(a_list, long);
				else
					num = va_arg(a_list, int);
				if (num < 0)
				{
					ft_putchar('-');
					num *= -1;
				}
				ft_putnbr(num);
						
			}
			else
				ft_putchar(*fmt);
			++fmt;

		}
		else
			ft_putchar(*fmt++);
	}
}
