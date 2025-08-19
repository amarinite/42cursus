#include "libft/libft.h"
#include "pipex.h"

char    **get_path(char **envp)
{
    char    *string_path;
    char    **path;

    path = NULL;
    while (*envp)
    {
        if(ft_strncmp("PATH=", *envp, ft_strlen("PATH=")) == 0)
        {
            string_path = *envp + 5;
            break ;
        }
        envp++;
    }
    path = ft_split(string_path, ':');
    // free when called
    return (path);
}

int get_files(int argc, char **argv, t_files *files)
{
    if (access(argv[1], R_OK) < 0 && access(argv[argc - 1], W_OK))
    {
        files->in = argv[1];
        files->out = argv[argc - 1];
        return (1);
    }
    return (0);
}

char    **get_cmds(int argc, char **argv)
{
    int     i;
    char    **cmds;

    i = 3;
    cmds = malloc((argc - 2) * sizeof(char *));
    if(!cmds)
        return (NULL);
    while (i < argc - 3)
    {
        cmds[i] = argv[i + 2];
        i++;
    }
    cmds[i] = NULL;
    return (cmds);
}
