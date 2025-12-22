NAME = ex03
SRC = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(SRC:%.cpp=$(OBJ_DIR)/%.d)

CPP = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	$(CPP) $(CCFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp  Makefile | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CPP) $(CCFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re