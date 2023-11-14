/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:07:07 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/14 21:07:08 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*curr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev = gnl_advance(fd, prev);
	if (!prev)
		return (NULL);
	curr = gnl_produce(prev);
	prev = gnl_consume(prev);
	return (curr);
}

char	*gnl_advance(int fd, char *prev)
{
	char	*curr;
	int	count;

	curr = gnl_calloc((BUFFER_SIZE + 1) ,sizeof(char));
	if (!curr)
		return (NULL);
	count = 1;
	while (!gnl_search(prev, '\n') && count)
	{
		count = read(fd, curr, BUFFER_SIZE);
		if (count == -1)
		{
			free(curr);
			return (NULL);
		}
		curr[count] = '\0';
		prev = gnl_join(prev, curr);
	}
	free(curr);
	return (prev);
}

char	*gnl_produce(char *prev)
{
	char	*line;
	int		i;

	i = 0;
	if (!*prev)
		return (NULL);
	while (prev[i])
		if (prev[i++] == '\n')
			break;
	line = gnl_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i ^= i;
	while (prev[i] && prev[i] != '\n')
	{
		line[i] = prev[i];
		i++;
	}
	if (prev[i] == '\n')
		line[i] = prev[i];
	return (line);
}

char	*gnl_consume(char *prev)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (prev[i] && prev[i] != '\n')
		i++;
	if (!prev[i])
	{
		free(prev);
		return (NULL);
	}
	next = gnl_calloc(gnl_strlen(prev) - i + 1, sizeof(char));
	if (!next)
		return (NULL);
	while (prev[++i])
		next[j++] = prev[i];
	free(prev);
	return (next);
}
