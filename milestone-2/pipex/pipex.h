#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_files {
    char    *in;
    char    *out;
}   t_files;

int get_files(int argc, char **argv, t_files *files);
char    **get_cmds(int argc, char **argv);

#endif
