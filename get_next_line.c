/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:43:14 by egatien           #+#    #+#             */
/*   Updated: 2025/01/17 16:33:50 by egatien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*result;

	result = s;
	while (n--)
	{
		*result++ = (unsigned char) c;
	}
	return (s);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dupli;

	i = 0;
	while (src[i] != '\0')
		i++;
	dupli = malloc(i * sizeof(char) + 1);
	if (dupli == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dupli[i] = src[i];
		i++;
	}
	dupli[i] = '\0';
	return (dupli);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cha;

	cha = (unsigned char)c;
	while (*s)
	{
		if (*s == cha)
			return ((char *) s);
		s++;
	}
	if (cha == '\0')
		return ((char *)s);
	return (NULL);
}

char	*read_until_newline(int fd, char *buffer, int *readcheck)
{
	char	*line;
	char	*temp;

	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		*readcheck = readfile(buffer, fd);
		if (*readcheck <= 0)
			break ;
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			readcheck;

	if (fd == -1)
		return (NULL);
	readcheck = 0;
	line = read_until_newline(fd, buffer, &readcheck);
	if (readcheck <= 0 && buffer[0] == '\0')
	{
		if (line)
			free(line);
		return (NULL);
	}
	decalebuffer(buffer);
	cutstringwhen_n(line);
	return (line);
}

// int main ()
// {
// 	int fd;
// 	char *test;
// 	fd = 0;
// 	fd = open("test.txt", O_RDONLY);
// //get_next_line(fd);

// 	test = get_next_line(fd);
// 	printf("1 :%s",test);
// 	free(test);
// 	test = get_next_line(fd);
// 	printf("2 :%s",test);
// 	free(test);
// 	test = get_next_line(fd);
// 	printf("3 :%s",test);
// 	free(test);
// 	test = get_next_line(fd);
// 	printf("4 :%s",test);
// 	free(test);
// 	test = get_next_line(fd);
// 	printf("5 :%s",test);
// 	free(test);
// 	test = get_next_line(fd);
// 	printf("6 :%s",test);
// 	free(test);

// 	close(fd);
// }
