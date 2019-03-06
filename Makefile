NAME = wolf
SRC = main.c
OUT = *.o
INC = include/ -I libft
MINI = -L lib -lSDL2 -L lib -lSDL2main -L lib -lSDL2-2.0.0 libft/libft.a
FLAGS = -Wall -Wextra -Werror -Ofast -std=c99 -lpthread  
FRAME = -F SDL2/Frameworks -framework SDL2
DIRECTORY =  $(shell pwd)
all: $(SRC)
	gcc -o $(NAME) -I $(INC) $(SRC) $(MINI)
sdl:	
	cd SDL2; ./configure --prefix=$(DIRECTORY); make; make install
clean:
	rm -f $(OUT)
fclean:	clean
	rm -rf $(NAME) lib bin share include cd
cleansdl:
	cd SDL2 rm -rf build 
re: 	fclean cleansdl sdl all