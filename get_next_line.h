/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:07:45 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/14 21:07:46 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	gnl_strlen(char *str);
void	gnl_bzero(void *src, size_t n);
void	*gnl_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*gnl_advance(int fd, char *prev);
char	*gnl_search(char *str, int ch);
char	*gnl_join(char *prev, char *curr);
char	*gnl_produce(char *prev);
char	*gnl_consume(char *prev);

#endif
