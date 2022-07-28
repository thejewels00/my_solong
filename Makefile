SO_LONG = so_long
SO_LONG_BONUS = bonus
CC = @cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
SRC =	mandatory/main.c \
		mandatory/error_management.c \
		mandatory/error_management_1.c \
		mandatory/window.c \
		mandatory/window_2.c \

SRC_BONUS =	so_long_bonus/main_bonus.c \
			so_long_bonus/error_management_bonus.c \
			so_long_bonus/error_management_1_bonus.c \
			so_long_bonus/window_bonus.c \
			so_long_bonus/window_2_bonus.c \

SO_LONG_OBJ = $(SRC:%.c=%.o)

SO_LONG_OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all : $(SO_LONG) $(SO_LONG_BONUS)

clean :
	@rm -rf mandatory/*.o so_long_bonus/*.o 
	@make -C libft clean
	@printf "\033[1;36mObject Files Deleted !\033[0m\n"

fclean : clean
	@rm -rf $(SO_LONG) $(so_long_bonus)
	@make -C libft fclean
	@printf "\033[1;36mProgram Deleted !\033[0m\n"

re : fclean all 


$(SO_LONG) : $(SO_LONG_OBJ) make_libft
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -L /usr/local/lib  $(SO_LONG_OBJ) ./libft/libft.a -o $(SO_LONG)
	@printf "\033[1;33m****so_long compiled Succesfully ! ****\033[0m\n"

$(SO_LONG_BONUS) : $(SO_LONG_OBJ_BONUS) make_libft
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -L /usr/local/lib  $(SO_LONG_OBJ_BONUS) ./libft/libft.a -o $(SO_LONG_BONUS)
	@printf "\033[1;33m****so_long_bonus compiled Succesfully ! ****\033[0m\n"

make_libft:
	@make -C libft/ 
	@printf "\n\033[1;33m**** libft Compiled Succesfully ! ****\033[0m\n"
