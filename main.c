/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:40:52 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/26 21:36:56 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include <stdio.h>
# include <fcntl.h>
#include "wolf.h"
#include <math.h>
#include "libft/libft.h"

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
	t_texture dat;
	dat = readbmp("2.bmp");
	data = dat.pixels;
	camx=camx+(cos((pov)* M_PI/180.0))*x00;
	camy=camy+(sin((pov)* M_PI/180.0))*x00;
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
			 	
			SDL_RenderDrawPoint(renderer, (x5), (y5));
			 	if (map[(int)y5/sy][(int)x5/sx] == 1)
			 		break;
					 c +=0.5;
			 }
			 while (map[(int)y5/sy][(int)x5/sx] == 1)
			 {
				c -= 0.0001;
				x5 = camx+c*(cosl((pov +i)* M_PI/180));
			 	y5 = camy+c* (sinl((pov +i)* M_PI/180));
				 
			 }
			 
			 
			  c +=0.0001;
			//   while (map[(int)y5/sy][(int)x5/sx] != 1)
			//  {
			// 	c += 0.00001;
			// 	x5 = camx+c*(cosl((pov +i)* M_PI/180));
			//  	y5 = camy+c* (sinl((pov +i)* M_PI/180));
				 
			//  }
			 lineheght[e] = roundl(6000.0/ (c * cos((i)*M_PI/180.0)));
			
			e++;
			i = i + 0.1;

		}
		x1 = 0;
		y1 = 0;
		i = 0;
		e = 0;

		// SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		int dd;
		int shag;
		shag = dat.bpp/8;
		float k;
		int m;
		int v;
		v = 0;
		int yp;
		int z;
		int xp;
		while (e < 600)
		{	
			if (v >= (dat.width))
				v = 0;

					
			y1 = 0;
			while (y1 < (lineheght[e]))
			{
				k = lineheght[e]/dat.height;
				k = y1/(k);
				// if (lineheght[e] < dat.height)
				// 	k =64.0/lineheght[e];
				yp = (dat.width*3*(int)k);
				xp = (v * 3) ;
				// printf("k - %f\n", k);
				// printf("height - %d\n", dat.height);
				// printf("y1 - %d\n", y1);
				// printf("y pos - %d\n", yp);
				// printf("x pos - %d\n", v);
				r = data[xp + yp + 2];
				g = data[xp + yp + 1];
				b = data[xp + yp + 0];
				SDL_SetRenderDrawColor(renderer, r , g, b, 255);
				// SDL_RenderDrawPoint (renderer, 400+x00/shag, 400+dat.height-y00);

				// SDL_SetRenderDrawColor(renderer,lineheght[e]/2 , 0, lineheght[e]/2, 255);
				SDL_RenderDrawPoint(renderer, e, 300 - (lineheght[e] / 2) + y1);
				y1++;
				
			}
			v++;
			e++;
		}
		printf ("%d",yp + (64*3));
		SDL_Rect pos;
		pos.x = 0;
		pos.y = 0;

		

		// printf ("%d\n", r);
		// printf ("%d\n", g);
		// printf ("%d\n", b);
		// printf ("%d\n", (int)x00/3);
		// printf ("%d\n", (int)y00);
		pos.w = 200;
		pos.h = 200;
		//dd = 64*3* y00;
	int l;
	shag = dat.bpp/8;
	y00 =0;
		while (y00 < dat.height)
		{
			x00 = 0;
			while (x00 < dat.width*shag)
			{	
				l = 2;
				dd = dat.width*shag* (y00/5);
				r = data[2+ (int)x00+dd];
				g = data[1 + (int)x00+dd];
				b = data[0 + (int)x00+dd];
				SDL_SetRenderDrawColor(renderer, r , g, b, 255);
				SDL_RenderDrawPoint (renderer, 400+x00/shag, 400+y00);
				x00+=shag;
			}
			y00++;
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
					x00 = 5;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					x00 = -5;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					x00 += 3;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					x00 -= 3;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
    			if(event.key.keysym.sym == SDLK_UP)
				{
					y00 += 1;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					y00 -= 1;
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
	camx = 12;
	camy = 5;
	sx = 600/x;
	render(x, y, map, camx*sx, camy*sx , win, 0 , 0, 0, 0, 0);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}