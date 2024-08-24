# Nom de l'exécutable
NAME = fixed_point

# Options de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRCS = main.cpp Fixed.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
