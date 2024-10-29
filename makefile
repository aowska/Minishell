NAME = minishell


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes/ -I Libft/


SRC_DIR = src
LIBFT_DIR = Libft

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/parser.c $(SRC_DIR)/executor.c $(SRC_DIR)/signal.c $(SRC_DIR)/builtins.c $(SRC_DIR)/ft_split_move.c $(SRC_DIR)/fd_echo.c

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a


all: $(LIBFT) $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

