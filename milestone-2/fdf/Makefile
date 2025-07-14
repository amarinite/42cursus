NAME = fdf
SRC = $(wildcard *.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
OBJ_DIR = obj
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
GNL_OBJ := $(GNL_SRC:%.c=$(OBJ_DIR)/%.o)
CC = cc
CCFLAGS = -Wall -Wextra -g
LDFLAGS = -Lmlx -lmlx_Linux -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ) $(GNL_OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -I. -Ilibft -Ignl -Imlx -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
