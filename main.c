/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:40:15 by girts             #+#    #+#             */
/*   Updated: 2024/07/13 11:04:42 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("multiple_nlx5", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file.\n");
		return (1);
	}
	line = get_next_line(fd);
	// printf("line: %s", line);
	while (line)
	{
		// printf("here\n");
		printf("%s", line);
		// printf("\n");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
