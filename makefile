NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c parser.c executor.c builtins.c signals.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all
