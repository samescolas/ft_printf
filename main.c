#include <unistd.h>
#include <stdarg.h>

void	ft_printf(char *fmt, ... );

int		main(void)
{
	ft_printf("test string: %s\nstring2: %s\nand a digit:%ld\n", "shit btches!", "another fucking string?", 174217421742);
	return (0);
}
