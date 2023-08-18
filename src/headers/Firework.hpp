#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Particle.hpp"

class Firework {
public:
	Firework(SDL_Surface *image, float x, float y, float resX, float resY, size_t max, float emitFreq);
	~Firework();
	void update(float timeElapsed);
	void render(SDL_Surface *screen, double timeElapsed);
	float lifetime;
	float vel; // velocity
	float acc; // acceleration
	float ratio; //
	float emitFreq; //frequence emission
	size_t max; // number maximum of particles
	Particle* particles; // An array of particles
private:
	SDL_Surface *image; // image of the particle
	float x; // position x 
	float y; // position y
	size_t resX; // width of the window
	size_t resY; // height of the window
	float timeEmit; // delay for the emission
};