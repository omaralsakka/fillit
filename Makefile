# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 14:08:26 by oabdelfa          #+#    #+#              #
#    Updated: 2022/01/03 18:43:01 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FNAMES	:=	main.c		reading.c		bitwise1.c		bitwise2.c	\
			checking.c	printing.c		solve_utils.c	solving.c

OBJS_DIR	:=	./objs/

SRCS_DIR	:=	./srcs/

OBJS	:=	$(addprefix $(OBJS_DIR), $(FNAMES:.c=.o))

LDFLAGS	=	-Llibft

LDLIBS	=	-lft

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes

CC	= clang

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	make -sC libft
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY:	all clean fclean re
