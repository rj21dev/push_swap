HDR			= header.h
NAME		= push_swap
SRC			= push_swap.c input_parser.c swap_ops.c rotate_ops.c rev_rotate_ops.c push_ops.c utils.c midpoint_algo.c count_rotates.c optimized_rotates.c
OBJ			= $(SRC:.c=.o)
NAME_B		= checker
SRC_B		= checker.c input_parser.c swap_ops.c rotate_ops.c rev_rotate_ops.c push_ops.c utils.c
OBJ_B		= $(SRC_B:.c=.o)
LIB_SRC		= ./libft/
LIB_NAME	= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -I. -I$(LIB_SRC) -c $< -o $@

$(NAME): $(OBJ) $(LIB_SRC)$(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_SRC)$(LIB_NAME) -o $(NAME)

$(NAME_B): $(OBJ_B) $(LIB_SRC)$(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ_B) $(LIB_SRC)$(LIB_NAME) -o $(NAME_B)

$(LIB_SRC)$(LIB_NAME) : libft ;

libft :
	make -C $(LIB_SRC)

bonus: $(NAME_B)

clean:
	rm -f $(OBJ) $(OBJ_B)
	make clean -C $(LIB_SRC)

fclean: clean
	rm -f $(NAME)
	rm -f checker
	rm -fr tester
	rm -f push_swap_run_args.log
	make fclean -C $(LIB_SRC)

re: fclean all

test:
	git clone https://github.com/lmalki-h/push_swap_tester.git tester
	bash tester/tester.sh ../push_swap 5 10
	bash tester/tester.sh ../push_swap 100 10
	bash tester/tester.sh ../push_swap 500 10

chk:
	curl -O https://projects.intra.42.fr/uploads/document/document/6453/checker_linux
	mv checker_linux checker
	chmod +x checker

.PHONY : all libft clean fclean re
