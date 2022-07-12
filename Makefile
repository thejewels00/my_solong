CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c error_management.c
SO_LONG = so_long
SO_LONG_OBJ = $(SRC:%.c=%.o)

all : $(SO_LONG)

clean :
	@rm -rf *.o 
	@make -C libft clean
	@printf "\033[1;36mObject Files Deleted !\033[0m\n"

fclean : clean
	@rm -rf $(SO_LONG)
	@make -C libft fclean
	@printf "\033[1;36mProgram Deleted !\033[0m\n"

re : fclean all

$(SO_LONG) : $(SO_LONG_OBJ) make_libft
	@$(CC) $(CFLAGS) $(SO_LONG_OBJ) ./libft/libft.a -o $(SO_LONG)
	@printf "\n\033[1;33m****so_long compiled Succesfully ! ****\033[0m\n\n"

%.o:%.c
	@$(CC) $(CFLAGS) -c $^

make_libft:
	@make -C libft/ 
	@printf "\n\033[1;33m**** libft Compiled Succesfully ! ****\033[0m\n\n"
