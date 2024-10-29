#include "minishell.h"

void check_parag(char **args)
{
    char *start_quote;
    char *end_quote;

    if (*args[0] == '"')
    {
        start_quote = ft_strchr(*args, '"');
        if (start_quote)
            ft_memmove(start_quote, start_quote + 1, ft_strlen(start_quote));
        end_quote = ft_strrchr(*args, '"');
        if (end_quote)
            *end_quote = '\0';
    }
}

int fd_echo(char *input)
{
    int i = 0;
    int j = 0;
    char **args;
    char *filename;

    args = fft_split(input);
    while (args[i])
    {
        if (ft_strstr(args[i], ">>") && args[i][0] != '"' && args[i][ft_strlen(args[i]) - 1] != '"')
        {

            if (ft_strstr(args[i], ">>\0"))
                filename = args[++i];
            else
                filename = ft_strstr(args[i], ">>\0") + 2;
            int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (file == -1)
            {
                perror("can not create file");
                return (1);
            }
            while (args[j])
            {
                if (!(ft_strstr(args[j], ">>")) && j != i)
                {
                    check_parag(&args[j]);
                    write(file, args[j], ft_strlen(args[j]));
                    write(file, " ", 1);
                }
                j++;
            }
            close(file);
            return (0);
        }
        i++;
    }
    i = 0;
    while (args[i])
    {
        check_parag(&args[j]);
        printf("%s ", args[i]);
        i++;
    }
    printf("\n");
    return (0);
}