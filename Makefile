# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:16:40 by jimartin          #+#    #+#              #
#    Updated: 2023/02/23 15:58:24 by jimartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJNAME = libftprintf.o
OBJFILES = ft_printf.o

all: $(NAME)

$(NAME): $(OBJFILES)
	ar rc libftprintf.a $(OBJFILES)

%.o : %.c
	$(CC) -c $(CFLAGS)  $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all