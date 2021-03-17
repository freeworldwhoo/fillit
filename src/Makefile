# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnbou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 02:46:42 by rnbou             #+#    #+#              #
#    Updated: 2018/12/13 03:03:45 by rnbou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all: $(NAME)
$(NAME):
	gcc -c -Wall -Wextra -Werror libft/*.c
	ar rc libft.a *.o
	gcc -Wall -Wextra -Werror put_tet.c main.c bit_manipulation.c backtracking.c ver_tet.c read_file.c math_fillit.c libft.a deplay.c -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -rf libft.a fillit
re: fclean $(NAME)
