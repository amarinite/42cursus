NAME = philo
SRC = src/death_monitor.c \
		src/init_all.c \
		src/philosophers.c \
		src/philo_routine.c \
		src/num_utils.c \
		src/time_utils.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(SRC:%.c=$(OBJ_DIR)/%.d)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread #-fsanitize=address

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -MMD -MP -I $(HEADER_DIR)/ -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
