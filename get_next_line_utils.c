#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb > 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (!(c <= 127 && c >= 0))
		return ((char *)str);
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (NULL);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}