# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulo <paulo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 15:37:32 by paulo             #+#    #+#              #
#    Updated: 2023/08/31 15:37:41 by paulo            ###   ########.fr        #
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
NAME_BONUS = so_long_bonus

# Compiler options
CC 			= cc
FLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS	= -L ./minilibx -lmlx -Ilmlx -lXext -lX11

# Paths
SRC_DIR			= ./src/
OBJ_DIR			= ./obj/
SRC_DIR_BONUS	= ./src_bonus/

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
MINILIBX_PATH	=	./minilibx

# Source and object files
SRCS = $(wildcard $(SRC_DIR)*.c)
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
SRCS_BONUS = $(wildcard $(SRC_DIR_BONUS)*.c)
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS_BONUS:.c=.o)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

${NAME}: $(OBJS)
	@$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	@echo "\n$(GREEN) [Success] Minilibix compilated.$(RESET)\n\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "\n$(GREEN) [Success] Libft compilated.$(RESET)\n\n"
	$(CC) $(FLAGS) -lm $(SRCS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "\n$(GREEN) [Success] ./so_long created.$(RESET)\n\n"

${NAME_BONUS}: $(OBJS_BONUS)
	@$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	@echo "\n$(GREEN) [Success] Minilibix compilated.$(RESET)\n\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "\n$(GREEN) [Success] Libft compilated.$(RESET)\n\n"
	$(CC) $(FLAGS) -lm $(SRCS_BONUS) $(MLXFLAGS) $(LIBFT) -o $(NAME_BONUS)
	@echo "\n$(GREEN) [Success] ./so_long_bonus created.$(RESET)\n\n"

clean:
	@rm -rf $(OBJS)
	@echo "$(RED) [Deleting] .o files ... (deleted)$(RESET)"
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean

fclean: clean
	@rm -rf $(NAME) $(OBJS)
	@echo "$(RED) [Deleting] .a files ... (deleted)$(RESET)"
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean

fclean_bonus: clean
	@rm -rf $(NAME_BONUS) $(OBJS_BONUS)
	@echo "$(RED) [Deleting] .a files ... (deleted)$(RESET)"
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean

re: fclean all

.PHONY: all clean fclean re bonus fclean_bonus
