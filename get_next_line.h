/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:19:59 by girts             #+#    #+#             */
/*   Updated: 2024/07/19 21:54:55 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct data_s
{
	char	*buffer;
	char	*line;
	int		bytes_read;
	size_t	line_len;
	size_t	buffer_len;
}	t_data;

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr( char *s, int c);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_realloc(char *ptr, size_t size);
int		handle_buffer(t_data *data, char	**newline_pos);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
