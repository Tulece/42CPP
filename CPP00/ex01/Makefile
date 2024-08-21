# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook

# Fichiers source
SRCS = main.cpp PhoneBook.cpp Contact.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Compilation
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
