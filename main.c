#include <stdio.h>
#include <stdarg.h>

void	ft_printf(char *fmt, ... );

int		main(void)
{
	ft_printf("%-3.5d\n", 3000000000);
	printf("%-3.5ld\n", 3000000000);

	ft_printf("%%\n");

	ft_printf("This string contains %ld numbers and %03d other things.?", 3000000000, 17);
	return (0);
}
