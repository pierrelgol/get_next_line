/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:31:03 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/15 11:31:04 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stddef.h>

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*temp;
	size_t	total;

	if (!count || !size)
		return (malloc(0));
	if (count > INT_MAX / size)
		return (NULL);
	total = (size * count);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	temp = ptr;
	while (temp < ((char *)ptr + total))
		*temp++ = 0;
	return (ptr);
}

size_t	gnl_strlen(char *str)
{
	char	*pstr;

	if (!str)
		return (0);
	pstr = str;
	while (*pstr && *(pstr + 1) && *(pstr + 2) && *(pstr + 3))
		pstr += 4;
	while (*pstr)
		++pstr;
	return (pstr - str);
}

char	*gnl_search(char *str, int ch)
{
	if (!str)
		return (NULL);
	if (ch == '\0')
		return ((char *)&str[gnl_strlen(str)]);
	while (*str)
	{
		if (*str == (char)ch)
			return (str);
		++str;
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
	newln = gnl_calloc(rlen + 1, sizeof(char));
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
