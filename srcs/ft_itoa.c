#include "libft.h"
#include <stdlib.h>
char	*ft_itoa(int n)
{
	char	*str;
	char	temp;
	int	i;
	int	isNegative;
	int	base;
	int	rem;
	int	start;
	int	end;

	i = 0;
	isNegative = 0;
	base = 10;
	/* 处理负数，只有在十进制下才需要考虑负号 */
	if (n < 0)
	{
		isNegative = 1;
		n = -n;/* 将负数转为正数 */
	}
	/* 处理 0 特殊情况 */
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	/* 将整数转换为字符串 */
	while (n != 0)
	{
		rem = n % base;
		if (rem > 9)
			str[i++] = (rem - 10) + 'a';
		else
			str[i++] = rem + '0';
		n = n / base;
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	/* 反转字符串 */
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
