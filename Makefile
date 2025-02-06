NAME = libft.a
SRC_DIR = srcs
MAIN_DIR = main
INCLUDE_DIR = includes

SRC = $(wildcard $(SRC_DIR)/*.c)
MAIN = $(wildcard $(MAIN_DIR)/*.c)
OBJ = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
AR = ar
ARFLAGS = rcs

EXEC = ft

.PHONY: all clean fclean re run
all: $(NAME) $(EXEC)
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
$(EXEC): $(NAME) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -L. -lft -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "Removing object files..."
	@rm -f $(OBJ) $(MAIN_OBJ)
fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "Removing executable..."
	@rm -f $(EXEC)
re: fclean all
run: all
	@echo "Running $(EXEC)..."
	@./$(EXEC)
