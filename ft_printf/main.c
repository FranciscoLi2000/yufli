#include "ft_printf.h"

int	main()
{
	int	x;

	x = 42;
	ft_printf("ft_printf: %c\n", 'A');
	ft_printf("ft_printf: %s\n", "Hello, World!");
	ft_printf("ft_printf: %d, %i\n", 123, -456);
	ft_printf("ft_printf: %u\n", 4294967295U);
	ft_printf("ft_printf: %x, %X\n", 255, 255);
	ft_printf("ft_printf: %p\n", &x);
	ft_printf("ft_printf: %%\n");
	return (0);
}
