# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ametapod <pe4enko111@rambler.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/09 18:18:13 by ametapod          #+#    #+#              #
#    Updated: 2020/06/09 18:18:13 by ametapod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft
HEADER = ft_printf.h
SRC = ft_printf.c ft_vprintf.c
OBJ = $(SRC:.c=.o)
SRCBONUS = ft_vprintf.c
OBJBONUS = $(SRCBONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJBONUS)
else
	OBJ_FILES = $(OBJ)
endif

all: libfta $(NAME)

$(NAME): $(LIB)/$(LIB).a $(OBJ_FILES) $(HEADER)
	@ar -x $(LIB)/$(LIB).a
	@ar rvc $(NAME) *.o
	@ranlib $(NAME)

libfta:
	@cd $(LIB) && make

%.o: %.c
	@gcc -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME) __.*

re: fclean all

.PHONY: all clean fclean re
