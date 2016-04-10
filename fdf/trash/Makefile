# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoden <ncoden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 06:56:00 by ncoden            #+#    #+#              #
#    Updated: 2015/09/02 18:21:38 by ncoden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DEPENDENCIES
LIBFT_A = libs/libft/libft.a
LIBFT_H = libs/libft/include

LIBFT_GRAPHICS_A = libs/libft-graphics/libft-graphics.a
LIBFT_GRAPHICS_H = libs/libft-graphics/include

MINILIBX_A = libs/minilibx/libmlx.a
MINILIBX_H = libs/minilibx

# **************************************************************************** #

NAME = fdf

# COMPILATION
CC = gcc
CCFLAGS = -Wall -Werror -Wextra

ASM = nasm
ASMFLAGS = -f macho64

LNK = gcc
LNKFLAGS =	-framework OPENGL -framework AppKit

# DIRECTORIES
SRCDIR = src
OBJDIR = obj
INCDIR = \
	include\
	$(LIBFT_H)\
	$(LIBFT_GRAPHICS_H)\
	$(MINILIBX_H)

# SOURCES
LIBS = \
	$(LIBFT_A)\
	$(LIBFT_GRAPHICS_A)\
	$(MINILIBX_A)
SRC = \
	main.c\
	map.c\
	env.c\
	events.c

# **************************************************************************** #

# ALLOWED EXTENSIONS
EXTENSIONS = .c .s

# SPECIAL CHARS
LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #

.PHONY: all $(NAME) build clean fclean re dev
.SILENT:

SRC := $(filter $(addprefix %, $(EXTENSIONS)), $(SRC))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
OBJS_DIRS = $(sort $(dir $(OBJS)))

INCS_DIRS = $(addsuffix /, $(INCDIR))
INCS_DIRS += $(addsuffix /, $(dir $(LIBS)))
INCS = $(addprefix -I , $(INCS_DIRS))

all: $(NAME)
$(NAME): build $(LIBS) $(OBJS)
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)assembling...$(LOG_NOCOLOR)$(LOG_UP)"
	$(LNK) -o $(NAME) $(LIBS) $(OBJS) $(LNKFLAGS)
	echo "$(LOG_CLEAR)$(NAME)... compiled $(LOG_GREEN)✓$(LOG_NOCOLOR)"
build:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJS_DIRS)
clean:
	rm -f $(LIBS)
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

dev:
	rm -f $(LIBS)
	make
	./$(NAME) maps/42.fdf

%.a:
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$@$(LOG_NOCOLOR)$(LOG_UP)"
	make -s -C $(@D)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	$(CC) -c -o $@ $< $(INCS) $(CCFLAGS)
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	$(ASM) -o $@ $< $(INCS) $(ASMFLAGS)
