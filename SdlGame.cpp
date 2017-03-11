#include "SdlGame.h"

#include "utils/SdlTimer.h"

namespace gamebase { namespace sdl 
{
    SdlGame::SdlGame() : Gamebase(SdlTimer::Create()),
                    window(NULL),
                    renderer(NULL),
                    title("Hey there!"),
                    windowWidth(640),
                    windowHeight(480)
    {
        backgroundColor.r = backgroundColor.g = backgroundColor.b = backgroundColor.a = 0xFF;
    }

    bool SdlGame::Initialize()
    {
        //Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
            return false;
        }

        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create the window
        int flags = SDL_WINDOW_SHOWN;
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, flags);
        if (window == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            return false;
        }

        //Create renderer for window
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL)
        {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            return false;
        }

        //Initialize renderer color (rgba) to background color
        SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);

        return true;
    }

    void SdlGame::Uninitialize()
    {
        // Free resources & zero pointers
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        window = NULL;
        renderer = NULL;

        // Quit
        SDL_Quit();
    }

    void SdlGame::Update()
    {
        SDL_Event e;
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
                Quit();

            // Quit if the user presses ESC when the window is fullscreen
            if (isFullscreen && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                Quit();
            }
        }
    }

    void SdlGame::Draw() { }
    void SdlGame::Load() { }
    void SdlGame::Unload() { }
}}