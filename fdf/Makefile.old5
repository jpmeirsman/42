NAME = fdf
FLAGS = -Wall -Wextra -Werror
OBJDIR = ./obj
SRCDIR = ./
INCDIR = ./libs/
FCT = $(shell find $(SRCDIR) | grep "\.c" | cut -d / -f 3-4 | cut -d . -f 1)
SRC = $(FCT:%=$(SRCDIR)/%.c)
OBJ = $(FCT:%=$(OBJDIR)/%.o)
INC = $(INCDIR:%=-I %)

all: $(NAME)

$(OBJ):$(SRC)
	@mkdir -p $(OBJDIR)
	@(cd $(OBJDIR) ; mkdir -p $(shell find $(SRCDIR) | grep -v "\.c" | cut -d / -f 3))
	@gcc -c $(SRCDIR)/$(shell echo $@ | cut -d / -f 2-3 | cut -d . -f 1).c $(FLAGS) $(INC) -o $@

$(NAME): $(OBJ)
	@ar rcus $@ $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
