# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 17:54:18 by artuda-s          #+#    #+#              #
#    Updated: 2024/05/13 17:54:51 by artuda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs
CC = gcc
CFLAGS = -Wextra -Wall -Werror
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = gnllib.a
DEPS = get_next_line.h

.SILENT: 

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all