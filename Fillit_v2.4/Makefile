# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 20:16:44 by wmaykit           #+#    #+#              #
#    Updated: 2019/06/12 22:52:29 by wmaykit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name prog
NAME = fillit

# flags
CC = gcc
FLAGS = -Wall -Wextra -Werror

# repo for compiling
LIB_DIR = ./libft/
SRC_DIR = ./src/
INC_DIR = ./include/

# file for compiling
SRC = $(shell ls $(SRC_DIR))

# file with puth
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
LIB = ./libft/libft.a


all:$(NAME)

$(NAME):lib
	@echo compiling...
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB) -I $(LIB_DIR) -I $(INC_DIR) 

lib:
	@echo make libft
	@make -C $(LIB_DIR)

clean:
	@echo cleaning...
	@make -C $(LIB_DIR) clean

fclean:clean
	@echo FULL
	@rm -f fillit
	@make -C $(LIB_DIR) fclean

re:fclean all
