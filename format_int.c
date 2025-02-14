/* 处理有符号整数（%d/%i） */
void	format_integer(char *buf, int *n, int size, long num, t_format *fmt)
{
	char	temp[32];
	char	pad_char;
	int	i;
	int	is_negative;
	int	padding;

	i = 0;
	is_negative = (num < 0);
	/* 处理负数 */
	if (is_negative)
		num = -num;
	/* 转换为字符串（逆序） */
	do
	{
		temp[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);
	/* 处理精度填充 */
	while (i < fmt->precision)
		temp[i++] = '0';
	/* 添加符号（负数、+、空格）*/
	if (is_negative)
		temp[i++] = '-';
	else if (fmt->plus)
		temp[i++] = '+';
	else if (fmt->space)
		temp[i++] = ' ';
	/* 处理字段宽度 */
	padding = fmt->width - i;
	if (fmt->zero_pad && !fmt->left_align)
		pad_char = '0';
	else
		pad_char = ' ';
	/* 左对齐填充 */
	if (!fmt->left_align && padding > 0)
	{
		while (padding-- > 0 && *n < size - 1)
			buf[(*n)++] = pad_char;
	}
	/* 逆序写入缓冲区 */
	while (i-- > 0 && *n < size - 1)
		buf[(*n)++] = temp[i];
	/* 右对齐填充 */
	if (fmt->left_align && padding > 0)
	{
		while (padding-- > 0 && *n < size - 1)
			buf[(*n)++] = ' ';
	}
}
