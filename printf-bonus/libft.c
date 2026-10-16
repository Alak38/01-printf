// #include "ft_printf.h"

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		*(char *)(s + i) = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*buffer;
// 	size_t	total;

// 	if (size == 0 || count == 0)
// 		return (malloc(0));
// 	total = size * count;
// 	if (total / count != size)
// 		return (NULL);
// 	buffer = malloc (count * size);
// 	if (buffer == NULL)
// 		return (NULL);
// 	ft_bzero(buffer, (count * size));
// 	return (buffer);
// }

// int	ft_isalpha(int c)
// {
// 	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
// 		return (1);
// 	else
// 		return (0);
// }

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	else
// 		return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == c)
// 		return ((char *)&s[i]);
// 	return (0);
// }

// int	ft_atoi(const char *str)
// {
// 	int	result;
// 	int	sign;

// 	result = 0;
// 	sign = 1;
// 	while ((*str == 32) || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '-')
// 	{
// 		sign = -1;
// 		str++;
// 	}
// 	else if (*str == '+')
// 		str++;
// 	while (*str == 48)
// 		str++;
// 	while (*str && (*str >= 48 && *str <= 57))
// 	{
// 		result = result * 10 + (str[0] - 48);
// 		str++;
// 	}
// 	return (result * sign);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	uc1;
// 	unsigned char	uc2;

// 	i = 0;
// 	while (i < n)
// 	{
// 		uc1 = (unsigned char)s1[i];
// 		uc2 = (unsigned char)s2[i];
// 		if (uc1 != uc2)
// 			return (uc1 - uc2);
// 		if (uc1 == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	unsigned char	*str1;
// 	unsigned char	*str2;

// 	str1 = (unsigned char *) s1;
// 	str2 = (unsigned char *) s2;
// 	while (n-- > 0)
// 	{
// 		if (*str1 != *str2)
// 			return (*str1 - *str2);
// 		str1++;
// 		str2++;
// 	}
// 	return (0);
// }
