# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 18:17:53 by lhanna            #+#    #+#              #
#    Updated: 2022/03/26 16:20:45 by lhanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRV_NAME = server

CLT_NAME = client

SRV_SRC = server.c utils_client.c utils_server.c utils_put.c

CLT_SRC = client.c utils_client.c utils_server.c utils_put.c

GCC = gcc

FLAGS = -Wall -Wextra -Werror -I minitalk.h

SRV_OBJ = $(SRV_SRC:.c=.o)

CLT_OBJ = $(CLT_SRC:.c=.o)

%.o: %.c
	@$(GCC) $(FLAG) -c $< -o $@

all: $(SRV_NAME) $(CLT_NAME)

$(SRV_NAME): $(SRV_OBJ)
	@$(GCC) $(FLAGS) $(SRV_OBJ) -o $(SRV_NAME)
	@echo "\n📥 Server ready!\n"

$(CLT_NAME): $(CLT_OBJ)
	@$(GCC) $(FLAGS) $(CLT_OBJ) -o $(CLT_NAME)
	@echo "\n📟 Client ready!\n"

clean:
	@rm -rf $(SRV_OBJ) $(CLT_OBJ)
	@echo "\nClean done!\n"

fclean: clean
	@rm -rf $(SRV_NAME) $(CLT_NAME)
	@echo "\nFClean done!\n"

re:	fclean all

.PHONY: all server client clean fclean re
