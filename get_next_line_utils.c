/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:08:02 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/14 21:08:03 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stddef.h>

void	gnl_bzero(void *s, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	*ptr_end;

	ptr_s = (unsigned char *)s;
	ptr_end = (unsigned char *)s + n;
	while (ptr_s < ptr_end)
		*ptr_s++ = 0;
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!count || !size)
		return (malloc(0));
	if (count > INT_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	gnl_bzero(ptr, (count * size));
	return (ptr);
}

size_t	gnl_strlen(char *str)
{
	char	*pstr;

	if (!str)
		return (0);
	pstr = str;
	while (*pstr)
		++pstr;
	return (pstr - str);
}

char	*gnl_search(char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (ch == '\0')
		return ((char *)&str[gnl_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*gnl_join(char *prev, char *curr)
{
	char	*newln;
	size_t	rlen;
	size_t	i;

	if (!prev)
		prev = gnl_calloc(1, sizeof(char));
	if (!prev || !curr)
		return (NULL);
	rlen = gnl_strlen(prev) + gnl_strlen(curr);
	newln = malloc(sizeof(char) * (rlen + 1));
	if (newln == NULL)
		return (NULL);
	i = -1;
	if (prev)
		while (prev[++i] != '\0')
			newln[i] = prev[i];
	while (*curr)
		newln[i++] = *curr++;
	newln[rlen] = '\0';
	free(prev);
	return (newln);
}
