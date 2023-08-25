# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulo <paulo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 15:52:31 by jede-ara          #+#    #+#              #
#    Updated: 2023/08/25 11:17:18 by paulo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color variables
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m
RESET 	= \033[0m

# Executable name
NAME = so_long

# Compiler options
CC 			= cc
FLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS	= -L ./minilibx -lmlx -Ilmlx -lXext -lX11

# Paths
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
MINILIBX_PATH	=	./minilibx

# Source and object files
SRCS = $(wildcard $(SRC_DIR)*.c)
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
	@$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	@echo "\n$(GREEN) [Success] Minilibix compilated.$(RESET)\n\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "\n$(GREEN) [Success] Libft compilated.$(RESET)\n\n"
	$(CC) $(FLAGS) -lm $(SRCS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "\n$(GREEN) [Success] ./so_long created.$(RESET)\n\n"

clean:
	@rm -rf $(OBJS)
	@echo "$(RED) [Deleting] .o files ... (deleted)$(RESET)"
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean

fclean: clean
	@rm -rf $(NAME) $(OBJS)
	@echo "$(RED) [Deleting] .a files ... (deleted)$(RESET)"
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean

re: fclean all

.PHONY: all clean fclean re
