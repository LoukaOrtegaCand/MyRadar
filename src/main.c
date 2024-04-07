/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main for my_radar
*/

#include "my_radar.h"

int errors(int argc, char **argv, char **envp)
{
    if (argc != 2)
        return (84);
    if (envp == NULL)
        return (84);
    if (open(argv[1], O_RDONLY) == -1) {
        my_printf("the script file can't be found with the path provided");
        return (84);
    }
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "DISPLAY=", 7) == 0)
            return (0);
    }
    return (84);
}

int help(char **argv)
{
    char str[] = "Air traffic simulation panel\n\nUSAGE\n ./my_radar "
    "[OPTIONS] path_to_script\n  path_to_script    The path to the script"
    " file.\n\nOPTIONS\n -h\t\t   print the usage and quit.\n\nUSER "
    "INTERACTIONS\n 'L' key\tenable/disable hitboxes and areas.\n 'S' "
    "key\tenable/disable sprites.";

    if (my_strcmp(argv[1], "-h") == 0) {
        my_printf("%s", str);
        return (1);
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    all_t *all = malloc(sizeof(all_t));
    sfVideoMode video_mode = {1920, 1080, 32};

    all->screen = 0;
    if (errors(argc, argv, envp) == 84)
        return (84);
    if (help(argv) == 1)
        return (0);
    recup(all, argv);
    init(all);
    all->window = SRWC(video_mode, "MyRadar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(all->window, 60);
    setwindow(all);
    destroy_all(all);
    free_all(all);
    return (0);
}
