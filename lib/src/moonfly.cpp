#include <moonfly.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <Limelight.h>

bool MoonflyInit()
{
    SDL_SetMainReady();
    const bool is_initialized = SDL_Init(SDL_INIT_VIDEO | 
                                         SDL_INIT_AUDIO);
    return is_initialized;
}

void MoonflyClose()
{
    SDL_Quit();
}
