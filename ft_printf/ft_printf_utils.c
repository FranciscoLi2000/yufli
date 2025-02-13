#include "ft_printf.h"
void	ft_itoa(char *buf, int *n, int size, long num)
{
	char	temp[20];  /* 假设最大长度为 20（足够存储 64 位整数）*/
	int	i;
	int	is_negative;

	i = 0;
	is_negative = (num < 0);
	if (num == 0)
		temp[i++] = '0';
	else
	{
		if (is_negative)
			num = -num;  /* 转为正数处理 */
		while (num > 0)
		{
			temp[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	/* 写入符号 */
	if (is_negative && (*n < size - 1))
		buf[(*n)++] = '-';
	/* 逆序写入缓冲区 */
	while (i-- > 0 && *n < size - 1)
		buf[(*n)++] = temp[i];
}
void	ft_utoa(char *buf, int *n, int size, unsigned long num)
{
	char	temp[20];
	int	i;

	i = 0;
	if (num == 0)
		temp[i++] = '0';
	else
	{
		while (num > 0)
		{
			temp[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	/* 逆序写入缓冲区 */
	while (i-- > 0 && *n < size - 1)
		buf[(*n)++] = temp[i];
}
void	ft_htoa(char *buf, int *n, int size, unsigned long num, int uppercase)
{
	const char	*digits_lower;
	const char	*digits_upper;
	const char	*digits;
	char	temp[20];
	int	i;

	digits_lower = "0123456789abcdef";
	digits_upper = "0123456789ABCDEF";
	i = 0;
	if (uppercase)
		digits = digits_upper;
	else
		digits = digits_lower;
	if (num == 0)
		temp[i++] = '0';
	else
	{
		while (num > 0)
		{
			temp[i++] = digits[num % 16];
			num /= 16;
		}
	}
	/* 逆序写入缓冲区 */
	while (i-- > 0 && *n < size - 1)
		buf[(*n)++] = temp[i];
}
void	ft_htoa_pre(char *buf, int *n, int size, unsigned long num, int uppercase)
{
	if (*n < size - 1)
		buf[(*n)++] = '0';
	if (*n < size - 1)
	{
		if (uppercase)
			buf[(*n)++] = 'X';
		else
			buf[(*n)++] = 'x';
	}
	ft_htoa(buf, n, size, num, uppercase); /* 调用普通十六进制转换 */
}
void	ft_stoa(char *buf, int *n, int size, char *str)
{
	const char	*null_str;
	int	i;

	if (!str)
	{
		null_str = "(null)";
		i = 0;
		while (null_str[i] && *n < size - 1)
		{
			buf[(*n)++] = null_str[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (str[i] && *n < size - 1)
		{
			buf[(*n)++] = str[i];
			i++;
		}
	}
}
