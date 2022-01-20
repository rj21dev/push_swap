NAME		= push_swap
SRC			= push_swap.c input_parser.c swap_ops.c rotate_ops.c rev_rotate_ops.c push_ops.c utils.c midpoint_algo.c count_rotates.c optimized_rotates.c
HDR			= header.h
LIB_SRC		= ./libft/
LIB_NAME	= libft.a
OBJ			= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -I. -I$(LIB_SRC) -c $< -o $@

$(NAME): $(OBJ) $(LIB_SRC)$(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_SRC)$(LIB_NAME) -o $(NAME)

$(LIB_SRC)$(LIB_NAME) : libft ;

libft :
	make -C $(LIB_SRC)

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_SRC)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_SRC)

re: fclean all

.PHONY : all libft clean fclean re
