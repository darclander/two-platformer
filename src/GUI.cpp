#include "GUI.hpp"


GUI::GUI() {

}

int GUI::init(const char *title, int w, int h, bool fullscreen) {
    int flags = 0;
    this->m_windowWidth = w;
    this->m_windowHeight = h;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_window = SDL_CreateWindow(
                                    title,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    w,
                                    h,
                                    SDL_WINDOW_RESIZABLE
        );

        m_renderer = SDL_CreateRenderer(m_window, -1, 0);

        if(m_renderer) {
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        }
    }



    return 0;
}





void GUI::update() {
    
}


void GUI::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(m_renderer);
}


void GUI::clearRenderer() {
    SDL_RenderClear(m_renderer);
}

SDL_Window *GUI::getWindow() {
    return m_window;
}

/* Could move this to destructor? */
void GUI::clean() {

	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}
