#include "Text.hpp"

Text::Text(SDL_Renderer *renderer, std::string font, int font_size)
{
    static bool already_instanciated = false;

    if(already_instanciated == false)
    {
        assert(TTF_Init() != -1);
    }

    this->renderer = renderer;

    this->font = TTF_OpenFont(font.c_str(), font_size);
    assert(this->font != nullptr);
}

Text::~Text()
{
    SDL_FreeSurface(this->surface);
    SDL_DestroyTexture(this->texture);
    TTF_CloseFont(this->font);
    TTF_Quit();
}

void Text::render(int x, int y, std::string text, SDL_Color color)
{
    this->surface = TTF_RenderText_Solid(this->font, text.c_str(), color);
    assert(this->surface != nullptr);

    this->rect = new SDL_Rect{x, y, this->surface->w, this->surface->h};

    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    assert(this->texture != nullptr);

    SDL_RenderCopy(this->renderer, this->texture, NULL, this->rect);

    delete this->rect;
}