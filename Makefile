# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 12:24:32 by anon              #+#    #+#              #
#    Updated: 2024/01/20 20:36:06 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I. -g

# sources

L_DIR	= lib
S_DIR	= s_src
C_DIR	= c_src

L_SRC	= $(wildcard $(L_DIR)/*.c)
S_SRC	= $(wildcard $(S_DIR)/*.c)
C_SRC	= $(wildcard $(C_DIR)/*.c)

# objects

ODIR	= objs

L_OBJ	= $(patsubst %.c,$(ODIR)/%.o,$(L_SRC))
S_OBJ	= $(patsubst %.c,$(ODIR)/%.o,$(S_SRC))
C_OBJ	= $(patsubst %.c,$(ODIR)/%.o,$(C_SRC))

NAME	= client server

vpath %.c $(L_DIR)
vpath %.c $(S_DIR)
vpath %.c $(C_DIR)

all: $(NAME)

client: $(C_OBJ) $(L_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

server: $(S_OBJ) $(L_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
