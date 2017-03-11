#pragma once

#include "../Gamebase/Gamebase.h"
#include <SDL2/SDL.h>
#include <string>

namespace gamebase { namespace sdl 
{
    class SdlGame : public Gamebase
    {
        private:
            // The window
            SDL_Window* window;

            // The window renderer
            SDL_Renderer* renderer;

            // The background color
            SDL_Color backgroundColor;

            // Window properties
            std::string title;
            unsigned int windowWidth;
            unsigned int windowHeight;
            bool isFullscreen;

        public:

            SdlGame();

            virtual bool Initialize();
            virtual void Uninitialize();

            virtual void Load();
            virtual void Unload();

            virtual void Update();
            virtual void Draw();
    };

}}
