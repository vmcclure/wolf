/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:40:52 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/04 15:48:21 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "/Users/vmcclure/school42/wolf/wolf/SDL2/include/SDL.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
int main(int argc, char* args[])
{
  SDL_Window* window;
  SDL_Surface* screenSurface;
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }
  window = SDL_CreateWindow("hello_sdl2",100, 100,
			    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }
  screenSurface = SDL_GetWindowSurface(window);
  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF));
  SDL_UpdateWindowSurface(window);
  SDL_LockSurface(screenSurface);
  SDL_Delay(2000);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
