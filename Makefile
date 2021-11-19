NAME = minishell

FLAG = -Wall -Wextra -Werror

EXECUTION = execution/init/init_env.c\
			execution/init/init_env_export.c\
			execution/init/init_export.c\
			execution/pipe/child_cmd.c\
			execution/pipe/here_doc_pipe.c\
			execution/pipe/pipe.c\
			execution/redirection/back_to_normal.c\
			execution/redirection/here_doc.c\
			execution/redirection/here_doc_expand.c\
			execution/redirection/init_redirection.c\
			execution/redirection/redirection.c\
			execution/redirection/simple_redirection.c\
			execution/signal/signal.c\
			execution/src/cd/cd.c\
			execution/src/cd/cd_path.c\
			execution/src/cd/update_env_export_old_pwd.c\
			execution/src/cd/update_env_export_pwd.c\
			execution/src/cmd/cmd.c\
			execution/src/cmd/cmd_phase.c\
			execution/src/echo/echo.c\
			execution/src/env/env.c\
			execution/src/exit/exit.c\
			execution/src/export/add_env_export.c\
			execution/src/export/add_export.c\
			execution/src/export/add_to_export.c\
			execution/src/export/add_update_arg_env.c\
			execution/src/export/add_update_arg_export.c\
			execution/src/export/add_update_arg_export_helper.c\
			execution/src/export/export.c\
			execution/src/export/print_export.c\
			execution/src/other/other.c\
			execution/src/other/run_cmd.c\
			execution/src/pwd/pwd.c\
			execution/src/unset/new_env_export.c\
			execution/src/unset/unset.c\
			execution/src/unset/unset_env_export.c\
			execution/src/utils/export_unset.c\
			execution/util/atoi.c\
			execution/util/calloc.c\
			execution/util/error.c\
			execution/util/free.c\
			execution/util/fsplit.c\
			execution/util/isalnum.c\
			execution/util/isalpha.c\
			execution/util/isdigit.c\
			execution/util/split.c\
			execution/util/strcmp.c\
			execution/util/strcpy.c\
			execution/util/strdup.c\
			execution/util/strjoin.c\
			execution/util/strjoin_w_quote.c\
			execution/util/strlen.c\
			execution/util/strnstr.c


PARSING = parsing/lexer/find_closing_quote.c\
		parsing/lexer/get_string_btw_quotes.c\
		parsing/lexer/init_lexer.c\
		parsing/lexer/init_token.c\
		parsing/lexer/lexer_get_input_redir_token.c\
		parsing/lexer/lexer_get_next_token.c\
		parsing/lexer/lexer_get_output_redir_token.c\
		parsing/lexer/lexer_get_pipe_token.c\
		parsing/lexer/lexer_get_string.c\
		parsing/lexer/lexer_move_to_next_char.c\
		parsing/lexer/lexer_peek_next_char.c\
		parsing/lexer/lexer_skip_whitespaces.c\
		parsing/lexer/tokenize.c\
		parsing/libft/ft_atoi.c\
		parsing/libft/ft_bzero.c\
		parsing/libft/ft_calloc.c\
		parsing/libft/ft_isalnum.c\
		parsing/libft/ft_isalpha.c\
		parsing/libft/ft_isascii.c\
		parsing/libft/ft_isdigit.c\
		parsing/libft/ft_isprint.c\
		parsing/libft/ft_itoa.c\
		parsing/libft/ft_lstadd_back_bonus.c\
		parsing/libft/ft_lstadd_front_bonus.c\
		parsing/libft/ft_lstclear_bonus.c\
		parsing/libft/ft_lstdelone_bonus.c\
		parsing/libft/ft_lstiter_bonus.c\
		parsing/libft/ft_lstlast_bonus.c\
		parsing/libft/ft_lstmap_bonus.c\
		parsing/libft/ft_lstnew_bonus.c\
		parsing/libft/ft_lstsize_bonus.c\
		parsing/libft/ft_memccpy.c\
		parsing/libft/ft_memchr.c\
		parsing/libft/ft_memcmp.c\
		parsing/libft/ft_memcpy.c\
		parsing/libft/ft_memmove.c\
		parsing/libft/ft_memset.c\
		parsing/libft/ft_putchar_fd.c\
		parsing/libft/ft_putendl_fd.c\
		parsing/libft/ft_putnbr_fd.c\
		parsing/libft/ft_putstr_fd.c\
		parsing/libft/ft_split.c\
		parsing/libft/ft_strchr.c\
		parsing/libft/ft_strdup.c\
		parsing/libft/ft_strjoin.c\
		parsing/libft/ft_strlcat.c\
		parsing/libft/ft_strlcpy.c\
		parsing/libft/ft_strlen.c\
		parsing/libft/ft_strmapi.c\
		parsing/libft/ft_strncmp.c\
		parsing/libft/ft_strnstr.c\
		parsing/libft/ft_strrchr.c\
		parsing/libft/ft_strtrim.c\
		parsing/libft/ft_substr.c\
		parsing/libft/ft_tolower.c\
		parsing/libft/ft_toupper.c\
		parsing/parser/add_arg_to_simple_cmd.c\
		parsing/parser/add_redir_to_simple_cmd.c\
		parsing/parser/add_redir_to_table_of_redirection.c\
		parsing/parser/add_simple_cmd_to_pipeline.c\
		parsing/parser/add_string_to_table_of_args.c\
		parsing/parser/delete_string_from_table_of_args.c\
		parsing/parser/expand_dollar_sign.c\
		parsing/parser/expand_string_within_double_quotes.c\
		parsing/parser/extract_string_within_dollar_sign.c\
		parsing/parser/extract_string_within_quotes.c\
		parsing/parser/fill_table_of_redir.c\
		parsing/parser/free_ast.c\
		parsing/parser/free_lexer.c\
		parsing/parser/free_simple_cmd.c\
		parsing/parser/free_table_of_redir.c\
		parsing/parser/free_table_of_string.c\
		parsing/parser/free_token.c\
		parsing/parser/ft_realloc_redir_table.c\
		parsing/parser/ft_realloc_table.c\
		parsing/parser/ft_strjoin_and_free.c\
		parsing/parser/get_env_var_name.c\
		parsing/parser/get_env_var_value.c\
		parsing/parser/get_size_of_redir_table.c\
		parsing/parser/get_size_of_table.c\
		parsing/parser/init_ast.c\
		parsing/parser/init_redir.c\
		parsing/parser/parse_and_execute.c\
		parsing/parser/parse_command.c\
		parsing/parser/parse_simple_command.c\
		parsing/parser/unlock_file_name.c\
		parsing/parser/unlock_string.c

EXECUTION_OBJ = $(EXECUTION:.c=.o)

PARSING_OBJ = $(PARSING:.c=.o)

MAIN = main.c

all : $(NAME)

$(NAME): $(EXECUTION) $(PARSING)
	@gcc $(FLAG) $(EXECUTION) $(PARSING) $(MAIN) -lreadline -L /goinfre//.brew/opt/readline/lib  -I /goinfre//.brew/opt/readline/include -o $(NAME)

clean:
	@rm -fr $(EXECUTION_OBJ) $(PARSING_OBJ)

fclean: clean
	@rm -fr $(NAME)

re: fclean all
