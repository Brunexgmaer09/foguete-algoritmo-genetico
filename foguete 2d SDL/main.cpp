#include <SDL.h>
#include <SDL_image.h>
#include "Rocket.h"
#include "GeneticAlgorithm.h"

int main(int argc, char* argv[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("Jogo 2D do Foguete com SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    GeneticAlgorithm ga(500, renderer);

    bool running = true;
    SDL_Event event;

    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    ga.initializePopulation();

    while (running) {
        frameStart = SDL_GetTicks();

        SDL_RenderClear(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        ga.evaluateFitness();
        ga.performSelection();
        ga.performCrossover();
        ga.performMutation();

        for (auto& rocket : ga.getPopulation()) {
            rocket.update(keystates);
            rocket.renderBackground();
            rocket.render();
        }

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
