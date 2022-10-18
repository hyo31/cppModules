NAME = Intern

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	src/main.cpp \
		src/Bureaucrat.cpp\
		src/Form.cpp\
		src/ShrubberyCreationForm.cpp\
		src/RobotomyRequestForm.cpp\
		src/PresidentialPardonForm.cpp\
		src/Intern.cpp

OBJ = $(SRC:cpp=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re