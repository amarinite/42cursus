#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
    t_files files;
    char    **cmds;

    if (argc < 5)
        return (1);
    if(!get_files(argc, argv, &files))
        return (1);
    cmds = get_cmds(argc, argv);
    /*
    int i = 0;

        printf("Command-line arguments:\n");
        for (i = 0; i < argc; i++) {
            printf("argv[%d] = %s\n", i, argv[i]);
        }

        printf("\nEnvironment variables:\n");
        i = 0;
        while (envp[i] != NULL) {
            printf("envp[%d] = %s\n", i, envp[i]);
            i++;
        }
        */
}
