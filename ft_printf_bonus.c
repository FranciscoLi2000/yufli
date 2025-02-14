
static int	ft_vsnprintf(char *buf, int size, const char *format, va_list *ap)
{
	int	n;
	t_format	fmt;

	n = 0;
	while (*format && n < size - 1)
	{
		if (*format != '%')
		{
			buf[n++] = *format++;
			continue ;
		}
		format++;
		fmt = (t_format){0};
		parse_format(&format, &fmt, ap); /* 解析格式字符串 */
		switch (*format)
		{
			case 'd':
			case 'i':
				long num = va_arg(*ap, long);
				format_integer(buf, &n, size, num, &fmt);
				break ;
			case 'x':
			case 'X':
				unsigned long num = va_arg(*ap, unsigned long);
				format_hex(buf, &n, size, num, &fmt, (*format == 'X'));
				break ;
			case 'u':
				unsigned long num = va_arg(*ap, unsigned long);
				format_unsigned(buf, &n, size, num, &fmt);
				break ;
			case 'c':
				char ch = (char)va_arg(*ap, int);
				format_char(buf, &n, size, ch, &fmt); /* 支持宽度和对齐 */
				break ;
			case 's':
				char *str = va_arg(*ap, char*);
				format_string(buf, &n, size, str, &fmt); /* 支持宽度和精度 */
				break ;
			case'p':
				void *ptr = va_arg(*ap, void*);
				format_pointer(buf, &n, size, ptr, &fmt); /* 支持宽度和对齐 */
				break ;
			case '%':
				format_char(buf, &n, size, '%', &fmt); /* 支持宽度和对齐 */
				break ;
			default:
				return (-1);
		}
		format++;
	}
	buf[n] = '\0';
	return (n);
}
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*buf;
	int	ret;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (-1);
	va_start(ap, format);
	ret = ft_vsnprintf(buf, BUFFER_SIZE, format, ap);
	va_end(ap);
	if (ret > 0)
		ret = write(1, buf, ret);
	free(buf);
	return (ret);
}
