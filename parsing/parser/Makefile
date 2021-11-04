NAME = parser.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror\

SRCS = *.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	#@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.phony : clean fclean re
