#include "include/SDL2/SDL.h"
#include "wolf.h"
/* Moving Rectangle */
void line_DDA(HDC hdc, float x1, float y1, float x2, float y2)
{
	// Целочисленные значения координат начала и конца отрезка,
	// округленные до ближайшего целого
	int iX1 = roundf(x1);
	int iY1 = roundf(y1);
	int iX2 = roundf(x2);
	int iY2 = roundf(y2);
 
	// Длина и высота линии
	int deltaX = abs(iX1 - iX2);
	int deltaY = abs(iY1 - iY2);
 
	// Считаем минимальное количество итераций, необходимое
	// для отрисовки отрезка. Выбирая максимум из длины и высоты
	// линии, обеспечиваем связность линии
	int length = max(deltaX, deltaY);
 
	// особый случай, на экране закрашивается ровно один пиксел
	if (length == 0)
	{
		SetPixel (hdc, iX1, iY1, 0);
		return;
	}
 
	// Вычисляем приращения на каждом шаге по осям абсцисс и ординат
	double dX = (x2 - x1) / length;
	double dY = (y2 - y1) / length;
 
	// Начальные значения
	double x = x1;
	double y = y1;
 
	// Основной цикл
	length++;
	while (length--)
	{
		x += dX;
		y += dY;
		SetPixel(hdc, roundf(x), roundf(y), 0);
	}
}
int main(int argc, char *argv[])
{
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        SDL_Event event;
        SDL_Rect r;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
                return 3;
        }

        window = SDL_CreateWindow("SDL_CreateTexture",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        1024, 768,
                        SDL_WINDOW_RESIZABLE);

        r.w = 100;
        r.h = 50;

        renderer = SDL_CreateRenderer(window, -1, 0);

        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);

        while (1) {
                SDL_PollEvent(&event);
                if(event.type == SDL_QUIT)
                        break;
                r.x=rand()%500;
                r.y=rand()%500;

                SDL_SetRenderTarget(renderer, texture);
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
                SDL_RenderClear(renderer);
                SDL_RenderDrawRect(renderer,&r);
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
                SDL_RenderFillRect(renderer, &r);
                SDL_SetRenderTarget(renderer, NULL);
                SDL_RenderCopy(renderer, texture, NULL, NULL);
                SDL_RenderPresent(renderer);
        }
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        return 0;
}