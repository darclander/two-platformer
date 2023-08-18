#include "Particle.hpp"

Particle::Particle() {
	this->id = NULL;
	this->rect = SDL_Rect{0, 0, 0, 0};
	this->lifetime = 0;
	this->cur_lifetime = 0;
	this->x = 0;
	this->y = 0;
	this->x2 = 0;
	this->y2 = 0;
	this->vx = 0;
	this->vy = 0;
	this->ax = 0;
	this->ay = 0;
	this->rot = 0;
	this->set = 0;
	this->color = SDL_Color{ 255, 0, 0, 255 };
}

Particle::Particle(SDL_Surface *id, SDL_Rect rect, float lifetime, 
                        float x, float y, float x2, float y2, 
                        float vx, float vy, float ax, float ay, 
                        float rot, float th, SDL_Color color) {
	this->id = id;
	this->rect = rect;
	this->lifetime = lifetime;
	this->cur_lifetime = lifetime;
	this->x = x;
	this->y = y;
	this->x2 = x;
	this->y2 = y;
	this->vx = vx;
	this->vy = vy;
	this->ax = ax;
	this->ay = ay;
	this->rot = rot;
	this->th = th;
	this->set = 1;
	this->color = color;
}

void Particle::reset() {
	this->id = NULL;
	this->rect = SDL_Rect{ 0, 0, 0, 0 };
	this->lifetime = 0;
	this->cur_lifetime = 0;
	this->x = 0;
	this->y = 0;
	this->x2 = 0;
	this->y2 = 0;
	this->vx = 0;
	this->vy = 0;
	this->ax = 0;
	this->ay = 0;
	this->rot = 0;
	this->set = 0;
	this->color = SDL_Color{ 255, 0, 0, 255 };
}

void Particle::update(SDL_Surface* id, SDL_Rect rect, float lifetime, 
                        float x, float y, float x2, float y2, 
                        float vx, float vy, float ax, float ay, 
                        float rot, float th, SDL_Color color) {
	this->id = id;
	this->rect = rect;
	this->lifetime = lifetime;
	this->cur_lifetime = lifetime;
	this->x = x;
	this->y = y;
	this->x2 = x;
	this->y2 = y;
	this->vx = vx;
	this->vy = vy;
	this->ax = ax;
	this->ay = ay;
	this->rot = rot;
	this->th = th;
	this->set = 1;
	this->color = color;
}