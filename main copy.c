/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:40:52 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/13 16:23:10 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include <stdio.h>
# include <fcntl.h>
#include "wolf.h"
#include <math.h>
#include "libft/libft.h"

void render(int x, int y, int **map, int camx, int camy, SDL_Window *win, int x00, int y00, int pov, double newx, double newy)
{

	int sx;
	int sy;
	float i;
	int y1;
	int x1;
	double rayx;
	double rayy;
	rayx = 0;
	rayy = 0;
	//int pov;
	int fov;
	//pov =0;
	fov = 60;
	double dirx;
	double diry;
	double angle;
	int stope;
	stope = 0;
	//angle = pov - (fov/2);
	newx += cos(angle* M_PI/180 );
	newy += sin(angle* M_PI/180);
	
	// dirx = rayx + cos(angle* M_PI/180 );
	// diry = rayy + sin(angle* M_PI/180);
	
	SDL_Texture *texture;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    int posX = 1000, posY = 500, width = 600, height = 600;
	SDL_Event event;
	renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
    
		sx = width/(x);
		sy = height/(y);
		
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
					while (e < sx)
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
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		
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
		i = -45;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		while (i < 46)
		{
			rayx = 0;
			rayy= 0;
			angle = (pov+i) - (fov/2);
			dirx = rayx + cos(angle* M_PI/180 );
			diry = rayy + sin(angle* M_PI/180);
			rayx = (camx*sx)+x00;
			rayy = (camy*sx)+y00;
			while ((int)rayx/sx < x && (int)rayy/sx < y && (map[((int)(rayy))/sy][((int)(rayx))/sx] != 1))
			{
				
				SDL_RenderDrawPoint(renderer, rayx, rayy);
				
					rayx +=dirx;
					rayy += diry;				
			}
			i+= 1;
		//	printf("%d", i);
		}
		//
        SDL_RenderPresent(renderer);

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
   				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					x00 += 4;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					x00 -= 4;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
    			if(event.key.keysym.sym == SDLK_UP)
				{
					y00 -= 4;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					y00 += 4;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_d)
				{
					pov += 1;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_a)
				{
					pov -= 1;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
}
int		tkey(int key)
{

	if (key == 53)
		exit(0);
		return(0);
}
int main(int c, char *v[]) {
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
	int camx;
	int camy;
	int pov;
	int fov;
	int rayx;
	int rayy;
	int dirx;
	int diry;
	int angle;
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
	printf ("%s\n", str);
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
	printf ("%d\n", x);
	printf ("%d\n", y);
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
			printf ("%d", map[y1][x1]);
			x1++;
		}
		y1++;
		printf("\n");
	}

    SDL_Init(SDL_INIT_VIDEO);

     win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);
	 camx = 5;
		camy = 5;
	render(x, y, map, camx, camy, win, 0 , 0, 30, 0, 0);
	//mlx_hook(win, 2, 0, tkey);
    //  renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
    
	// 	sx = width/(x);
	// 	sy = height/(y);
    //     SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    //     SDL_RenderClear(renderer);
	// 	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	// 	i =0;
	// 	y1 = 0;
	// 	int e;
	// 	while ( y1 < y)
	// 	{
	// 		x1 = 0;
	// 		while (x1 < x)
	// 		{
	// 			if (map[y1][x1] == 1)
	// 			i = 0;
	// 			while (i < sx)
	// 			{
	// 				e = 0;
	// 				while (e < sx)
	// 				{
	// 				SDL_RenderDrawPoint(renderer, x1*sx+i, y1*sy +e);
					  
	// 				e++;
	// 				}
	// 				i++;
	// 			} 
	// 				x1++;
	// 		}   
	// 		y1++;
	// 	}
	// 	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	// 	camx = 8;
	// 	camy = 9;
	// 	i = 0;
	// 	while (i < sx)
	// 	{
	// 		e =0;
	// 		while (e < sx)
	// 		{
	// 			SDL_RenderDrawPoint(renderer, camx*sx+i, camy*sy+e);
	// 			e++;
	// 		}
	// 		i++;
	// 	}
		
    //     SDL_RenderPresent(renderer);

	// 	while (1) {
			
    //  	   if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
    //   	      break;
   	// 	 }
   
    // SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}