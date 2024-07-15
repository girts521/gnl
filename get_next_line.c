/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:20:19 by girts             #+#    #+#             */
/*   Updated: 2024/07/12 20:13:18 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


static void free_all(char **buffer, char **line, char **remaining)
{
    if (buffer && *buffer)
    {
        free(*buffer);
        *buffer = NULL;
    }
    if (line && *line)
    {
        free(*line);
        *line = NULL;
    }
    if (remaining && *remaining)
    {
        free(*remaining);
        *remaining = NULL;
    }
}



char    *get_next_line(int fd)
{
	static char	*remaining = NULL;
	int			bytes_read;
	char		*buffer;
	char        *line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	temp = NULL;
	line = NULL;
	bytes_read = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
	{
		free_all(&buffer, &line, &remaining);
		return (NULL);
	}
	while(1)
	{
		if (remaining)
		{
			if (line)
				temp = ft_strjoin(line, remaining);
			else if (line == NULL)
				temp = ft_strdup(remaining);
			if (temp == NULL)
			{
				free_all(&buffer, &line, &remaining);
				return (NULL);
			}
			free(line);
			free(remaining);
			remaining = NULL;
			line = temp;
			temp = NULL;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		if (line)
			temp = ft_strjoin(line, buffer);
		else if (line == NULL)
			temp = ft_strdup(buffer);
		if (temp == NULL)
		{
			free_all(&buffer, &line, &remaining);
			return (NULL);
		}
		free(line);
		line = temp;
		temp = NULL;
		temp = ft_strchr(line, '\n');
		if (temp)
		{
			if (*(temp + 1))
			{
				remaining = (char *)malloc(ft_strlen(temp + 1) + 1);
				if (!remaining)
				{
					free_all(&buffer, &line, &remaining);
					return (NULL);
				}
				ft_strlcpy(remaining, temp + 1, ft_strlen(temp + 1) + 1);
			}
			temp = temp + 1;
			*temp = '\0';
			temp = NULL;
			free(buffer);
			buffer = NULL;
			return (line);
		}
	}
	if (!line)
	{
		free_all(&buffer, &line, &remaining);
		return (NULL);
	}
	free(buffer);
	buffer = NULL;
	return (line);
}
