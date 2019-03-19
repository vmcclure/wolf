/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:40:52 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/19 22:41:52 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include <stdio.h>
# include <fcntl.h>
#include "wolf.h"
#include <math.h>
#include "libft/libft.h"

void render(int x, int y, int **map, double camx, double camy, SDL_Window *win, double x00, double y00, double pov, double newx, double newy)
{
	long double lineheght[601];
	int sx;
	int sy;
	double i;
	int y1;
	int x1;
	double startx;
	double starty;
	double rayx;
	double rayy;
	SDL_Surface *surface;
	
	rayx = 0;
	rayy = 0;
	//int pov;
	double fov;
	//pov =0;
	fov = 60;
	double dirx;
	double diry;
	double angle;
	SDL_Texture *texture;
	long double distance[601];
	
	
	 
	camx=camx+(cos((pov)* M_PI/180.0))*x00;
	camy=camy+(sin((pov)* M_PI/180.0))*x00;
	// angle = pov - (fov/2);
	// newx = camx;//cos(angle* M_PI/180 );
	// newy = camy;//sin(angle* M_PI/180);
	// newx += cos(angle* M_PI/180 );
	// newy += sin(angle* M_PI/180 );
	// dirx = rayx + cos(angle* M_PI/180 );
	// diry = rayy + sin(angle* M_PI/180);
	
	
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    int posX = 1000, posY = 500, width = 600, height = 600;
	SDL_Event event;
	SDL_Texture *bmp1;
	surface = SDL_LoadBMP("1.BMP");
	renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
	bmp1 = SDL_CreateTextureFromSurface(renderer, surface);
    //texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);
		sx = width/(x);
		sy = height/(y);
		int w;
		int h;
		//texture = SDL_CreateTextureFromSurface(renderer, surface);
		//SDL_FreeSurface(surface);
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
		//SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		// camx = camx+(cos(pov* M_PI/180 )*x00);
		// camy = camy+(sin(pov* M_PI/180 )*x00);
		i = -sx/2;
		while (i < sy/2)
		{
			e = -sx/2;
			while (e < sx/2)
			{
				//SDL_RenderDrawPoint(renderer, camx*sx+i+x00, camy*sx+e+y00);
				e++;
			}
			i++;
		}
		e = 0;
		i = -30;
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		// camx += (cos(pov* M_PI/180 ));
		// camy += (sin(pov* M_PI/180 ));

		while (i < 30)
		{
			rayx = 0;
			rayy= 0;
		//	 i += 30;
			//pov = pov +i;
			// if ((pov +i) - (fov/2) > 360)
			// 	pov -= 360;
			// if ((pov +i) - (fov/2)< 0)
			// 	pov += 360;
			int k;
			k = 0;
			angle = (pov +i);// - (fov/2);
			dirx = cos(angle* M_PI/180.0 );
			diry = sin(angle* M_PI/180.0);
			rayx = (camx);//+(cos(pov* M_PI/180))*x00));//+(cos(pov* M_PI/180))*x00;
			rayy = (camy);//+(sin(pov* M_PI/180))*x00));//+(sin(pov* M_PI/180))*x00;
			// camx = ((camx))+(cos(pov* M_PI/180))*x00;
			// camy =((camy))+(sin(pov* M_PI/180))*x00;

			startx = (rayx);
			starty = (rayy);

			while (rayx/sx < x && rayy/sx < y && map[(int)rayy/sy][(int)rayx/sx] != 1)
			{
				

				SDL_RenderDrawPoint(renderer, (rayx), (rayy));
					rayx = (rayx + dirx) ;
					rayy = (rayy + diry) ;				
			}
			//  rayx = (int)rayx;
			//  rayy = (int)rayy;
			
			distance[e] = sqrt(pow(rayx - startx , 2)+ pow(rayy- starty, 2));
			//if (r % 10 == 0)
			distance[e] = distance[e] * cos (i*M_PI/180.0);
			lineheght[e] = 600 - distance[e] - (300 -distance[e] * cos (30 * M_PI/180));
			printf("%Lf", lineheght[e]);
			//lineheght[e] /= cos (i*M_PI/180.0);//*distance[e]/distance[e];
			//(long double)1000/
			printf ("%f\n", roundf(distance[e]));
			e++;
			i = i + 0.1;

		}
		x1 = 0;
		y1 = 0;
		i = 0;
		e = 0;
	int k;
	k = 0;
	float z;
	z =0;
	float raz;
	float p;
	p =0;
	float l;
		SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		while (e < 600)
		{	
			// if (e%sx == 0  && e < 600)
			// 	{
			// 		z = lineheght[(e+sx-1)]-lineheght[e];
			// 		l = lineheght[e];
			// 		k = 0;
					
			// 		raz = z/sx;
			// 		printf("%f\n",raz);
			// 		while (k < sx)
			// 		{
			// 			lineheght[k+e] = l+(raz*k);
			// 			k++;
			// 		}
			// 	}
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
		//SDL_QueryTexture(bmp1, NULL, NULL, &pos.w, &pos.h);
		pos.w = 20;
		pos.h = 30;
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
   				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					x00 =8;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					x00 = -8;
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
					x00 = 0;
					pov += 1;
					if (pov > 360)
						pov -= 360;
					if (pov < 0)
						pov += 360;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_a)
				{
					pov -= 1;
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
	camx = 12;
	camy = 5;
	sx = 600/x;
	render(x, y, map, camx*sx, camy*sx , win, 0 , 0, 0, 0, 0);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}