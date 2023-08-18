#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>



class Particle {

    public:
        Particle();

        Particle(SDL_Surface *id, SDL_Rect rect, float lifetime, 
                float x, float y, float x2, float y2, 
                float vx, float vy, float ax, float ay, float rot, 
                float th, SDL_Color color);

        void reset();
        void update(SDL_Surface* id, SDL_Rect rect, float lifetime, 
                        float x, float y, float x2, float y2, 
                        float vx, float vy, float ax, float ay, 
                        float rot, float th, SDL_Color color);



        SDL_Surface *id; // id of the particle
        SDL_Rect rect; // region of the source image to use
        float cur_lifetime; // current lifetime
        float lifetime; // total lifetime
        float x; // first vertex coordinate x
        float y; // first vertex coordinate y
        float x2; // second vertex coordinate x
        float y2;  // second vertex coordinate y
        float vx; // speed along the x-axis
        float vy; // speed along the y-axis
        float ax; // acceleration along the x-axis
        float ay; // acceleration along the y-axis
        float rot; // angle rotation of the first point
        float th; // angle rotation of the second point 
        size_t set; // true if the particle is allocated
        SDL_Color color; // color of the particle

    private:

};