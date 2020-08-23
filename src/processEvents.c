#include "header.h"

int processEvents(SDL_Window *window, t_world *world)
{
  SDL_Event event;
  int done = 0;

  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_WINDOWEVENT_CLOSE:
      {
        if(window)
        {
          SDL_DestroyWindow(window);
          window = NULL;
          done = 1;
        }
      }
      break;
      case SDL_KEYDOWN:
      {
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            done = 1;
          break;
        }
      }
      break;
      case SDL_QUIT:
        //quit out of the game
        done = 1;
      break;
    }
  }
  // const Uint32 *mouse = SDL_GetGlobalMouseState(NULL, NULL);
  // if (wmouse[0] >= 300 && world->mouse[0] <= 500 && world->mouse[1] >= 300 && world->mouse[1] <500)
  //   done = 1;
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if(state[SDL_SCANCODE_LEFT])
  {
    if (world->man.x > 0)
        world->man.x -= 1;
  }
  if(state[SDL_SCANCODE_RIGHT])
  {
       if (world->man.x < (ScreenWidth - world->man.size[0]))
        world->man.x += 1;
  }
  if(state[SDL_SCANCODE_UP])
  {
    if (world->man.y > 0)
        world->man.y -= 1;
  }
  if(state[SDL_SCANCODE_DOWN])
  {
    if (world->man.y < (ScreenHight - world->man.size[1]))
        world->man.y +=1;
  }

  if(state[SDL_SCANCODE_A])
    world->stars[10].x -= 10;
  if(state[SDL_SCANCODE_D])
    world->stars[10].x += 10;
  if(state[SDL_SCANCODE_W])
    world->stars[10].y -= 10;
  if(state[SDL_SCANCODE_S])
    world->stars[10].y += 10;
  
  return done;
}

