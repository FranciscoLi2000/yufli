/* 处理十六进制（%x/%X）*/
void	format_hex(char *buf, int *n, int size, unsigned long num, t_format *fmt, int uppercase)
{
	const char	*digits;
	char	temp[32];
	char	pad_char;
	int	i;
	int	padding;

	i = 0;
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	/* 转换为十六进制字符串（逆序）*/
	do
	{
		temp[i++] = digits[num % 16];
		num /= 16;
	} while (num > 0);
	/* 处理精度填充 */
	while (i < fmt->precision)
		temp[i++] = '0';
	/* 添加前缀（如 0x） */
	if (fmt->prefix)
	{
		if (uppercase)
			temp[i++] = 'X';
		else
			temp[i++] = 'x';
		temp[i++] = '0';
	}
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
