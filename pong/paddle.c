/*
 * Date Created: 7/27/22
 * 
 */


#include <SDL2/SDL.h>
#include "paddle.h"

/*
 * Draws paddle
 */

void drawPaddle(SDL_Renderer *renderer, struct PaddleCoordinate position, struct Dimension size, unsigned short y)
{
	if (size.height > y) {
		drawPaddleRow(renderer, position, size, 0);
		position.y += 1;
		drawPaddle(renderer, position, size, y+1);
	}
}

void drawPaddleRow(SDL_Renderer *renderer, struct PaddleCoordinate position, struct Dimension size, unsigned short x)
{
		if (size.width > x) {
			SDL_RenderDrawPoint(renderer, position.x, position.y); // draws center point of paddle
			position.x += 1;
			drawPaddleRow(renderer, position, size, x+1);
		} else {
			position.x -= size.width;
		}
}

