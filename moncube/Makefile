NAME += moncube
DIRC += ./
FLAG += -Wall -Wextra -Werror -O3
INDS += -I./
INDS += -I./Libft/
INDS += -I/usr/X11/include
SRCA += ./Libft/libft.a
SRCS += moncube.c
SRCS += mm_math.c
SRCS += mm_intersects.c
SRCS += mm_graph.c
SRCS += mm_libx.c
SRCS += mm_readmap.c
SRCS += mm_json.c
SRCS += mm_libx2.c
SRCS += libft2.c
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
