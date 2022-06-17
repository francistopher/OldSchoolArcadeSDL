/*
 *	File Name: main.c
 *  Date Created: Friday, June 17, 2022
 *  Author: Christopher Francisco
 */

#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 640

int main(int argc, const char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) { // initialize sdl or exit upon error
		fprintf(stderr, "FAILED TO INITIALIZE SDL: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Window *window = SDL_CreateWindow("Pong 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN); // create window

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // create renderer
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Event event;

	while(SDL_WaitEvent(&event)) { // start events loop
		if (event.type == SDL_QUIT) {
			break;
		}
	}


	SDL_Quit(); // quit
}
