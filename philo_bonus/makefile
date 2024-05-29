NAME_B = philo_bonus


SRC_B = errors_bonus.c\
       get_time_bonus.c\
       main_bonus.c\
        philo_create_bonus.c\
        utils_bonus.c\
        utils_routine_bonus.c\
        init_semaphores_bonus.c\
        utils_bonus2.c

OBJ_B = $(SRC_B:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=address -g3
GFLAGS = -pthread


all: $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS)  -o $(NAME_B) $(OBJ_B) $(GFLAGS)

clean:
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME_B)

re: fclean all

.PHONY: all clean fclean re