#include "ft_printf.h"

void	format_integer(char *buf, int *n, int size, long num, t_format *fmt)
{
	char	temp[20];
	char	pad_char;
	int	i;
	int	is_negative;
	int	padding;

	i = 0;
	is_negative = (num < 0);
	if (is_negative)
		num = -num;
	do
	{
		temp[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);
	/* 处理精度填充 */
	while (i < fmt->precision)
		temp[i++] = '0';
	/* 添加符号 */
	if (is_negative)
		temp[i++] = '-';
	else if (fmt->plus)
		temp[i++] = '+';
	else if (fmt->space)
		temp[i++] = ' ';
	/* 处理字段宽度填充 */
	padding = fmt->width - i;
	if (!fmt->left_align && padding > 0)
	{
		if (fmt->zero_pad)
			pad_char = '0';
		else
			pad_char = ' ';
		while (padding-- > 0 && *n < size - 1)
			buf[(*n)++] = pad_char;
	}
	/* 逆序写入缓冲区 */
	while (i-- > 0 && *n < size - 1)
		buf[(*n)++] = temp[i];
	/* 左对齐填充剩余空间 */
	if (fmt->left_align && padding > 0)
	{
		while (padding-- > 0 && *n < size - 1)
			buf[(*n)++] = ' ';
	}
}
