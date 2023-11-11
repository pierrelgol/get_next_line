/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:36:23 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/07 23:36:24 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line_buff;
	char		*next_line;
	int			len;
	int			size;

	len = 0;
	size = BUFFER_SIZE;
	line_buff = (char[BUFFER_SIZE + 1]){0};
	if (fd < 0)
		return (NULL);
	while (read(fd, &line_buff[len], 1) == 1)
	{
		if (line_buff[len] == '\n' || line_buff[len] == 0)
			break ;
		len++;
	}
	if (len >= 0)
	{
		next_line = malloc(len + 1);
		len = 0;
		while (*line_buff)
			next_line[len++] = *line_buff++;
		next_line[len] = '\0';
		return (next_line);
	}
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 	// int	count;
// 	int	fd;
// 	char	*ln;

// 	// count = 1;
// 	fd = 0;
// 	ln = NULL;
// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		ln = get_next_line(fd);
// 		while (ln != NULL)
// 		{
// 			// printf("[%d]%s\n",count++,ln);
// 			if (ln)
// 				free(ln);
// 			ln = get_next_line(fd);
// 		}
// 	}
// 	else
// 	{
// 		fd = 0;
// 		ln = get_next_line(fd);
// 		while (ln != NULL)
// 		{
// 			// printf("[%d]%s\n",count++,ln);
// 			if (ln)
// 				free(ln);
// 			ln = get_next_line(fd);
// 		}
// 	}
// 	return (0);
// }
