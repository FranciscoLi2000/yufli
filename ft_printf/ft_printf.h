#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct
{
	int	left_align;    /* '-' */
	int	zero_pad;      /* '0' */
	int	prefix;        /* '#' */
	int	space;         /* ' ' */
	int	plus;          /* '+' */
	int	width;         /* 字段宽度（静态或动态）*/
	int	precision;     /* 精度（静态或动态）*/
	int	is_short;      /* 'h' */
	int	is_long;       /* 'l' 或 'll' */
}	t_format;

int	ft_printf(const char *format, ...);
void	ft_htoa(char *buf, int *n, int size, unsigned long num, int uppercase);
void	ft_htoa_pre(char *buf, int *n, int size, unsigned long num, int uppercase);
void	ft_itoa(char *buf, int *n, int size, long num);
void	ft_utoa(char *buf, int *n, int size, unsigned long num);
void	ft_stoa(char *buf, int *n, int size, char *str);

void	format_integer(char *buf, int *n, int size, long num, t_format *fmt);

#endif
