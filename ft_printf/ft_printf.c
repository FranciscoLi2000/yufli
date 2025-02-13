#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
static int	ft_vsnprintf(char *buf, int size, const char *format, va_list *ap)
{
	char	*str;
	char	c;
	int	n;
	int	is_long;
	int	prefix;
	int	uppercase;
	long	num;
	void	*ptr;
	unsigned long	nb;
	unsigned long	addr;

	n = 0;
	while (*format && n < size - 1)
	{
		if (*format != '%')
		{
			buf[n++] = *format++;
			continue ;
		}
		format++;  /* 跳过 '%' */
		is_long = 0;   /* 假设根据格式符判断是否需要 long 类型 */
		prefix = 0;
		while (*format == '#' || *format == 'l' || *format == 'h')
		{
			if (*format == 'l')
				is_long = 1;
			format++;
		}
		if (*format == 'd' || *format == 'i')
		{
			if (is_long)
				num = va_arg(*ap, long);
			else
				num = va_arg(*ap, int);
			if (num < 0)
			{
				buf[n++] = '-';
				num = -num;
			}
			ft_itoa(buf, &n, size, num);
		}
		else if (*format == 'c')
		{
			c = (char)va_arg(*ap, int);
			if (n < size - 1)
				buf[n++] = c;
		}
		else if (*format == 'u')
		{
			if (is_long)  /* 假设 is_long 表示是否需要 long 类型 */
				ft_utoa(buf, &n, size, va_arg(*ap, unsigned long));
			else
				ft_utoa(buf, &n, size, va_arg(*ap, unsigned int));
		}
		else if (*format == 'x' || *format == 'X')
		{
			uppercase = (*format == 'X');
			if (is_long)
				nb = va_arg(*ap, unsigned long);
			else
				nb = va_arg(*ap, unsigned int);
			if (prefix)
				ft_htoa_pre(buf, &n, size, nb, uppercase);
			else
				ft_htoa(buf, &n, size, nb, uppercase);
		}
		else if (*format == 'p')
		{
			ptr = va_arg(*ap, void*);
			addr = (unsigned long)ptr;  /* 将指针转为 unsigned long */
			ft_stoa(buf, &n, size, "0x");
			ft_htoa(buf, &n, size, addr, 0);  /* 强制小写十六进制 */
		}
		else if (*format == 's')
		{
			str = va_arg(*ap, char*);
			if (!str)
				ft_stoa(buf, &n, size, "(null)");  /* 处理 NULL 指针 */
			else
				ft_stoa(buf, &n, size, str);
		}
		else
			return (-1);  /* 非法格式符 */
		format++;
	}
	buf[n] = '\0';
	return (n);
}
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	buf[1024];
	int	ret;

	va_start(ap, format);
	ret = ft_vsnprintf(buf, sizeof(buf) - 1, format, &ap);
	va_end(ap);
	if (ret > 0)
		ret = write(1, buf, ret);
	return (ret);
}
