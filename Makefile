NAME = push_swap
SRCS = stack_handeling.c input_handeling.c main.c operations.c algorithm.c
CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJS = $(SRCS:.c=.o)
LIB = -L./ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./ft_printf
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
