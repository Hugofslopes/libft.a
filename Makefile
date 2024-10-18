# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 11:51:18 by hfilipe-          #+#    #+#              #
#    Updated: 2024/10/18 18:53:07 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BUILD_PATH = ./srcs
OBJ_PATH = ./obj
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(BUILD_PATH)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c )
OBJ = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH)/, $(notdir $(OBJ)))
HEAD = includes/ 
CC = cc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "Library successfully builded"
	
$(OBJ_PATH)/%.o: $(BUILD_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I./$(HEAD) $(CFLAGS) -c $< -o $@
	
clean: 
	@$(RM) $(OBJ_FILES)
	@echo "Objects successfully removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "Library successfully removed"

re: fclean all

help:
	@echo "Available targets:"
	@echo "  all      - Build the library"
	@echo "  clean    - Remove object files"
	@echo "  fclean   - Remove object files and the library"
	@echo "  re       - Rebuild the library"
