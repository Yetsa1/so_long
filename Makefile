# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 15:41:27 by yeparra-          #+#    #+#              #
#    Updated: 2025/04/14 14:27:13 by yetsabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Archivos de origen
SRCS = tools2.c \
		tools.c \
		so_long.c \
		count_and_validates.c \
		memory_free.c \
		load_map.c \
		main.c

# Directorios de MiniLibX
MLX_DIR = ./mlx_linux

# Archivos de MiniLibX
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_INC = -I$(MLX_DIR)

# Librerías adicionales necesarias
LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -lbsd

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

# Opciones del compilador
CFLAGS = -Wall -Wextra -Werror -g3#-fsanitize=leak

# Comando del compilador
CC = gcc

# Regla para compilar el ejecutable
$(NAME): $(SRCS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SRCS) $(MLX_INC) $(LIBS) $(LIBFT_LIB) -o $(NAME)

# Regla para compilar MiniLibX
$(MLX_LIB):
	make -C $(MLX_DIR)

# Regla para limpiar archivos objeto y el ejecutable
clean:
	rm -f $(NAME)

# Regla para limpiar archivos generados por MiniLibX
fclean: clean
	make -C $(MLX_DIR) clean

# Regla para recompilar todo
re: fclean $(NAME)

norm:
	norminette $(SRCS) ./so_long.h libft

# Indicar que las reglas no son archivos
.PHONY: all clean fclean re

