#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define UNUSED_ARGUMENT(x) ((void)(x))

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "fcntl.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* ----------------------------- get_next_line.c ---------------------------- */

char	*get_next_line(int fd);
int		gnl_init(int fd);
int		gnl_read(int fd);
int		gnl_fill(void);
int		gnl_clean(void);
int		gnl_flush(void);

/* ----------------------------- get_next_line_utils.c ---------------------- */

#endif
