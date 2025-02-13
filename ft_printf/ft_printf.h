#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
void	ft_htoa(char *buf, int *n, int size, unsigned long num, int uppercase);
void	ft_htoa_pre(char *buf, int *n, int size, unsigned long num, int uppercase);
void	ft_itoa(char *buf, int *n, int size, long num);
void	ft_utoa(char *buf, int *n, int size, unsigned long num);
void	ft_stoa(char *buf, int *n, int size, char *str);

#endif
