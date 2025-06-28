# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:50:16 by fgrabows          #+#    #+#              #
#    Updated: 2025/06/25 11:55:11 by fgrabows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR = obj
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))


all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
	