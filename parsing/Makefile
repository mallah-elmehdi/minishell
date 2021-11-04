NAME = parsing.a

SRCS = lexer/lexer.a libft/libft.a parser/parser.a

all: $(NAME)

$(NAME):
	@make -C lexer
	@make -C parser
	@make -C libft
	@ar rc $(NAME) $(SRCS)
	#@ranlib $(NAME)

clean:
	@make clean -C lexer
	@make clean -C parser
	@make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C lexer
	@make fclean -C parser
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

.phony : clean fclean re
