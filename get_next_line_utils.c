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

size_t	ft_strlen(const char *str)
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
