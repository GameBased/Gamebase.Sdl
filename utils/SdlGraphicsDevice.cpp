#include "SdlGraphicsDevice.h"

namespace gamebase { namespace sdl 
{
    SdlGraphicsDevice::SdlGraphicsDevice(SDL_Renderer* renderer, SDL_Color backgroundColor)
    {
        this->renderer = renderer;
        this->backgroundColor = backgroundColor;
    }

    void SdlGraphicsDevice::Clear()
    {
        SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
        SDL_RenderClear(renderer);
    }

    void SdlGraphicsDevice::Draw()
    {
        SDL_RenderPresent(renderer);
    }
}}
