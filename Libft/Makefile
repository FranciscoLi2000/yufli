# 目标库名称
NAME = libft.a
# 编译器 & 编译选项
CC = cc
CFLAGS = -Wall -Wextra -Werror
# 所有需要编译的源文件
SRC = $(wildcard *.c)
# Bonus 文件
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \
	    ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
# 生成的 .o 文件
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
# ar 命令：创建静态库
AR = ar rcs
# 生成所有目标
all: $(NAME)
# 编译 .o 并生成 libft.a
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
# 生成 bonus 目标
bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
# 清除 .o 文件
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
# 清除 .o 文件 和 libft.a
fclean: clean
	rm -f $(NAME)
# 重新编译
re: fclean all
# 伪目标（不生成实际文件）
.PHONY: all clean fclean re bonus
