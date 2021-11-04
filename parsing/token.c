#include "../minishell.h"

t_token *init_token(int type, char *value)
{
	t_token *s_token;

	s_token = malloc(sizeof(t_token));
	s_token->type = type;
	s_token->value = value;
	return (s_token);
}
