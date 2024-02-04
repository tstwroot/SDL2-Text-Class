#ifndef TEXT_CLASS_GUARD
#define TEXT_CLASS_GUARD

#include <iostream>
#include <cassert>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text
{
public:
    Text(SDL_Renderer *renderer, std::string font, int font_size);
    ~Text();
    void render(int x, int y, std::string text, SDL_Color color);

private:
    SDL_Renderer *renderer;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect *rect;
};

#endif // TEXT_CLASS_GUARD