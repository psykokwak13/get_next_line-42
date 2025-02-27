/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:43:21 by egatien           #+#    #+#             */
/*   Updated: 2025/01/17 10:09:35 by egatien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif
// # define malloc(...) NULL
# include <stdlib.h>

char	*ft_strjoin(char	*s1, char const		*s2);
char	*get_next_line(int fd);
int		readfile(char	*buffer, int fd);
char	*cutstringwhen_n(char	*line);
void	decalebuffer(char	*buffer);
char	*ft_strcpy(char	*dest, char	*src);
char	*ft_strchr(const char	*s, int c);

#endif
