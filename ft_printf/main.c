#include "ft_printf.h"

int	main()
{
	int	x;

	x = 42;
	ft_printf("char %c\n", 'T');
	ft_printf("string %s\n", "yufli");
	ft_printf("pointer %p\n", &x);
	ft_printf("base10 %d\n", -13);
	ft_printf("integer %i\n", 124);
	ft_printf("unsigned %u\n", 245);
	ft_printf("lower hex %x\n", 243);
	ft_printf("upper hex %X\n", 123);
	ft_printf("%12%");
	return (0);
}
