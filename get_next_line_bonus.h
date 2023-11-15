/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:31:36 by plgol.perso       #+#    #+#             */
/*   Updated: 2023/11/15 11:31:37 by plgol.perso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	gnl_strlen(char *str);
void	*gnl_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*gnl_advance(int fd, char *prev);
char	*gnl_search(char *str, int ch);
char	*gnl_join(char *prev, char *curr);
char	*gnl_produce(char *prev);
char	*gnl_consume(char *prev);

#endif
