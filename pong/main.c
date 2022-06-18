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

void drawShittyBall(SDL_Renderer *renderer, SDL_Rect rect, struct RGBA color);


int main(int argc, const char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) { // initialize sdl or exit upon error
		fprintf(stderr, "FAILED TO INITIALIZE SDL: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Window *window = SDL_CreateWindow("Pong 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN); // create window

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // create renderer
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // draw background
	SDL_RenderClear(renderer);

	struct RGBA white = {.r = 255, .g = 255, .b = 255, .a = 255}; // draw shitty pixelated ball
	SDL_Rect ballRect = {
		.x = (WIDTH - BALL_LENGTH) / 2,
		.y = (HEIGHT - BALL_LENGTH) / 2,
		.w = BALL_LENGTH,
		.h = BALL_LENGTH,
	};
	drawShittyBall(renderer, ballRect, white);

	SDL_RenderPresent(renderer); // have renderer present

	SDL_Event event;  // create event

	while(SDL_WaitEvent(&event)) { // start events loop
		if (event.type == SDL_QUIT) {
			break;
		}
	}


	SDL_Quit(); // quit
}

void drawShittyBall(SDL_Renderer *renderer, SDL_Rect rect, struct RGBA color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}
