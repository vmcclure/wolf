/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:40:52 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/25 18:57:20 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include <stdio.h>
# include <fcntl.h>
#include "wolf.h"
#include <math.h>
#include "libft/libft.h"
unsigned char *readBMP(char* filename)
{
	t_bmphead hdBMP;
	int i;
	int fd;
	int l;
	int width;
	int height;
	FILE* f;
	if((f = fopen(filename,"rb")) == NULL)
		return 0;
	
	fread(&hdBMP,sizeof(hdBMP),1,f);
	
	printf("%c%c\n",hdBMP.b1, hdBMP.b2);
	printf("%d\n",hdBMP.bfSize);
	printf("%d\n",hdBMP.bfReserved1);
	printf("%d\n",hdBMP.bfReserved2);
	printf("%d\n",hdBMP.bfOffBits);
	
	//return 0;

    fd = open(filename, O_RDONLY);
    unsigned char info[hdBMP.bfOffBits];
    i = read(fd, info, hdBMP.bfOffBits); // read the 54-byte header
	
	// printf("%d\n",i);

	width = 0;
	

	//int height = hdBMP.a[10];
    // extract image height and width from header
    width = *(int*)&hdBMP.a[6];
    height = *(int *)&hdBMP.a[10];
	 printf ("%d\n", width);
	  printf ("%d\n", height);

     int size = 3* width * height;
	unsigned  char *data;
	data = malloc (size);
//    // unsigned char data[size];//= new unsigned char[size]; // allocate 3 bytes per pixel
     l =read(fd , data, size); // read the rest of the data at once
// printf ("%d\n", l);
//  printf ("%d", size);
//     close(fd);
return data;
}
void render(int x, int y, int **map, double camx, double camy, SDL_Window *win, double x00, int y00, double pov, double newx, double newy)
{
	double lineheght[601];
	int sx;
	int sy;
	float i;
	int d[601];
	int y1;
	int x1;
	double startx;
	double starty;
	long double rayx;
	long double rayy;
	SDL_Surface *surface;
	SDL_Surface *bmp2;
	long double x5;
	long double y5;
	rayx = 0;
	rayy = 0;

	double fov;
	unsigned char *data;
	fov = 60;
	double dirx;
	double diry;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	double angle;
	SDL_Texture *texture;
	float distance[601];
	float c;
			c = 0;
	
	data = readBMP("2.bmp");
	camx=camx+(cos((pov)* M_PI/180.0));//*x00;
	camy=camy+(sin((pov)* M_PI/180.0));//*x00;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    int posX = 1000, posY = 500, width = 600, height = 600;
	SDL_Event event;
	SDL_Texture *bmp1;
	surface = SDL_LoadBMP("2.BMP");
	bmp2 = SDL_LoadBMP("2.BMP");
	renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
	bmp1 = SDL_CreateTextureFromSurface(renderer, surface);
    
		sx = width/(x);
		sy = height/(y);
		int w;
		int h;
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
        SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		i =0;
		y1 = 0;
		int e;
		while ( y1 < y)
		{
			x1 = 0;
			while (x1 < x)
			{
				if (map[y1][x1] == 1)
				i = 0;
				while (i < sx)
				{
					e = 0;
					while (e < sy)
					{
					SDL_RenderDrawPoint(renderer, x1*sx+i, y1*sy +e);
					  
					e++;
					}
					i++;
				} 
					x1++;
			}   
			y1++;
		}

		i = -sx/2;
		while (i < sy/2)
		{
			e = -sx/2;
			while (e < sx/2)
			{
				SDL_RenderDrawPoint(renderer, camx*sx+i+x00, camy*sx+e+y00);
				e++;
			}
			i++;
		}
		e = 0;
		i = -30;
		
		SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
			while (i < 30)
		{
					
			c = 0;
			 while (c < 600)
			 {
			 	x5 = camx+c*(cosl((pov +i)* M_PI/180));
			 	y5 = camy+c* (sinl((pov +i)* M_PI/180));
			 	
			//SDL_RenderDrawPoint(renderer, (x5), (y5));
			 	if (map[(int)y5/sy][(int)x5/sx] == 1)
			 		break;
					 c +=0.5;
			 }
			 while (map[(int)y5/sy][(int)x5/sx] == 1)
			 {
				c -= 0.001;
				x5 = camx+c*(cosl((pov +i)* M_PI/180));
			 	y5 = camy+c* (sinl((pov +i)* M_PI/180));
				 
			 }
			 lineheght[e] = roundl(6000.0/ (c * cos((i)*M_PI/180.0)));
			
			e++;
			i = i + 0.1;

		}
		x1 = 0;
		y1 = 0;
		i = 0;
		e = 0;

		// SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		while (e < 600)
		{	
						y1 = 0;
			while (y1 < (lineheght[e]))
			{
				
				SDL_SetRenderDrawColor(renderer,lineheght[e]/2 , 0, lineheght[e]/2, 255);
				SDL_RenderDrawPoint(renderer, e, 300 - (lineheght[e] / 2) + y1);
				y1++;
			}
			e++;
		}
		SDL_Rect pos;
		pos.x = 0;
		pos.y = 0;
		r = data[2+ (int)x00]+4;
		g = data[1 + (int)x00+4];
		b = data[0 + (int)x00+4];
		//printf ("%f\n", x00);
		pos.w = 200;
		pos.h = 200;
		
		SDL_SetRenderDrawColor(renderer, r , g, b, 255);
		i = 0;
		int j;
		while (i < 10)
		{
			j = 0;
			while (j < 10)
			{
				SDL_RenderDrawPoint (renderer, 300+i, 300+j);
				j++;
			}
			i++;
		}
		
		
		SDL_RenderCopy(renderer, bmp1, NULL, &pos);
        SDL_RenderPresent(renderer);
	//printf("%d",sx);
		while (1) {
			
     	   if (SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT)
					break;
				if (event.type == SDL_KEYDOWN)		
					break;
			}
			
   		 }
			SDL_DestroyRenderer(renderer);
   				if(event.key.keysym.sym == SDLK_w)
				{
					x00 = 2;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					x00 = -2;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					x00 += 12;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					x00 -= 12;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
    			if(event.key.keysym.sym == SDLK_UP)
				{
					y00 -= 1;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					y00 += 1;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_d)
				{
					x00 = 0;
					pov += 2;
					if (pov > 360)
						pov -= 360;
					if (pov < 0)
						pov += 360;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_a)
				{
					pov -= 2;
					x00=0;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
}
int		tkey(int key)
{

	if (key == 53)
		exit(0);
		return(0);
}
int main(int c, char *v[])
 {
    SDL_Window *win = NULL;
	SDL_Event event;
	int size;
	int sx;
	int sy;
	int x1;
	x1 =0;
	char buf[101];
	char *str;
	int i;
	int y;
	int fd;
	int x;
	int y1;
	y1 = 0;
	int **map;
	t_hero hero;
	float camx;
	float camy;
	int pov;
	int fov;
	int rayx;
	int rayy;
	int dirx;
	int diry;
	int angle;
	//unsigned char image[1920*1200*3];
	fov = 60;
	i= 0;
	y = 1;
    SDL_Texture *texture;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    int posX = 1000, posY = 500, width = 600, height = 600;
	str = ft_memalloc(1);
	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		while ((size = read(fd, buf, 100)) > 0)
		{
			buf[size] = '\0';
			if (!(str = ft_strjoin(str, buf)))
				return (0);
		}
	}
	
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (y == 1)
				x = i/2+1;
			y++;
		}
		i++;
	}

	map = (int **)malloc(sizeof(int *) * y);
	i = 0;
	while (i < y)
	{
		map[i] = (int *)malloc(sizeof(int) * x);
		i++;
	}
	i = 0;
	while (y1 < y)
	{
		x1 = 0;
		while (x1 < x)
		{
			while (str[i] != '1' && str[i] != '0')
			{				
				i++;
			}
			map[y1][x1] = str[i]-48;
			i++;
			x1++;
		}
		y1++;
	}
	i =0;
	x1 = 0;
	y1=0;
	while (y1 < y)
	{
		x1 = 0;
		while (x1 < x)
		{
			
			x1++;
		}
		y1++;
		
	}

    SDL_Init(SDL_INIT_VIDEO);

     win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);
	camx = 1.1;
	camy = 1.1;
	sx = 600/x;
	render(x, y, map, camx*sx, camy*sx , win, 0 , 0, 0, 0, 0);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}