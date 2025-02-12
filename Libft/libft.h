#ifndef LIBFT_H
# define LIBFT_H

/* 检查字符类型的函数，参数通常为 int 类型的字符值（通常用 unsigned char 转换后再传入），返回值非零表示真，0 表示假 */
int	ft_isalnum(int c);   /* 判断是否为字母或数字 */
int	ft_isalpha(int c);   /* 判断是否为字母 */
int	ft_isdigit(int c);   /* 判断是否为数字 */
int	ft_isprint(int c);   /* 判断是否为可打印字符，包括空格 */
int	ft_isascii(int c);   /* 判断是否为ASCII符号 */
/* 字符大小写转换函数 */
int	ft_tolower(int c);   /* 将字符转换为小写 */
int	ft_toupper(int c);   /* 将字符转换为大写 */
#include <stddef.h>  /* 定义 size_t 类型 */
/* 内存操作函数 */
/* 将内存块 src 中的前 n 个字节复制到内存块 dest 中，注意：src 和 dest 不可重叠，否则应使用 memmove */
void	*ft_memcpy(void *dest, const void *src, size_t n);
/* 将内存块 src 中的前 n 个字节复制到内存块 dest 中，支持重叠的内存块 */
void	*ft_memmove(void *dest, const void *src, size_t n);
/* 将内存块 s 的前 n 个字节设置为指定的值 c */
void	*ft_memset(void *s, int c, size_t n);
/* 比较内存块 s1 和 s2 的前 n 个字节，返回值：<0 表示 s1 小于 s2，0 表示相等，>0 表示 s1 大于 s2 */
int	ft_memcmp(const void *s1, const void *s2, size_t n);
/* 在内存块 s 中搜索第一个值为 c 的字节，返回该字节的指针，如果未找到，则返回 NULL */
void	*ft_memchr(const void *s, int c, size_t n);
/* 字符串操作函数 */
/* 计算字符串 s 的长度，不包括末尾的空字符 '\0' */
size_t	ft_strlen(const char *s);
/* 比较两个字符串 s1 和 s2 的前 n 个字符 */
int	ft_strncmp(const char *s1, const char *s2, size_t n);
/* 在字符串 s 中查找第一次出现的字符 c，返回该字符在字符串中的位置（指针），未找到则返回 NULL */
char	*ft_strchr(const char *s, int c);
/* 在字符串 s 中查找最后一次出现的字符 c */
char	*ft_strrchr(const char *s, int c);
/* 在字符串 haystack 中查找子字符串 needle，返回第一次出现的子字符串的指针，未找到则返回 NULL */
char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len);
/* 内存分配与释放函数 */
/* 分配一块内存用于存储 num 个元素，每个元素大小为 size 字节，并将分配到的内存初始化为零 */
void	*ft_calloc(size_t num, size_t size);
/* 字符串与数值转换函数 */
/* 将字符串转换为 int 类型数值 */
int	ft_atoi(const char *nptr);
/* 将内存块（字符串）的前n个字节清零 */
void	ft_bzero(void *s, size_t n);
/* 将 src 字符串复制到 dst 中，最多复制 dstsize-1 个字符，并在末尾添加 '\0'。返回值为 src 的长度（不包括终止的 '\0'）。 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/* 将 src 字符串追加到 dst 字符串的末尾，最多追加 dstsize - strlen(dst) - 1 个字符，并在末尾添加 '\0'。返回值为 dst 原始字符串长度加上 src 的长度，即理论上最终字符串的长度。 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/* 分配足够空间并复制参数 s 指向的字符串，返回新字符串的指针。如果分配失败，则返回 NULL。 */
char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}			t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
# define FD_MAX 1024
# endif

char	*get_next_line(int fd);

#endif
