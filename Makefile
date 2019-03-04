NAME = wolf
SRC = main.c
OUT = *.o
INC = SDL2/include/SDL.h
MINI = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror -Ofast -std=c99 -lpthread  
FRAME = -F SDL2/Frameworks -framework SDL2
all: $(NAME)

$(NAME):
	gcc -o $(NAME) -I $(INC) $(SRC) $(FRAME)
clean:
	rm -f $(OUT)
fclean:	clean
	rm -f $(NAME)
re: 	fclean all