NAME =		Cast
CC =		clang++
CFLAGS =	-Wall -Wextra -Werror -std=c++98
DFLAGS =	-MMD -MF $(@:.o=.d)
SRC =		main.cpp
OBJ =		$(SRC:.cpp=.o)
DEP =		$(@:.o=.d)

	
all:	$(OBJ) $(NAME)
-include	$(DEP)
$(NAME): $(OBJ)
	@echo "Le programme cree les objets"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(DFLAGS)
