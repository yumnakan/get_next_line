/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumnakan <robynmao@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:30:02 by yumnakan          #+#    #+#             */
/*   Updated: 2023/03/26 22:51:00 by yumnakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# define BUFFER_SIZE 4

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	static char	*store = NULL;
	size_t	i;
	
	i = 0;
	while (read(fd, buf, BUFFER_SIZE) != -1)
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
				store[BUFFER_SIZE + i]
				
		}
			
		
	}
	
	//ssize_t read(int fd, void *buf, size_t count);
	//fd から最大countバイトをbufに読み込む、読み込んだバイト数が返る
	return (NULL);
}

int	main(void)
{
	int	fd = open("./test", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}

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