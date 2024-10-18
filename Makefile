# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 11:51:18 by hfilipe-          #+#    #+#              #
#    Updated: 2024/10/17 15:05:55 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BUILD_PATH = ./srcs
OBJ_PATH = ./obj
FLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(BUILD_PATH)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c )
OBJ = $(SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH)/, $(notdir $(OBJ)))
HEAD = includes/ 

all: $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(SRCS)
	@mkdir -p $(OBJ_PATH)
	@cc -I./$(HEAD) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean:
	@rm -f $(NAME)

re: fclean all