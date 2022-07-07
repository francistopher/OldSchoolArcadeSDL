#include<SDL2/SDL.h>
#include <math.h>
#include "ball.h"

/*
 *	Draws ball layer by layer, pixel by pixel
 */
void drawBall(SDL_Renderer *renderer, struct Coordinate center, struct Coordinate position, unsigned short radius, unsigned short radiusI)
{
	if (radiusI < radius + 1) {
		if (position.x == center.x) SDL_RenderDrawPoint(renderer, position.x, position.y); // draws centerpoint of pong ball
		position.x += 1; // slide to the right
		drawBallLayer(renderer, center, position, radius, radiusI + 1, 1, radiusI * 2, 8 * radiusI, 1, 0); // draw the next circular layer
	}
}

/*
 *	Determines if the pixel is within the specified radius through the power of math to make the ball round
 */
void drawPixelWithinRadius(SDL_Renderer *renderer, struct Coordinate center, struct Coordinate position, unsigned short radius)
{
	unsigned short distance = (unsigned short)floor(sqrt(pow(abs(center.x - position.x), 2) + pow(abs(center.y - position.y), 2))); // calculate distance of the center from the current position
	//printf("Distance: %d\n", distance);
	if (distance < radius) { // color the pixel within circumference white
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawPoint(renderer, position.x, position.y);
	} else if (distance == radius) { // color the pixel along the circumference dark gray 
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_RenderDrawPoint(renderer, position.x, position.y);
	}
}

/*
 *	Draw layer of ball via circulation one pixel at a time
 */
void drawBallLayer(SDL_Renderer *renderer, struct Coordinate center, struct Coordinate position, unsigned short radius, unsigned short radiusI, Direction d, unsigned short subLayerLen, unsigned short layerLen, unsigned short subLayerI, unsigned short layerI)
{
	if (layerI != layerLen) { // draw circular layer
		//printf("DRAW PIXEL LAYER x: %d y: %d\n", rect.x, rect.y);
		drawPixelWithinRadius(renderer, center, position, radius);
	}
	if (subLayerI == subLayerLen) { // update drawing direction after drawing a side of the layer
		//printf("Sub Layer Len: %d\n", subLayerLen);
		d = (d + 1) % 4;
		subLayerI = 0;
	}
	if (layerI == layerLen) { // circular layer drawn
		position.y += 1;
		drawBall(renderer, center, position, radius, radiusI);
	} else { // shift position of drawing point according to direction
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
