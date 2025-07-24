NAME = push_swap
SRC = error_check.c \
		list_utils.c \
		main.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort.c \
		stack_init.c \
		swap.c \
		turkish.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = push_swap.h
OBJ_DIR = obj
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
CC = cc
CCFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -I. -Ilibft -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
