#include<SDL2/SDL.h>
#include "ball.h"

/*
 *	Draws ball layer by layer
 */
void drawBall(SDL_Renderer *renderer, SDL_Rect rect, unsigned short radius, unsigned short radiusI)
{
	if (radiusI < radius + 1) {
		//printf("Draw Pixel x: %d y: %d\n", rect.x, rect.y);
		SDL_RenderFillRect(renderer, &rect);
		rect.x += 1;
		drawBallLayer(renderer, rect, radius, radiusI + 1, 1, radiusI * 2, 8 * radiusI, 1, 0);
	}
}

/*
 *	Draw layer of ball via circulation one pixel at a time
 */
void drawBallLayer(SDL_Renderer *renderer, SDL_Rect rect, unsigned short radius, unsigned short radiusI, Direction d, unsigned short subLayerLen, unsigned short layerLen, unsigned short subLayerI, unsigned short layerI)
{
	if (layerI != layerLen) {
		//printf("DRAW PIXEL LAYER x: %d y: %d\n", rect.x, rect.y);
		SDL_RenderFillRect(renderer, &rect);
	}
	if (subLayerI == subLayerLen) {
		//printf("Sub Layer Len: %d\n", subLayerLen);
		d = (d + 1) % 4;
		subLayerI = 0;
	}
	if (layerI == layerLen) {
		rect.y += 1;
		drawBall(renderer, rect, radius, radiusI);
	} else {
		switch(d) {
			case East:
				rect.x += 1;
				break;
			case North:
				rect.y -= 1;
				break;
			case West:
				rect.x -= 1;
				break;
			default:
				rect.y += 1;
		}
		drawBallLayer(renderer, rect, radius, radiusI, d, subLayerLen, layerLen, subLayerI + 1, layerI + 1);
	}
}
