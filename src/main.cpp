#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <chrono>

#include "GUI.hpp"
#include "Particle.hpp"
#include "Firework.hpp"

#include "SDL2/SDL.h"


#ifdef _WIN32
   #include <io.h> 
   #define access    _access
#else
   #include <unistd.h>
#endif

typedef std::chrono::high_resolution_clock Clock;

#define FPS 30
#define frameDelay = 1000 / FPS

/**
 * Limits update frequency rate. Bad implementation since it creates flickering due to
 * not basing updating on a time but to wait for X.
 *
 * @param starting_tick The tick which is retrieved every while-loop.
 * @return No return value.
 */
void fpsCap(Uint32 starting_tick) {
    // '1000 / FPS' is meant to be replaced with 'frameDelay'
    if ((1000 / FPS) > SDL_GetTicks() - starting_tick) {
        SDL_Delay(1000 / FPS - (SDL_GetTicks() - starting_tick));
    }
}

bool fileExists(const std::string &filePath) {
    return access( filePath.c_str(), 0 ) == 0;
}

int main(int argc, char **argv) {

    // Ticks for fpsCap
    uint32_t startingTick;
    int endTick;

    GUI gui = GUI();

    const std::vector<std::string> args(argv+1, argv + argc);

    int width = 1280; // "Default" value for width.
    int height = 720; // "Default" value for height.


    for(auto it = args.begin(), end = args.end(); it != end; ++it) {
        if (*it == "-h" || *it == "--height") {
            height = std::stoi(*(it + 1));
        } else if (*it == "-w" || *it == "--width"){
            width = std::stoi(*(it + 1));
        }
    }



    if (argc == 1) {
        gui.init("TP", width, height, false);
    } else {
        gui.init("TP", width, height, false);
    }


    SDL_Event event;
    bool isRunning = true;

    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *image = IMG_Load("./particle.png");

    if (!image) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return 1; // Exit with an error code
    }
    Firework gp(image, 1920/2.0f, 1080/2.0f, 1920, 1080, 7500, 10);
    gp.lifetime = 300;
	gp.vel = 0.00f;
	gp.acc = 0.0025f;
    double timeElapsed = 0;

    SDL_Surface *screen = SDL_GetWindowSurface(gui.getWindow());
    std::cout << screen;
    while(isRunning) {
        // Get the number of milliseconds since the SDL library initialization.
        startingTick = SDL_GetTicks();
        auto t1 = Clock::now();

        // --- USE THIS WHEN: You have an application window and want to be able to close it.
        
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT : 
                isRunning = false;
                break;
            default:
                break;
        }

        // gui.clearRenderer();
        // gui.update();
        // gui.render();
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        gp.render(screen, timeElapsed);
        SDL_UpdateWindowSurface(gui.getWindow());

        auto t3 = Clock::now();
        // See method-description
        timeElapsed = (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(t3 - t1).count())/ 1000000.f;
        fpsCap(startingTick);
    }

    SDL_FreeSurface(image);
    SDL_FreeSurface(screen);
    gui.clean();

    return 0;
}


// Could implement this?
/*
@  https://www.reddit.com/user/larso0/

Let me give you an example:

float time_seconds = SDL_GetTicks() / 1000.f;
while(1){
    float new_time = SDL_GetTicks() / 1000.f;
    float delta = new_time - time_seconds;
    time_seconds = new_time;
    updateGamePhysics(delta);
    SDL_RenderClear(renderer);
    renderGamebjects();
    SDL_RenderPresent(renderer); //Will wait here
}

So the game loop won't continue to the next iteration before SDL_RenderPresent is done presenting. 
So if VSync is enabled, SDL_RenderPresent will wait the correct amount of time for the framerate 
to stay at the monitors refreshrate. So what I recommend using the delta variable for is 
calculating the physics of your game. so if you have an object that should move on the x axis, 
instead of calculating it like x += xPerFrame; you should do x += delta*xSpeedPerSecond. 
That way your objects will move at the same rate, no matter what the frame rate is.

*/