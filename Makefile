NAME = wolf
SRC = main.c
OUT = *.o
INC = include/
MINI = -L lib -lSDL2 -L lib -lSDL2main -L lib -lSDL2-2.0.0
FLAGS = -Wall -Wextra -Werror -Ofast -std=c99 -lpthread  
FRAME = -F SDL2/Frameworks -framework SDL2
DIRECTORY =  $(shell pwd)
all: 
	gcc -o $(NAME) -I $(INC) $(SRC) $(MINI)
sdl:
	
	cd SDL2; ./configure --prefix=$(DIRECTORY); make;
	$(MAKE) -s $(DIRECTORY)/SDL2 install
clean:
	rm -f $(OUT)
fclean:	clean
	rm -rf $(NAME) lib bin share include
re: 	fclean all