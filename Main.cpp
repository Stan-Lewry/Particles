#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDL_Renderer* rend = NULL;
SDL_Window* window = NULL;

#define SCREEN_W 640
#define SCREEN_H 480

static int screen_w = 0;
static int screen_h = 0;

bool initSDL()
{

  bool ret;
  
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  IMG_Init(IMG_INIT_PNG);

  SDL_DisplayMode displayMode;
  SDL_GetCurrentDisplayMode(0, &displayMode);
  screen_w = displayMode.w;
  screen_h = displayMode.h;
  
  window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_w, screen_h, SDL_WINDOW_FULLSCREEN);
  if (window != NULL)
  {
    printf("Window Initialized\n");
    rend = SDL_CreateRenderer(window, -1, 0);
    if (rend != NULL)
    {
      // setup
      printf("Renderer Initialized\n");
      ret = true;
    }
    else ret = false;
  }
  else ret = false;

  return ret;
}

int main(int argv, char* argc[])
{
  initSDL();

  SDL_Delay(5000);

  return 0;
}
