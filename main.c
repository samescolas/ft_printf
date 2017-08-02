#include <stdio.h>
#include <stdarg.h>

void	ft_printf(char *fmt, ... );

int		main(void)
{
	ft_printf("ME: octal num: %o\n", 42);
	printf("XX: octal num: %o\n\n", 42);

	ft_printf("ME: hex num: %x\n", 42);
	printf("XX: hex num: %x\n\n", 42);

	ft_printf("ME: long hex num: %lx\n", 174217421742);
	printf("XX: long hex num: %lx\n", 174217421742);
	return (0);
}
