#include "../../minishell.h"

void	add_simple_cmd_to_pipeline(t_ast *s_parent, t_ast *s_child)
{
	t_ast	*s_next_child;

	if (!s_parent->child_cmd)
		s_parent->child_cmd = s_child;
	else
	{
		s_next_child = s_parent->child_cmd;
		while (s_next_child->child_cmd)
			s_next_child = s_next_child->child_cmd;
		s_next_child->child_cmd = s_child;
	}
}
