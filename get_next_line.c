#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	check_line(char buffer);

char	*get_next_line(int fd)
{
	int		i;
	int		j;
	char	*buffer;
	char	*res;
	int		size;
	int		siz;
	//300 = BUFFER_SIZE
	i = 0;
	j = 0;
	size = 1;
	buffer = malloc(sizeof(char) * 300 + 1);
	while (j < 300)
	{
		printf("%d\n", size);
		size += read(fd, buffer, 1);
		res = malloc(1 * size);
		if (res[j] == '\n')
			return (res);
		res[j] = buffer[j];
		printf("buff >> %c\n", res[j]);
		j++;
	}
	if (!buffer)
		return (NULL);
	res = malloc(sizeof(char) * size);
	buffer[size] = 0;
	if (!res)
		return (NULL);
	while (buffer[i])
	{
		//printf("%c", buffer[i]);
		res[i] = buffer[i];
		if (check_line(buffer[i]))
			return (res);
		i++;
	}
}

int	check_line(char buffer)
{
	int		i;

	i = 0;
	if (buffer == '\n')
		return (1);
	return (0);
}

int	check_buff(char *buffer, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		
	}
	return (i);	
}

int	main(void)
{
	int	fd;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (i < 40)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
