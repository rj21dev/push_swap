HDR			= header.h checker_bonus.h
NAME		= push_swap
SRC			= push_swap.c input_parser.c ops_swap.c ops_rotate.c ops_rev_rotate.c ops_push.c utils.c midpoint_algo.c rotates_count.c rotates_optimized.c
OBJ			= $(SRC:.c=.o)
NAME_B		= checker
SRC_B		= checker_bonus.c input_parser.c ops_swap_bonus.c ops_rot_bonus.c ops_rr_bonus.c ops_push_bonus.c utils.c
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
	rm -f pyviz.py
	rm -f push_swap_run_args.log
	make fclean -C $(LIB_SRC)

re: fclean all

test:
	git clone https://github.com/lmalki-h/push_swap_tester.git tester
	bash tester/tester.sh ../push_swap 5 20
	bash tester/tester.sh ../push_swap 100 20
	bash tester/tester.sh ../push_swap 500 15

simple100:
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG; echo "$$ARG\n"

simple500:
	ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG; echo "$$ARG\n"

chk:
	curl -O https://projects.intra.42.fr/uploads/document/document/6453/checker_Mac
	mv checker_Mac checker
	chmod +x checker

visual:
	git clone https://github.com/o-reo/push_swap_visualizer.git visual
	cp ./visual/pyviz.py ./
	rm -fr visual
	python3 pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`

.PHONY : all libft clean fclean re
