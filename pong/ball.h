#ifndef BALL_H_
#define BALL_H_

typedef enum {
	East,
	North,
	West,
	South
} Direction;

void drawBall(SDL_Renderer *renderer, SDL_Rect rect, unsigned short radius, unsigned short radiusI);
void drawBallLayer(SDL_Renderer *renderer, SDL_Rect rect, unsigned short radius, unsigned short radiusI, Direction d, unsigned short subLayerLen, unsigned short layerLen, unsigned short subLayerI, unsigned short layerI);

#endif
