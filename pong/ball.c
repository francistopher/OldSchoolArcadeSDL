#include<SDL2/SDL.h>
#include <math.h>
#include "ball.h"

/*
 *	Draws ball layer by layer
 */
void drawBall(SDL_Renderer *renderer, struct Coordinate center, struct Coordinate position, unsigned short radius, unsigned short radiusI)
{
	if (radiusI < radius + 1) {
		if (position.x == center.x) SDL_RenderDrawPoint(renderer, position.x, position.y);
		position.x += 1;
		drawBallLayer(renderer, center, position, radius, radiusI + 1, 1, radiusI * 2, 8 * radiusI, 1, 0);
	}
}

/*
 *	Determines if the pixel is within the specified radius through the power of math to make the ball round
 */
void drawPixelWithinRadius(SDL_Renderer *renderer, struct Coordinate center, struct Coordinate position, unsigned short radius)
{
	unsigned short distance = (unsigned short)floor(sqrt(pow(abs(center.x - position.x), 2) + pow(abs(center.y - position.y), 2)));
	printf("Distance: %d\n", distance);
	if (distance < radius) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawPoint(renderer, position.x, position.y);
	} else if (distance == radius) {	
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_RenderDrawPoint(renderer, position.x, position.y);
	}
}

/*
 *	Draw layer of ball via circulation one pixel at a time
 */
void drawBallLayer(SDL_Renderer *renderer, struct Coordinate center, struct Coordinate position, unsigned short radius, unsigned short radiusI, Direction d, unsigned short subLayerLen, unsigned short layerLen, unsigned short subLayerI, unsigned short layerI)
{
	if (layerI != layerLen) {
		//printf("DRAW PIXEL LAYER x: %d y: %d\n", rect.x, rect.y);
		drawPixelWithinRadius(renderer, center, position, radius);
	}
	if (subLayerI == subLayerLen) {
		//printf("Sub Layer Len: %d\n", subLayerLen);
		d = (d + 1) % 4;
		subLayerI = 0;
	}
	if (layerI == layerLen) {
		position.y += 1;
		drawBall(renderer, center, position, radius, radiusI);
	} else {
		switch(d) {
			case East:
				position.x += 1;
				break;
			case North:
				position.y -= 1;
				break;
			case West:
				position.x -= 1;
				break;
			default:
				position.y += 1;
		}
		drawBallLayer(renderer, center, position, radius, radiusI, d, subLayerLen, layerLen, subLayerI + 1, layerI + 1);
	}
}
