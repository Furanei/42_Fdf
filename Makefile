# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 16:27:03 by mbriffau          #+#    #+#              #
#    Updated: 2017/05/10 00:59:25 by mbriffau         ###   ########.fr        #
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
SRC = \
		main \


OBJ = $(SRC:.c=.o)

# RULES

all: tmp $(NAME)

$(NAME) :
	@$(CC) -o $(NAME) $(SRCDIR)/$(SRC) $(LIBS) $(ADDFLAGS)
	@echo "\033[0;32mFDF's program Created.\033[0m"

tmp : 
	@mkdir -p objs

re : clean all


clean :
	rm $(NAME)

#gcc main.c ../libft/libft.a ../get_next_line/get_next_line.c -framework OpenGL -framework Appkit