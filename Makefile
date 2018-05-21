# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 14:59:54 by shagazi           #+#    #+#              #
#    Updated: 2018/05/20 13:57:17 by shagazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

# directories
OBJ_DIR = obj/
SRC_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/
TEST_DIR = test/

# complier
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -O3 -march=native -pipe
DEBUG = -g

# src & obj files
SRC_FILES = ft_printf.c argcast.c flags.c parse.c precision.c write.c \
formatstring.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
TEST = a.out

# libraries
LIBFT = ft

INCLUDES = -I $(LIBFT_DIR)includes/ -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\`ft_printf\` [INFO] Library created"

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) $(INCLUDES) -c $^
	@mv -f *.o $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)
	@echo "\`ft_printf\` [INFO] Object folder removed"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)
	@echo "\`ft_printf\` [INFO] Executable removed"

test: all
	gcc $(DEBUG) -w test/*.c -L . -l ftprintf $(INCLUDES) -o $(TEST)

re: fclean all

.PHONY: all clean fclean re $(NAME)
