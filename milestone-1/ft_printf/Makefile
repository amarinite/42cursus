NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
       ft_conversions.c \
       ft_conversions_num.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created successfully"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "libft compiled successfully"

%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS:.o=.d)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "ft_printf Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) cleaned"

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re test
