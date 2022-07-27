#include <SDL2/SDL.h>
#include "paddle.h"

/*
 * Draws paddle
 */

void drawPaddle(SDL_Renderer *renderer, struct PaddleCoordinate center, struct PaddleCoordinate position, struct Dimension size)
{
	SDL_RenderDrawPoint(renderer, position.x, position.y); // draws center point of paddle
	printf("%d %d", size.width, size.height);
}

