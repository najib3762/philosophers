NAME = philo



SRC_M = create_threads.c\
        errors.c\
        forks_init.c\
        get_time.c\
        main.c\
        philo_init.c\
        routine.c\
        utils_routine.c\
        utils.c\
        odd_even.c\
        init_input.c


OBJ_M = $(SRC_M:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=address -g3
GFLAGS = -pthread

all: $(NAME)

$(NAME): $(OBJ_M)
	$(CC) $(CFLAGS)  -o $(NAME) $(OBJ_M) $(GFLAGS)

clean:
	rm -f $(OBJ_M)
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re