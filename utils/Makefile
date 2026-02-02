# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 13:42:16 by pedrohe3          #+#    #+#              #
#    Updated: 2026/01/21 18:33:13 by pedrohe3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Werror -Wextra -D BUFFER_SIZE=1

CFILES = get_next_line.c get_next_line_utils.c

all:
	$(CC) $(CFILES) && ./a.out

in:
	$(CC) $(CFILES) && ./a.out < test

move:
	mv Makefile utils/
	mv test utils/

clean:
	rm a.out

fclean: clean
