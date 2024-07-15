/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:09:11 by girts             #+#    #+#             */
/*   Updated: 2024/07/12 16:41:31 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void free_all(char *buffer, char *remaining, char *line)
{
	if (line)
		free(line);
	if (buffer)
		free(buffer);
	if (remaining)
		free(remaining);
	
}

char    *get_next_line(int fd)
{
	static char	*remaining;
	int			bytes_read;
	char		*buffer;
	char        *line;
	int			i;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	remaining = NULL;
	line = NULL;
	bytes_read = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
	while(1)
	{
		if (remaining)
		{
			temp = ft_strjoin(line, remaining);
			if (temp == NULL)
			{
				free_all(buffer, remaining, line);
				return (NULL);
			}
			free(line);
			line = NULL;
			free(remaining);
			remaining = NULL;
			line = temp;
			temp = NULL;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0 && !line)
    	{
			free_all(buffer, remaining, line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(line, buffer);
		if (temp == NULL)
		{
			free_all(buffer, remaining, line);
			return (NULL);
		}
		free(line);
		line = NULL;
		line = temp;
		temp = NULL;
		i = 0;
		temp = ft_strchr(line, '\n');
		if (temp)
		{
			if (*temp + 1)
			{
				remaining = (char *)malloc(ft_strlen(temp + 1) + 1);
				if (!remaining)
				{
					free_all(buffer, remaining, line);
					return (NULL);
				}
				ft_strlcpy(remaining, temp + 1, ft_strlen(temp + 1));
			}
			*temp = '\0';
			temp = NULL;
			free(buffer);
			
			return (line);
		}
	}
}





// char    *get_next_line2(int fd)
// {
//     static char    *remaining = NULL;
//     char        *buffer;
//     char        *line;
//     int            bytes_read;
//     size_t        i;
//     char        *temp;
	
// 	line = NULL;
//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
//     buffer = malloc(BUFFER_SIZE + 1);
//     if (!buffer)
//         return (NULL);
//     while (1)
//     {
//         if (remaining)
//         {
//             line = ft_strjoin(line, remaining);
// 			if (line == NULL)
// 				return (NULL);
//             free(remaining);
//             remaining = NULL;
//         }
//         i = 0;
//         while (line && line[i])
//         {
//             if (line[i] == '\n')
//             {
//                 temp = remaining;
//                 remaining = ft_strjoin(NULL, line + i + 1);
// 				if (remaining == NULL)
// 					return (NULL);
//                 free(temp);
//                 line[i + 1] = '\0';
//                 free(buffer);
//                 return (line);
//             }
//             i++;
//         }
//         bytes_read = read(fd, buffer, BUFFER_SIZE);
//         if (bytes_read <= 0)
//             break ;
//         buffer[bytes_read] = '\0';
//         line = ft_strjoin(line, buffer);
// 		if (line == NULL)
// 			return (NULL);
//     }
//     free(buffer);
//     if (bytes_read < 0 || (bytes_read == 0 && (!line || !line[0])))
//     {
//         free(line);
//         return (NULL);
//     }
//     return (line);
// }










// void	get_len(size_t *len1, size_t *len2, char *s1, char *s2)
// {
// 	if (s1)
// 		*len1 = ft_strlen(s1);
// 	if (s2)
// 		*len2 = ft_strlen(s2);
// }

// void	first_res_loop(char *res, char *s1, size_t i, size_t len1)
// {
// 	while (i < len1)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	char	*res;
// 	size_t	i;

// 	len1 = 0;
// 	len2 = 0;
// 	i = 0;
// 	get_len(&len1, &len2, s1, s2);
// 	res = (char *)malloc(len1 + len2 + 1);
// 	if (!res)
// 		return (NULL);
// 	first_res_loop(res, s1, i, len1);
// 	i = 0;
// 	while (i < len2)
// 	{
// 		res[len1 + i] = s2[i];
// 		i++;
// 	}
// 	res[len1 + len2] = '\0';
// 	free(s1);
// 	return (res);
// }