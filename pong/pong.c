/*
 *	File Name: main.c
 *  Date Created: Friday, June 17, 2022
 *  Date Last Updated: Saturday, July 2, 2022
 *  Author: Christopher Francisco
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "ball.h"

#define WIDTH 640
#define HEIGHT 640

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
	unsigned short ballRadius = 10; // draw the pong ball
	struct Coordinate center = {
		.x = (WIDTH - (ballRadius * 2)) / 2, 
		.y = (HEIGHT - (ballRadius * 2)) / 2
	};
	struct Coordinate position = {
		.x = (WIDTH - (ballRadius * 2)) / 2, 
		.y = (HEIGHT - (ballRadius * 2)) / 2
	};
	drawBall(renderer, center, position, ballRadius, 1);

	SDL_RenderPresent(renderer); // have renderer present drawn contents
	SDL_Event event;  // create event

	while(SDL_WaitEvent(&event)) { // start events loop
		if (event.type == SDL_QUIT) {
			break;
		}
	}
	SDL_Quit(); // quit
}
