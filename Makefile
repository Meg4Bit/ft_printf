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
SRC = ft_printf.c ft_vprintf.c check_flag.c check_width.c check_acc.c check_type.c\
		ft_print_type.c ft_big_sixteen.c ft_char.c ft_int.c ft_percent.c ft_pointer.c ft_sixteen.c ft_string.c ft_unsigned.c\
		ft_width.c ft_acc.c ft_transform_type.c ft_add_zeros.c ft_fchar.c\
		apply_flag_bonus.c ft_float_bonus.c ft_efloat_bonus.c ft_gfloat_bonus.c ftoe_bonus.c ft_n_bonus.c
OBJ = $(SRC:.c=.o)
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
	$(MAKE) all

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME) __.*

re: fclean all

.PHONY: all clean fclean re
