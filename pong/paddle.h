#ifndef PADDLE_H_
#define PADDLE_H_

struct PaddleCoordinate {
	unsigned short x;
	unsigned short y;
};

struct Dimension {
    unsigned short width;
    unsigned short height;
};


void drawPaddle(SDL_Renderer *renderer, struct PaddleCoordinate position, struct Dimension size, unsigned short y);
void drawPaddleRow(SDL_Renderer *renderer, struct PaddleCoordinate position, struct Dimension size, unsigned short x);
#endif

