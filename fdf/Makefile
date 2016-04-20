# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjivas <adjivas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/09 22:16:41 by adjivas           #+#    #+#              #
#    Updated: 2014/02/18 17:26:40 by adjivas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME += a.out
DIRC += ./
FLAG += -Wall -Wextra -Werror -O3
INDS += -I./
INDS += -I./Libft/
SRCA += ./Libft/libft.a
SRCS += testreadmap.c
SRCS += get_next_line.c
LSTC += $(patsubst %,$(DIRC)%,$(SRCS))
COMP += clang
OBJO += $(LSTC:.c=.o)

.PHONY: default all clean fclean re

default: all

all: $(NAME)

$(NAME): $(OBJO)
	@make -C ./Libft/ all
	@$(COMP) $(FLAG) $^ -o $@ $(SRCA)

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
