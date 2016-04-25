NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OBJDIR = ./obj
SRCDIR = ./src
INCDIR = ./includes/
FCT = $(shell find $(SRCDIR) | grep "\.c" | cut -d / -f 3-4 | cut -d . -f 1)
SRC = $(FCT:%=$(SRCDIR)/%.c)
OBJ = $(FCT:%=$(OBJDIR)/%.o)
INC = $(INCDIR:%=-I %)

all: $(NAME)
	@echo "\0033[1;34m Libft		\0033[1;30m[All OK]\0033[1;37m"

$(OBJ):$(SRC)
	@mkdir -p $(OBJDIR)
	@(cd $(OBJDIR) ; mkdir -p $(shell find $(SRCDIR) | grep -v "\.c" | cut -d / -f 3))
	@gcc -c $(SRCDIR)/$(shell echo $@ | cut -d / -f 2-3 | cut -d . -f 1).c $(FLAGS) $(INC) -o $@

$(NAME): $(OBJ)
	@ar rcus $@ $^
	@echo "\0033[1;34m %.o 		\0033[0;32m[Create]"
	@echo "\0033[1;34m Libft.a 	\0033[0;32m[Create]\0033[1;37m"

clean:
	@rm -f $(OBJ)
	@echo "\0033[1;34m %.o 		\0033[0;31m[Delete]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\0033[1;34m libft.a 	\0033[0;31m[Delete]\0033[1;37m"

re: fclean all
