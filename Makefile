# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 22:44:10 by student           #+#    #+#              #
#    Updated: 2020/05/12 22:03:13 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_vprintf.c
OBJ = $(SRC:.c=.o)
SRCBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJBONUS = $(SRCBONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJBONUS)
else
	OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rvc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

%.o: %.c
	@gcc -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
