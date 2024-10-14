NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./Libft
SRC_DIR = src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/parser.c $(SRC_DIR)/executor.c $(SRC_DIR)/builtins.c $(SRC_DIR)/signals.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
