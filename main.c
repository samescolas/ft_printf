#include <stdio.h>
#include <stdarg.h>

void	ft_printf(char *fmt, ... );

int		main(void)
{
	ft_printf("%-3.5d\n", 42);
	return (0);
}
