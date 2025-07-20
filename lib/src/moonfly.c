#include <moonfly.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <Limelight.h>

#include "network.h"

bool MoonflyInit()
{
    SDL_SetMainReady();
    const bool is_initialized = SDL_Init(SDL_INIT_VIDEO | 
                                         SDL_INIT_AUDIO);
    
    InitNetwork(49000, "_moonlight.local", NULL);
    return is_initialized;
}

void MoonflyClose()
{
    CloseNetwork();
    SDL_Quit();
}
