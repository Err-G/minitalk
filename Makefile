# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 12:24:32 by anon              #+#    #+#              #
#    Updated: 2024/01/23 17:51:35 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I. -g

# sources

L_DIR	= lib

L_SRC	= $(wildcard $(L_DIR)/*.c)
S_SRC	= server.c
C_SRC	= client.c

# objects

ODIR	= objs

L_OBJ	= $(patsubst %.c,$(ODIR)/%.o,$(L_SRC))
S_OBJ	= $(patsubst %.c,$(ODIR)/%.o,$(S_SRC))
C_OBJ	= $(patsubst %.c,$(ODIR)/%.o,$(C_SRC))

NAME	= client server

vpath %.c $(L_DIR)

all: $(NAME)

client: $(C_OBJ) $(L_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

server: $(S_OBJ) $(L_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	$(RM)r objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
