
void	format_pointer(char *buf, int *n, int size, void *ptr, t_format *fmt)
{
	unsigned long addr = (unsigned long)ptr;
	/* 写入前缀 "0x" */
	ft_stoa(buf, n, size, "0x");
	/* 格式化地址为十六进制 */
	format_hex(buf, n, size, addr, fmt, 0);
}
