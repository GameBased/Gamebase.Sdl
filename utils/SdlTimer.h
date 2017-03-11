#pragma once

#include "../../Gamebase/utils/TimerBase.h"
#include <SDL2/SDL.h>

namespace gamebase { namespace sdl 
{
    class SdlTimer : public TimerBase
    {
        public:
            void Delay(unsigned int ms)
            {
                SDL_Delay(ms);
            }

            unsigned int getTicks()
            {
                return SDL_GetTicks();
            }

            static std::unique_ptr<TimerBase> Create()
            {
                std::unique_ptr<TimerBase> timer(new SdlTimer());
                return std::move(timer);
            }        
    };
}}
