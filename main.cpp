#include <iostream>
#include <format>
#include <cassert>
#include "Text.hpp"

int main(int argc, char *argv[])
{
    assert(SDL_Init(SDL_INIT_EVERYTHING) >= 0);

    SDL_Window *window = SDL_CreateWindow("Text", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
    assert(window != nullptr);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    assert(renderer != nullptr);

    SDL_Event event;

    Text some_text(renderer, "IosevkaTermNerdFontMono-Regular.ttf", 24);

    do
    {
        SDL_PollEvent(&event);

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        some_text.render(10, 10, "Some Text", {255, 255, 255});

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
    } while (event.type != SDL_QUIT);
}