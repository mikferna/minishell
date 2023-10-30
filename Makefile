# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 16:06:29 by mikferna          #+#    #+#              #
#    Updated: 2023/10/30 13:01:56 by jumoncad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
DIR_OBJS = objs/
LREADLINE_FLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
READLINE = -I/Users/$(USER)/.brew/opt/readline/include/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

RED = \033[1;31m
BLUE = \033[1;36m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

SRCS = srcs/00_main.c \
	srcs/01_checker.c \
	srcs/02_node_utils.c \
	srcs/03_minishell.c \
	srcs/04_check_redir.c \
	srcs/05_signal.c \
	srcs/libft/ft_itoa.c \
	srcs/libft/ft_atoi.c \
	srcs/libft/ft_putchar_fd.c \
	srcs/libft/ft_putstr_fd.c \
	srcs/libft/ft_split.c \
	srcs/libft/ft_strchr.c \
	srcs/libft/ft_strdup.c \
	srcs/libft/ft_strjoin.c \
	srcs/libft/ft_strlen.c \
	srcs/libft/ft_strncmp.c \
	srcs/libft/ft_strtrim.c \
	srcs/libft/ft_substr.c \
	srcs/libft/ft_strlcpy.c \
	srcs/libft/ft_memmove.c \
	srcs/builtins/cd.c \
	srcs/builtins/cd1.c \
	srcs/builtins/env_gen.c \
	srcs/builtins/env.c \
	srcs/builtins/exit.c \
	srcs/builtins/export.c \
	srcs/builtins/pwd.c \
	srcs/builtins/unset.c \
	srcs/builtins/utils.c \
	srcs/builtins/echo.c \
	srcs/expander/expander.c \
	srcs/expander/exp_utils.c

# Directorios de objetos correspondientes a las rutas de los archivos de origen
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))

# ========= RULES ==========

# Regla de compilación para archivos de origen
$(DIR_OBJS)%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar el ejecutable
$(NAME) : $(OBJS)
	@echo "\n$(YELLOW)---------- Compilando Ficheros de Projecto ---------$(RESET)\n"
	@$(CC) $(CFLAGS) $(LREADLINE_FLAGS) $(READLINE) -o $(NAME) $^
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"

# ========== FUNCTIONS ==========

all: $(NAME)

clean:
	@rm -rf $(DIR_OBJS)
	@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)All deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re