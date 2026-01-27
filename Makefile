NAME = gnl

SRC = 	get_next_line.c \
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CXX = cc

CXXFLAGS = -Wall -Wextra -Werror # -g

all: $(NAME)

$(NAME): $(OBJ)
				$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
				@rm -f $(OBJ)

fclean: clean
				@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re