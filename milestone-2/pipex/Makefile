NAME = pipex
NAME_BONUS = pipex_bonus
SRC = src/clean_error.c \
		src/files.c \
		src/fork_children.c \
		src/path_cmds.c \
		src/pipes.c \
		src/pipex.c

SRC_BONUS = src_bonus/clean_error_bonus.c \
		src_bonus/files_bonus.c \
		src_bonus/fork_children_bonus.c \
		src_bonus/path_cmds_bonus.c \
		src_bonus/pipes_bonus.c \
		src_bonus/pipex_bonus.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER_DIR = inc
HEADER = $(HEADER_DIR)/pipex.h
HEADER_BONUS = $(HEADER_DIR)/pipex_bonus.h

OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR_BONUS)/%.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CCFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT): libft

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -I. -Ilibft -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c $(HEADER_BONUS) Makefile | $(OBJ_DIR_BONUS)
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -I. -Ilibft -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re libft
