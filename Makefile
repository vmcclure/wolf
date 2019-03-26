NAME = wolf
SRC = main.c read_textur.c 
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
	cd SDL2; rm -rf build rm config.status rm libtool rm sdl2-config rm Makefile rm Makefile.rules sdl2-config.cmake sdl2.pc SDL2.spec
re: 	fclean cleansdl sdl all