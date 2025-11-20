#ifndef BROKEN_GNL
# define BROKEN_GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif
