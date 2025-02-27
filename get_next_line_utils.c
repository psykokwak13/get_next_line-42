/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:43:34 by egatien           #+#    #+#             */
/*   Updated: 2024/12/06 10:15:33 by egatien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/get_next_line.h"
#include <unistd.h>

static size_t	ft_strlen(const char *str)
{
	size_t	nbr;

	nbr = 0;
	if (str == NULL)
		return (nbr);
	while (str[nbr] != '\0')
		nbr++;
	return (nbr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int			i;
	int			j;
	size_t		total;
	char		*result;

	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2)+1;
	result = malloc(total * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

int	readfile(char *buffer, int fd)
{
	int	readcheck;

	readcheck = (int)read(fd, buffer, BUFFER_SIZE);
	if (readcheck > 0)
		buffer[readcheck] = '\0';
	return (readcheck);
}

char	*cutstringwhen_n(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

void	decalebuffer(char *buffer)
{
	int		i;
	char	*newline_ptr;

	i = 0;
	newline_ptr = ft_strchr(buffer, '\n');
	if (newline_ptr)
	{
		newline_ptr++;
		while (newline_ptr[i])
		{
			buffer[i] = newline_ptr[i];
			i++;
		}
		buffer[i] = '\0';
	}
	else
		buffer[0] = '\0';
}
