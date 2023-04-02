/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumnakan <robynmao@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:30:02 by yumnakan          #+#    #+#             */
/*   Updated: 2023/04/02 14:04:14 by yumnakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
# define BUFFER_SIZE 5

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
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

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*current;
	static char	*next = "aaa\nbbb";
	// size_t	i;
	// static size_t	last_n = 0;
	
	if (next != NULL)//前回リードに残りあるか
	{
		if (ft_strchr(next, '\n') == NULL)//前回リード内に残り改行なければ
		{
			current = ft_strdup(next);//今回出力分
		}
		else 
		{
			current = output(next);//長いヤツの中から改行までの文字列だけ返す
			// next = 
			return (current);
		}
	}
	return ("zzz");
	while (read(fd, buf, BUFFER_SIZE) != -1)
	{
		if (ft_strchr(buf, '\n') != NULL)
		{
			current = join(current, output());
			next = ft_strchr(buf, '\n') +1;
		}
		while (ft_strchr(buf, '\n') == NULL)
		{
			
			read(fd, output, BUFFER_SIZE);
		}
		ft_strchr(output, '\n')
	}

}
int main()
{
	printf("%s", get_next_line(1));
	// get_next_line(1);
	// return (1);
}

// 				ft_strjoin(keep, ft_strdup((const char*)buf))
// 					// return ("end");
// 					return (ft_strjoin(keep, ft_strdup((const char*)buf)));
// 				}
// 				i++;
// 			}
// 			buf[i] = '\0';
// 			keep = ft_strjoin(keep, ft_strdup((const char*)buf));
// 			return("done");
			
// if (i < BUFFER_SIZE - 1) //\n のあともなんかある
// {
// 	ret = ft_strjoin(keep, make_ret(buf, i));
// 	keep = make_keep(buf, i);
// }
// else if (i == BUFFER_SIZE - 1)//\n ちょうど終わる
// {
// 	ret = make_ret(buf, i);
// }
// else if (i == BUFFER_SIZE)//\n なし
// {
// 	keep = ft_strjoin(keep, make_keep(buf, i));
// }

// int	main(void)
// {
// 	int	fd = open("./test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	return (0);
// }

//ssize_t read(int fd, void *buf, size_t count);
//fd から最大countバイトをbufに読み込む、読み込んだバイト数が返る

/*
Return Value:
Read line: correct behavior
NULL: there is nothing else to read, or an error occurred

External functs:
read, malloc, free

Description:
Write a function that returns a line read from a file descriptor

• Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.

• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.

• Make sure that your function works as expected both when reading a file and when
reading from the standard input.

• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.

• Add all the helper functions you need in the get_next_line_utils.c file.

*/