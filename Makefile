CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
LIBFT_DIR = inc/libft
GNL_DIR = inc/so_get_next_line
MLX_DIR = mlx
INC_DIR = inc
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext
MLX_INC = -I$(MLX_DIR)

SRCS = $(SRC_DIR)/so_long.c \
	   $(SRC_DIR)/map_controls_1.c \
	   $(SRC_DIR)/map_controls_2.c \
	   $(SRC_DIR)/free.c \
	   $(SRC_DIR)/entities.c \
	   $(SRC_DIR)/get_location.c \
	   $(SRC_DIR)/move.c \
	   $(SRC_DIR)/take_off.c \
	   $(SRC_DIR)/rendering.c \
	   $(GNL_DIR)/get_next_line.c \
	   $(GNL_DIR)/get_next_line_utils.c \
	   $(LIBFT_DIR)/libft_utils.c \
	   $(LIBFT_DIR)/ft_printf.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
