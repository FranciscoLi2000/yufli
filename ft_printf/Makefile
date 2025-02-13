NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(NAME) compiled successfully"
bonus: all

clean:
	@$(RM) $(OBJ)
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all bonus clean fclean re
