#pragma once

#include "../../Gamebase/utils/IGraphicsDevice.h"
#include <SDL2/SDL.h>

namespace gamebase { namespace sdl 
{
    class SdlGraphicsDevice : public IGraphicsDevice
    {
        private:
            SDL_Color backgroundColor;
            SDL_Renderer* renderer;

        public:
            SdlGraphicsDevice(SDL_Renderer* renderer, SDL_Color backgroundColor);
            void Clear();
            void Draw();
    };
}}
