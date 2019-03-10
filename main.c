/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:40:52 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/06 19:48:30 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "include/SDL2/SDL.h"
#include <stdio.h>
#include "libft/libft.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
int main(int argc, char *argv[]) {
    SDL_Window *win = NULL;
	SDL_Event event;
	int i;
	i= 0;
    SDL_Texture *texture;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    int posX = 1000, posY = 500, width = 320, height = 240;

    SDL_Init(SDL_INIT_VIDEO);

     win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);

     renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
    

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		
		while ( i++ < height)
					SDL_RenderDrawPoint(renderer, i, i);      
        SDL_RenderPresent(renderer);

		while (1) {
			
     	   if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
      	      break;
   		 }
   
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}