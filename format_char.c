
void	format_char(char *buf, int *n, int size, char ch, t_format *fmt)
{
	int	padding;
	char	pad_char;

	padding = fmt->width - 1;
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
	/* 写入字符 */
	if (*n < size - 1)
		buf[(*n)++] = ch;
	/* 右对齐填充 */
	if (fmt->left_align && padding > 0)
	{
		while (padding-- > 0 && *n < size - 1)
			buf[(*n)++] = ' ';
	}
}
