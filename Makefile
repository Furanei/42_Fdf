# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 16:27:03 by mbriffau          #+#    #+#              #
#    Updated: 2017/08/09 19:20:44 by mbriffau         ###   ########.fr        #
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
LIBS = -lmlx

#####################
# includes
INC = libft
OBJ_PATH = objs
HEADER = incl
SRC_PATH = srcs


# Sources
SRC = main.c


OBJ = $(SRC:.c=.o)

# RULES

all: tmp $(NAME)

$(NAME) :
	@gcc -o $(NAME) $(CFLAGS) -lmlx libft/libft.a get_next_line/get_next_line.c $(SRCDIR)/$(SRC) srcs/display.c srcs/draw_map.c srcs/line.c srcs/fdf_malloc.c srcs/parsing.c $(ADDFLAGS)
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