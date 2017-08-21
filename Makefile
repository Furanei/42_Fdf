# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 16:27:03 by mbriffau          #+#    #+#              #
#    Updated: 2017/08/21 15:38:49 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ADDFLAGS = -framework OpenGL -framework Appkit

# Default rule #
DEFRULE = all

# Executable
NAME = fdf

# Directories
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes \
			libft/includes \
			get_next_line

# Libs
LIB_MLX = minilibx_macos/libmlx.a
MLX = -lmlx
LIB_FT = libft/libft.a

GNL = get_next_line/get_next_line.c
#####################
# includes
INC = libft
OBJ_PATH = objs
HEADER = incl
SRC_PATH = srcs


# Sources
SRC = srcs/main.c \
		srcs/display.c \
		srcs/draw_map.c \
		srcs/line.c \
		srcs/fdf_malloc.c \
		srcs/key_function.c \
		srcs/parsing.c \
		srcs/rotation.c \
		srcs/ft_error.c \
		srcs/color.c

OBJ = $(SRC:.c=.o)
# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #

# RULES

all: tmp $(NAME)

$(NAME) :
	@$(CC) -o $(NAME) $(CFLAGS) $(MLX) $(LIB_FT) $(GNL) $(SRC) $(ADDFLAGS)
	@echo "\033[0;32mFDF's program Created.\033[0m"

# besoin de compiler la lib avant fdf 

tmp : 
	@mkdir -p objs

re : clean all


clean :
	rm $(NAME)

#gcc main.c ../libft/libft.a ../get_next_line/get_next_line.c -framework OpenGL -framework Appkit

#gcc main.c -lmlx ../libft/libft.a ../get_next_line/get_next_line.c parsing.c display.c 
#draw_map.c -framework OpenGL -framework Appkit