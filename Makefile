NAME = wolf
SRC = main.c
OUT = *.o
INC = SDL22/include/SDL2
MINI = -L SDL22/lib -lSDL2
FLAGS = -Wall -Wextra -Werror -Ofast -std=c99 -lpthread  
FRAME = -F SDL2/Frameworks -framework SDL2
all: $(NAME)

$(NAME):
	gcc -o $(NAME) -I $(INC) $(SRC) $(MINI)
clean:
	rm -f $(OUT)
fclean:	clean
	rm -f $(NAME)
re: 	fclean all