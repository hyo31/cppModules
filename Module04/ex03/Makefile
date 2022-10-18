NAME = test

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC_DIR = src/
OBJ_DIR = obj/

HEADER_FILES	=	inc/AMateria.hpp\
					inc/Character.hpp\
					inc/Cure.hpp\
					inc/Ice.hpp\
					inc/ICharacter.hpp\
					inc/IMateriaSource.hpp\
					inc/MateriaSource.hpp

SRC 			= 	src/main.cpp\
					src/AMateria.cpp\
					src/Cure.cpp\
					src/Ice.cpp\
					src/Character.cpp\
					src/MateriaSource.cpp

OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re