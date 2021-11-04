#include "../../minishell.h"

int get_size_of_table(char **table)
{
    int i;

    i = 0;
    while (table[i])
        i++;
    return (i);
}
