# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
LIBFT_DIR = inc/libft
GNL_DIR = inc/so_get_next_line
MLX_DIR = mlx
INC_DIR = inc

# MiniLibX library settings
# MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext
MLX_INC = -I$(MLX_DIR)

# Source files
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

OBJS = $(SRCS:%.c=%.o)

# Output
NAME = so_long

# Compilation rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
