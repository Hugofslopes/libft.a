# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 11:51:18 by hfilipe-          #+#    #+#              #
#    Updated: 2024/10/23 16:47:40 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BUILD_PATH = ./srcs
OBJ_PATH = ./obj
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(BUILD_PATH)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c \
ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c)
BONUS_SRCS = $(addprefix $(BUILD_PATH)/, ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
ft_ft_lstiter.c ft_lstmap.c)
OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH)/, $(notdir $(OBJ)))
BONUS_OBJ_FILES = $(addprefix $(OBJ_PATH)/, $(notdir $(BONUS_OBJ)))
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

bonus: $(NAME) $(BONUS_OBJ_FILES)
	@ar rcs $(NAME) $(BONUS_OBJ_FILES)
	@echo "Bonus successfully compiled"
	
$(OBJ_PATH)/%.o: $(BUILD_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I./$(HEAD) $(CFLAGS) -c $< -o $@
	

clean: 
	@$(RM) $(OBJ_FILES) $(BONUS_OBJ_FILES)
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
