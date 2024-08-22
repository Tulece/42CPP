# Nom de l'exécutable
NAME = megaphone

# Commande de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Règle par défaut
all: $(NAME)

# Règle de compilation
$(NAME): megaphone.cpp
	$(CXX) $(CXXFLAGS) -o $(NAME) megaphone.cpp

# Règle de nettoyage
clean:
	rm -f $(NAME)

# Règle p                 our tout nettoyer
fclean: clean

# Règle pour recompiler
re: fclean all
