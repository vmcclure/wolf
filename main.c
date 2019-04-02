/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:40:52 by vmcclure          #+#    #+#             */
/*   Updated: 2019/04/02 19:23:44 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include <stdio.h>
# include <fcntl.h>
#include "wolf.h"
#include <math.h>
#include "libft/libft.h"

int napravlenie1(float x, float y, float playerx, float playery, int last_step)
{
	int napravlenie;
	
	napravlenie = 0;
	if (playerx  > x && last_step == 1)
		napravlenie = 1;
	if (playerx < x && last_step == 1)
		napravlenie = 2;
	if (playery  < y && last_step == 2)
		napravlenie = 3;
	if (playery  > y && last_step == 2)
		napravlenie = 4;	
	return (napravlenie);
}

void render(int x, int y, int **map, double camx, double camy, SDL_Window *win, double x00, int y00, double pov, double newx, double newy)
{
	int z;
	z = 0;
	double lineheght[601];
	int sx;
	int sy;
	int maxf;
	float i;
	int d[601];
	int y1;
	int x1;
	long double rayx;
	long double rayy;
	SDL_Surface *surface;
	SDL_Surface *bmp2;
	char napravlenie[600];
	long double x5;
	long double y5;
	rayx = 0;
	rayy = 0;
	float startx;
	float starty;
	double fov;
	unsigned char *data;
	unsigned char *data1;
	unsigned char *data2;
	unsigned char *data3;
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
	int kub[601];
	int raznica;
	int sizeblock[601];
	int last_step;
			c = 0;
	t_texture dat;
	t_texture dat1;
	t_texture dat2;
	t_texture dat3;
	dat = readbmp("2.bmp");
	dat1 = readbmp("1.bmp");
	dat2 = readbmp("3.bmp");
	dat3 = readbmp("4.bmp");
	data = dat.pixels;
	data1 = dat1.pixels;
	data2 = dat2.pixels;
	data3 = dat3.pixels;
	camx=camx+(cos((pov)* M_PI/180.0))*x00;
	camy=camy+(sin((pov)* M_PI/180.0))*x00;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    int posX = 1000, posY = 500, width = 600, height = 600;
	SDL_Event event;
	SDL_Texture *bmp1;
	surface = SDL_LoadBMP("3.BMP");
	bmp2 = SDL_LoadBMP("2.BMP");
	renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
	bmp1 = SDL_CreateTextureFromSurface(renderer, surface);
   		sx = width/(x);
		sy = height/(y);
		int w;
		int h;
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
        SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		i =0;
		y1 = 0;
		int e;
		while ( y1 < y)
		{
			x1 = 0;
			while (x1 < x)
			{
				if (map[y1][x1] == 1)
				{i = 0;
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);}
				if (map[y1][x1] == 2)
				{i = 0;
				SDL_SetRenderDrawColor(renderer, 100, 100, 100, 0);}
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
		// while (i < sy/2)
		// {
		// 	e = -sx/2;
		// 	while (e < sx/2)
		// 	{
		// 		//SDL_RenderDrawPoint(renderer, camx*sx+i+x00, camy*sx+e+y00);
		// 		e++;
		// 	}
		// 	i++;
		// }
		e = 0;
		i = -30;
		int x6;
		int y6;
		int f;
		float start;
		float end;
		f = 0;
		
		SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
			while (i < 30)
		{
					
			c = 0;
			y5 = camy+c* (sinl((pov +i)* M_PI/180));
			 while (c < 1000)
			 {
			 	x5 = camx+c*(cosl((pov +i)* M_PI/180));
				if (map[(int)y5/sy][(int)x5/sx] == 1 || map[(int)y5/sy][(int)x5/sx] == 2)
			 		{
						 last_step = 1;
						//  printf ("x");
						 break;
						 
					 }
			 	y5 = camy+c* (sinl((pov +i)* M_PI/180));
			 	if(map[(int)y5/sy][(int)x5/sx] == 1 || map[(int)y5/sy][(int)x5/sx] == 2)
			 		{
						 last_step = 2;
						//  printf ("y");
						 break;
					 
					 }
			 SDL_RenderDrawPoint(renderer, (x5), (y5));
			 	
					 c +=1;
			 }
			
			 while (map[(int)y5/sy][(int)x5/sx] == 1 || map[(int)y5/sy][(int)x5/sx] == 2)
			 {
				c -= 0.01;
				x5 = camx+c*(cosl((pov +i)* M_PI/180));
			 	y5 = camy+c* (sinl((pov +i)* M_PI/180));
				 
			 }
			if (i == -30.0)
			{				
					starty = y5/(float)sx - (int)(y5/(float)sx);
					startx = (x5/(float)sx - (int)(x5/(float)sx));
				if (camx/sx  > x5/sx && starty > 0.001 && starty < 0.999)
					{						
						start = 1-(y5/(float)sx - (int)(y5/(float)sx));
						//printf("zapad\n");	
					}
				if (camx/sx  < x5/sx && starty > 0.001 && starty < 0.999)
					{
						//printf("vostok\n");
						start = (y5/(float)sx - (int)(y5/(float)sx));
					}
				if (camy/sy  < y5/sy && startx > 0.001 && startx < 0.999)
					{
						//printf("yg\n");
						start = 1-(x5/(float)sx - (int)(x5/(float)sx));
					}
				if (camy/sy  > y5/sy && startx > 0.001 && startx < 0.999)
					{
						//printf("sever\n");
						start = (x5/(float)sx - (int)(x5/(float)sx));
					}
			


			}
			 				
			starty = y5/(float)sx - (int)(y5/(float)sx);
			startx = (x5/(float)sx - (int)(x5/(float)sx));
			
			napravlenie[e] = napravlenie1(x5/sx, y5/sy, camx/sx, camy/sy, last_step);
			//printf ("%d\n", napravlenie[e]);
			// if (napravlenie[e] == 0)
			// {
			// 	napravlenie[e] = 1;
			// }
			// if (camx/sx  < x5/sx && starty > 0.001 && starty < 0.999)
			// 	napravlenie[e] = 2;
			// if (camy/sy  < y5/sy && startx > 0.001 && startx < 0.999)
			// 	napravlenie[e] = 3;
			// if (camy/sy  > y5/sy && startx > 0.001 && startx < 0.999)
			// 	napravlenie[e] = 4;
			
			// if (e < 2 && napravlenie[e] == napravlenie[e-2])
			// 	napravlenie[e-1] = napravlenie[e];
			
				//start =  (y5/(float)sx - (int)(y5/(float)sx));
			// if (i == 29.9)
			// 	end = (y5/(float)sx - (int)(y5/(float)sx));
			 c +=0.0001;
			 if (i == - 30)
			 {
				 x6 = (int)x5/sx;
				 y6 = (int)y5/sy;
				 sizeblock[f] = 0;				 
			 }
			if (x6 == (int)(x5/sx) && y6 ==(int)(y5/sy) && (e == 0 || napravlenie[e] == napravlenie[e-1] ))
			 	{
					sizeblock[f] += 1;
				}
			else 
			{				
				x6 = (x5/sx);
				y6 = (y5/sy);
				sizeblock[f] ++;
				// printf("%d-",f);
				// printf("%d\n",sizeblock[f]);
				f++;
				sizeblock[f] = 0;
			}
			
			//   while (map[(int)y5/sy][(int)x5/sx] != 1)
			//  {
			// 	c += 0.00001;
			// 	x5 = camx+c*(cosl((pov +i)* M_PI/180));
			//  	y5 = camy+c* (sinl((pov +i)* M_PI/180));
				 
			//  }
			 lineheght[e] = roundl(6000.0/ (c * cos((i)*M_PI/180.0)));
			if (e != 0 && napravlenie[e] != napravlenie[e-1])
			{
				raznica = lineheght[e-sizeblock[f-1]] - lineheght[e-1];
				printf ("raznica  %d\n", f);
				// i = 0;
				//  while (z < sizeblock[f-1])
				// {

				// 	z++;
				// }
			 }
			e++;
			i = i + 0.1;

		}
		// printf("\n");
		float endx;
		float endy;
		// printf("%d-",f);
		// 		printf("%d\n",sizeblock[f]);
		endy = y5/(float)sx - (int)(y5/(float)sx);
		endx = (x5/(float)sx - (int)(x5/(float)sx));
			// printf("\n");
		e = 0;
		end = (y5/(float)sx - (int)(y5/(float)sx));
		if (camx/sx  < x5/sx && endy > 0.001 && endy < 0.999)
					end = (y5/(float)sx - (int)(y5/(float)sx));
		if (camx/sx  > x5/sx && endy > 0.001 && endy < 0.999)
					end = 1-(y5/(float)sx - (int)(y5/(float)sx));
		if (camy/sy  > y5/sy && endx > 0.001 && endx < 0.999)
					end = x5/(float)sx - (int)(x5/(float)sx);
		if (camy/sy  < y5/sy && endx > 0.001 && endx < 0.999)
					end = 1-(x5/(float)sx - (int)(x5/(float)sx));
		
		//end = (y5/(float)sx - (int)(y5/(float)sx));
		//printf ("xxxx%d", (int)camx/sx);
		// if ((int)(x5/sx) >= camx/sx)
		// {
		// 	end = (y5/(float)sx - (int)(y5/(float)sx));
		// 	printf("end1%f\n",end);
		// }
		// if((int)(x5/sx) < (camx/sx))
		// 	{
		// 		end = (y5/(float)sx - (int)(y5/(float)sx));
		// 		printf("end2%f\n",end);

		// 	}
		// if ((int)(y5/sx) >= camy/sx )
		// {
		// 	if (end  < 0.0001 || end > 0.99)
		// 			e = 0;					
		// 	end = fabsl(e-(x5/(float)sx - (int)(x5/(float)sx)) +end);
		// 	printf("end3%f\n",end);
		// }
		// if ((int)(y5/sx) < camy/sx )
		// 	{
		// 		if (end  < 0.001 || end > 0.99 )
		// 			e = 0;
		// 		end = fabsl(e-(x5/(float)sx - (int)(x5/(float)sx)) +end);
		// 		printf("end4%f\n",end);
		// 		printf("e%d\n",e);
		// 	}
		
		sizeblock[f]= (float)sizeblock[f] / (end);
		// printf("end%Lf\n",x5/(float)sx);
		//  printf("\n");
		//  printf("0-%d\n",sizeblock[0]);
		x1 = 0;
		y1 = 0;
		i = 0;
		e = 0;
		maxf = f;
		f = 0;
				// SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		int dd;
		int shag;
		shag = dat.bpp/8;
		float k;
		float m;
		k = 0;
		int v;
		v = 0;
		int yp;
		double len;
		len = 0;
		
	
		int xp;
		i = 0;
		int sizeblockstart;
	
		//printf("%d\n", h);
		
		//  printf ("start%f\n", start);
		//sizeblockstart = (float)sizeblock[f] / (1-start);
		sizeblock[f] = (float)sizeblock[f] / (1-start);;
		v = start * sizeblock[f];
		//sizeblockstart = sizeblock[1];
		// while (f <= maxf)
		// {
		// 	raznica = lineheght[e] - lineheght[e+ sizeblock[f]];
		// 	e = sizeblock[f] + e;
		// 	f++;
		// 	printf ("%d\n", raznica);
		// }
		e = 0;
		f = 0;
		//printf("\n");
		while (e < 600)
		{	
			
				
			
			
			if (v >= sizeblock[f])
			{
				v = 0;
					//printf ("%f", (float)sizeblock[f]/fabsf(start-1));
				f++;
				//start = 0;
			}
			y1 = 0;
			while (y1 < (lineheght[e]))
			{
				k = lineheght[e]/dat.height;
				
				
				m = (float)sizeblock[f]/ dat.height;
						
				if (e == 0 && y1==1)
				{
					// printf ("startblock%d\n", sizeblock[f]);
					// printf ("v%d\n", v);
					// printf ("%f\n", m);
					// printf ("2block%d\n", sizeblock[1]);
				}
				
				
				//k = y1/(k);
				// if (lineheght[e] < dat.height)
				// 	k =64.0/lineheght[e];
				yp = (dat.width*3*(int)(dat.height - y1/k));
				xp = ((int)(v/m) *3) ; //(int)(v/(lineheght[e-v/20]/dat.height)) *3 ; 
					
				// printf("k - %f\n", k);
				// printf("height - %d\n", dat.height);
				// printf("y1 - %d\n", y1);
				// printf("y pos - %d\n", yp);
				// printf("x pos - %d\n", v);
				if (napravlenie[e] == 1)
				{
					r = data3[xp + yp + 2 ];
					g = data3[xp + yp + 1 ];
					b = data3[xp + yp + 0] ;
				}
				if (napravlenie[e] == 2)
				{
					r = data2[xp + yp + 2 ];
					g = data2[xp + yp + 1 ];
					b = data2[xp + yp + 0] ;
				}
				if (napravlenie[e] == 3)
				{
					r = data1[xp + yp + 2 ];
					g = data1[xp + yp + 1 ];
					b = data1[xp + yp + 0] ;
				}
				if (napravlenie[e] == 4)
				{
					r = data[xp + yp + 2 ];
					g = data[xp + yp + 1 ];
					b = data[xp + yp + 0] ;
				}
				// r = data[xp + yp + 2 ];
				// g = data[xp + yp + 1 ];
				// b = data[xp + yp + 0] ;
				SDL_SetRenderDrawColor(renderer, r , g, b, 255);
				

				//SDL_SetRenderDrawColor(renderer,lineheght[e]/2 , 0, lineheght[e]/2, 255);
				 SDL_RenderDrawPoint(renderer, e, 300 - (lineheght[e] / 2) + y1);
				y1++;
				
			}
			v++;
			e++;
		}
		//printf ("%d",yp + (64*3));
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
	// y00 =0;
	// 	while (y00 < dat.height)
	// 	{
	// 		x00 = 0;
	// 		while (x00 < dat.width*shag)
	// 		{	
	// 			l = 2;
	// 			dd = dat.width*shag* (y00);
	// 			r = data[2+ (int)x00+dd];
	// 			g = data[1 + (int)x00+dd];
	// 			b = data[0 + (int)x00+dd];
	// 			// SDL_SetRenderDrawColor(renderer, r , g, b, 255);
	// 			// SDL_RenderDrawPoint (renderer, 400+x00/shag, 400+y00);
	// 			x00+=shag;
	// 		}
	// 		y00++;
	// 	}
		

				
		
		
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
					newx += 5;
					x00 = 5;
					render(x, y, map, camx, camy, win, x00, y00, pov, newx, newy);
				}
				if(event.key.keysym.sym == SDLK_s)
				{
					newx -= 5;
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
			while (str[i] != '1' && str[i] != '0' && str[i] != '2')
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
	camx = 2;
	camy = 2;
	sx = 600/x;
	render(x, y, map, camx*sx, camy*sx , win, 0 , 0, 0, 0, 0);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}