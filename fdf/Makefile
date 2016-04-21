NAME += fdf
DIRC += ./
FLAG += -Wall -Wextra -Werror -O3
INDS += -I./
INDS += -I./Libft/
INDS += -I/usr/X11/include
SRCA += ./Libft/libft.a
SRCS += fdf.c
SRCS += lignes.c
SRCS += math.c
SRCS += mlibxtools.c
SRCS += itoa.c
SRCS += readmap.c
SRCS += get_next_line.c
LSTC += $(patsubst %,$(DIRC)%,$(SRCS))
COMP += clang
OBJO += $(LSTC:.c=.o)

.PHONY: default all clean fclean re

default: all

all: $(NAME)

$(NAME): $(OBJO)
	@make -C ./Libft/ all
	@$(COMP) $(FLAG) $^ -g -L/usr/X11/lib -lX11 -lmlx -lXext -o $@ $(SRCA)

%.o: %.c
	@$(COMP) $(FLAG) -c $< -o $@ $(INDS)

clean:
	@/bin/rm -rf $(OBJO)
	@make -C ./Libft/ clean

fclean:
	@/bin/rm -rf $(OBJO)
	@/bin/rm -rf $(NAME)
	@make -C ./Libft/ fclean

re:
	@/bin/rm -rf $(OBJO)
	@/bin/rm -rf $(NAME)
	@make -C ./Libft/ re
	@make -C ./ all
