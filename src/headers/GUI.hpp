#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <thread>
#include <atomic>
// #include <future> 
// #include <pthread.h>

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"


class GUI {

    public:
        GUI();


        int init(const char *title, int w, int h, bool fullscreen);

        void update();
        void render();
        void clearRenderer();
        void clean();

        SDL_Window *getWindow();

    private: 

        SDL_Renderer *m_renderer;
        SDL_Window *m_window;
        SDL_Event m_event;

        int m_windowWidth;
        int m_windowHeight;

};