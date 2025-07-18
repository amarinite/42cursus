NAME = fdf
SRC = main.c \
		bounds.c \
		calc_mapsize.c \
		calculate_color.c \
		connecting_dots.c \
		draw_map.c \
		draw_utils.c \
		hooks.c \
		interpolate_color.c \
		map_utils.c \
		parse_map.c \
		parse_utils.c \
		populate_map.c
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = fdf.h libft/libft.h gnl/get_next_line.h
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
OBJ_DIR = obj
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
GNL_OBJ := $(GNL_SRC:%.c=$(OBJ_DIR)/%.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx -lmlx_Linux -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ) $(GNL_OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(OBJ) $(GNL_OBJ): $(HEADERS) Makefile

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
