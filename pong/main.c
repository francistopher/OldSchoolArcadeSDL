/*
 *	File Name: main.c
 *  Date Created: Friday, June 17, 2022
 *  Author: Christopher Francisco
 */

#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 640
#define BALL_LENGTH 16

struct RGBA
{
	int r, g, b, a;
};

struct Position
{
	int x, y;
};

void drawBall(SDL_Renderer *renderer, SDL_Rect rect, int radius, int radiusi);
void drawBallLayer(SDL_Renderer *renderer, SDL_Rect rect, int radius, int radiusi, int direction, int subLayerLen, int layerLen, int subLayeri, int layeri);

int main(int argc, const char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) { // initialize sdl or exit upon error
		fprintf(stderr, "FAILED TO INITIALIZE SDL: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Window *window = SDL_CreateWindow("Pong 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN); // create window

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // create what draws contents

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // set color
	SDL_RenderClear(renderer); // clear contents with set color

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // set color
	
	SDL_Rect pixelPosition = { // draw pong ball
		.x = (WIDTH - BALL_LENGTH) / 2, 
		.y = (HEIGHT - BALL_LENGTH) / 2,
		.w = 1,
		.h = 1,
	};
	int ballRadius = 5;
	drawBall(renderer, pixelPosition, ballRadius, 1);

	SDL_RenderPresent(renderer); // have renderer present drawn contents

	SDL_Event event;  // create event

	while(SDL_WaitEvent(&event)) { // start events loop
		if (event.type == SDL_QUIT) {
			break;
		}
	}

	SDL_Quit(); // quit
}

/*
 * Draws a layer of the pong ball by circulating around it pixel by pixel
 */
void drawBallLayer(SDL_Renderer *renderer, SDL_Rect rect, int radius, int radiusi, int direction, int subLayerLen, int layerLen, int subLayeri, int layeri)
{
	if (layeri != layerLen) { // draw pixels when layer has not been drawn
		printf("DRAW PIXEL LAYER x: %d y: %d\n", rect.x, rect.y);
		SDL_RenderFillRect(renderer, &rect);
	}
	if (subLayeri == subLayerLen) { // if one side has been drawn
		printf("Sub Layer Len: %d\n", subLayerLen);
		direction += 1; // change direction
		subLayeri = 0;
	}
	if (layeri == layerLen) { // layer has been drawn
		rect.y += 1; // offset for next layer
		drawBall(renderer, rect, radius, radiusi); // draw next layer
	} else { // continue in the current direction
		direction %= 4; 
		if (direction == 0) {
			rect.x += 1;
		} else if (direction == 1) {
			rect.y -= 1;
		} else if (direction == 2) {
			rect.x -= 1;
		} else if (direction == 3) {
			rect.y += 1;
		}
		drawBallLayer(renderer, rect, radius, radiusi, direction, subLayerLen, layerLen, subLayeri + 1, layeri + 1); // draw same layer
	}
}

/*
 *	Draws the pong ball layer by layer
 */
void drawBall(SDL_Renderer *renderer, SDL_Rect rect, int radius, int radiusi) 
{
	if (radiusi < radius + 1) { // iterating through layers
		printf("Draw pixel x: %d y: %d\n", rect.x, rect.y);
		SDL_RenderFillRect(renderer, &rect);
		rect.x += 1; // offset for next layer
		drawBallLayer(renderer, rect, radius, radiusi + 1, 1, radiusi * 2, 8 * radiusi, 1, 0); 
	}
}
