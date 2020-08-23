#include "header.h"

void doRender(t_world *world)
{
  //set the drawing color to blue
  SDL_SetRenderDrawColor(world->renderer, 0, 0, 255, 255);
  
  //Clear the screen (to blue)
  SDL_RenderClear(world->renderer);

  SDL_RenderCopy(world->renderer, world->background, NULL, NULL);
  
  //set the drawing color to white
  SDL_SetRenderDrawColor(world->renderer, world->man.color[0], world->man.color[1], world->man.color[2], 255);
  

  // for(int i = 0; i < 50; i++) {
  //   SDL_Rect starRect = {world->stars[i].x, world->stars[i].y, 80, 100};
  //   SDL_RenderCopy(world->renderer, world->star, NULL, &starRect);

  // }
  SDL_Rect start = {ScreenWidth/2 - 150, ScreenHight/2 - 80, 300, 60};
  SDL_RenderDrawRect(world->renderer, &start);

  SDL_Rect exit = {ScreenWidth/2 - 150, ScreenHight/2 + 20, 300, 60};
  SDL_RenderDrawRect(world->renderer, &exit);

  SDL_Rect rect = { world->man.x, world->man.y, world->man.size[0], world->man.size[0]};
  SDL_RenderFillRect(world->renderer, &rect);
  //We are done drawing, "present" or show to the screen what we've drawn
  SDL_RenderPresent(world->renderer);
}

