# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
# define BUFFER_SIZE 3

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (s2);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = 0;
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*output(char *str)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (str[i] != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 2));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\n';
	ret[i + 1] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	static char	*storage = NULL;

	while (1)
	{
		if (storage != NULL)//前回リードに残りあるか
		{
			if (ft_strchr(storage, '\n') == NULL)//前回リード内に残り改行なければ
			{
				line = ft_strdup(storage);//今回出力分
			}
			else 
			{
				line = output(storage);//長いヤツの中から改行までの文字列だけ返す
				return (line);
			}
		}
		read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n') != NULL)
		{
			line = ft_strjoin(line, output(buf));
			storage = ft_strdup(ft_strchr(buf, '\n') + 1);
			return (line);
		}
	
	}
}


int	main(void)
{
	int	fd = open("./test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}