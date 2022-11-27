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

char	*ft_this_line(char	*buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] == '\n';
	return (line);
}


char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
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

/*
void	*ft_realloc(void *ptr, size_t new_size)
{
	char	*new;
	size_t	size;

	size = sizeof(ptr);
	if (new_size <= size)
		return (ptr);
	new = malloc(new_size + 1);
	while (size--)
		*(char *)new++ = *(char *)ptr++;
	free(ptr);
	return (new);
}
*/

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

char	*reajoin(char *buffer, char *res)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, res);
	free(buffer);
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc((size + 1), 1);
	if (!str || !s1 || !s2)
		return (NULL);
	//write(1, "check", 5);
	i = 0;
	//printf("\n[%s]\n", s2);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[size] = 0;
	return (str);
}

char	*ft_read(int fd, char *res)
{
	int		j;
	int			i;
	int			size;
	char	*buffer;
	//300 = BUFFER_SIZE
	j = 0;
	i = 0;
	size = 1;
	buffer = ft_calloc(301, 1);
	if (!res)
		res = ft_calloc(1, 1);
	while (size != 0)
	{
		size = read(fd, buffer, 300);
		res = reajoin(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	//printf("%s", res);
	free(buffer);
	return (res);
}
char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;

	buffer = ft_read(fd, buffer);
	//printf("%s", buffer);
	if (!buffer)
		return (NULL);
	line = ft_this_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

int	main(void)
{
	int	fd;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	//printf("%d", fd);
	//write(fd, "Hello", 4);
	while (i < 18)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
