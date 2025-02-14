/* 将格式字符串的解析逻辑拆分为独立的函数 parse_format，
 * 逐步提取标志、宽度、精度和长度修饰符 */
void	parse_format(const char **format, t_format *fmt, va_list *ap)
{
	/* 解析标志（如 '-', '0', '#'） */
	while (**format == '-' || **format == '0' || **format == '#' || 
			           **format == ' ' || **format == '+')
	{
		switch (**format)
		{
			case '-': fmt->left_align = 1; break;
			case '0': fmt->zero_pad = 1; break;
			case '#': fmt->prefix = 1; break;
			case ' ': fmt->space = 1; break;
			case '+': fmt->plus = 1; break;
		}
		(*format)++;
	}
	/* 解析宽度（静态或动态） */
	if (**format == '*')
	{
		fmt->width = va_arg(*ap, int);  /* 动态宽度 */
		(*format)++;
	}
	else
	{
		fmt->width = 0;
		while (**format >= '0' && **format <= '9')
		{
			fmt->width = fmt->width * 10 + (**format - '0'); /* 静态宽度 */
			(*format)++;
		}
	}
	/* 解析精度（静态或动态） */
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			fmt->precision = va_arg(*ap, int); /* 动态精度 */
			(*format)++;
		}
		else
		{
			fmt->precision = 0;
			while (**format >= '0' && **format <= '9')
			{
				fmt->precision = fmt->precision * 10 + (**format - '0'); /* 静态精度 */
				(*format)++;
			}
		}
	}
	/* 解析长度修饰符（'h'/'l'/'ll'） */
	if (**format == 'h')
	{
		fmt->is_short = 1;
		(*format)++;
	}
	else if (**format == 'l')
	{
		fmt->is_long = 1;
		(*format)++;
		if (**format == 'l')
		{
			fmt->is_long = 2; /* 处理 'll' */
			(*format)++;
		}
	}
}
