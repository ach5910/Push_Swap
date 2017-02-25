# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 15:05:38 by ahunt             #+#    #+#              #
#    Updated: 2017/01/11 15:05:40 by ahunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 15:41:53 by ahunt             #+#    #+#              #
#    Updated: 2016/11/30 15:41:58 by ahunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CH = checker

CC = gcc

INC += include libft/include

LIBFT = ./libft/libft.a

LIBFT_LINK = -L libft -lft

CFLAGS += $(foreach d, $(INC), -I$d)

AR = ar

RLIB = ranlib

RM = rm -rf

PS_BASE = 	push_swap.c \
			print.c \
			rotate.c \
			swap.c \
			pop.c \
			utils.c \

PS_SRC = $(addprefix src/, $(PS_BASE))

PS_OBJ = $(addprefix obj/, $(PS_BASE:.c=.o))

CH_BASE = 	checker.c \
			print.c \
			rotate.c \
			swap.c \
			pop.c \
			utils.c \

CH_SRC = $(addprefix src/, $(CH_BASE))

CH_OBJ = $(addprefix obj/, $(CH_BASE:.c=.o))

all: $(LIBFT) $(PS) $(CH)

$(LIBFT):
	make -C libft

$(PS_OBJ): | obj

$(CH_OBJ): | obj

obj:
	mkdir -p $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(PS): $(PS_OBJ)
	$(CC) $(LIBFT_LINK) $(CFLAGS) -o $@ $^

$(CH): $(CH_OBJ)
	$(CC) $(LIBFT_LINK) $(CFLAGS) -o $@ $^

debug: $(OBJ)
	$(CC) -fsanitize=address  -o $@ $^  $(CFLAGS)

clean:
	$(RM) $(OBJ)
	make -C ./libft clean

ps_clean:
	$(RM) $(OBJ)

fclean: ps_clean
	$(RM) $(NAME)
	$(RM) obj
	make -C ./libft fclean

ps_fclean: ps_clean
	$(RM) $(NAME)
	$(RM) obj

re: ps_fclean all
	make -C ./libft re

.PHONY: all clean fclean re
