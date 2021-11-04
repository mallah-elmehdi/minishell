#include "../../minishell.h"

void	fill_table_of_redir(t_ast *s_cmd, t_token **s_redir, t_token **s_filename, char **table_of_env_var)
{
    // t_redir *redir_table;
    // t_redir **new_redir_table;
    // char    *str;
    // int     i;

    // redir_table = malloc(sizeof(t_redir *));
    // redir_table = init_redir(s_redir->type, str);
    // // get_redir_of_simple_command();
    // if (s_cmd->redir == NULL)
    // {
    //     s_cmd->redir = (t_redir *)malloc(sizeof(t_redir *) * 2);
    //     s_cmd->redir[0] = redir_table;
    //     s_cmd->redir[1] = NULL;
    // }
    // else
    // {
    //     i = get_size_of_table(s_cmd->redir);
    //     new_redir_table = (t_redir *)malloc(sizeof(t_redir *) * (i + 2));
    //     ft_memcpy(new_redir_table, redir_table, i);
    //     new_redir_table[i] = redir_table;
    //     new_redir_table[i + 1] = NULL;
    //     //free_double_table(s_cmd->redir);
    //     s_cmd->redir = new_redir_table;
    // }
}
