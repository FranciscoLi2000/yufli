
void	format_string(char *buf, int *n, int size, char *str, t_format *fmt)
{
	if (!str)
		str = "(null)";
	int len = 0;
	/* 计算字符串有效长度（考虑精度限制） */
	while (str[len] && (fmt->precision < 0 || len < fmt->precision))
		len++;
	/* 处理字段宽度 */
	int padding = fmt->width - len;
	char pad_char = ' ';
	/* 左对齐填充 */
	if (!fmt->left_align && padding > 0)
	{
		while (padding-- > 0 && *n < size - 1)
			buf[(*n)++] = pad_char;
	}
	/* 写入字符串 */
	for (int i = 0; i < len && *n < size - 1; i++)
		buf[(*n)++] = str[i];
	/* 右对齐填充 */
	if (fmt->left_align && padding > 0)
	{
		while (padding-- > 0 && *n < size - 1)
			buf[(*n)++] = ' ';
	}
}
