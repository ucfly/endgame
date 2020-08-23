#include "header.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  bool flag_up_down = 1;


  t_world world;

  SDL_Window *window;                    // Declare a window
  //SDL_Renderer *renderer;                // Declare a renderer
  // SDL_Surface world->renderer

  
  SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
  
  // int color[3] = {100, 220, 0};
  // world.man.x = 220;
  // world.man.y = 140;
  // world.man.color[0] = 50;
  // world.man.color[1] = 50;
  // world.man.color[2] = 50;
  // world.man.size[0] = 50;
  // world.man.size[1] = 50;
  // world.man.speed = 1;
  // int color[] = {50, 50, 50};
  // int size[] = {50, 50};
  
  // man.size[] = {200, 200};
  
  //Create an application window with the following settings:
  window = SDL_CreateWindow("Game Window",                     // window title
                            SDL_WINDOWPOS_UNDEFINED,           // initial x position
                            SDL_WINDOWPOS_UNDEFINED,           // initial y position
                            ScreenWidth,                               // width, in pixels
                            ScreenHight,                               // height, in pixels
                            0                                  // flags
                            );
  world.renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  // starSurface = IMG_Load("./images/mario.png");
  // if (starSurface == NULL) {
  //   printf("Cannot fint picture!!!\n");
  //   SDL_Quit();
  //   return 1;
  // }
  // world.star = SDL_CreateTextureFromSurface(world.renderer, starSurface);

  // SDL_FreeSurface(starSurface);
  
  // The window is open: enter program loop (see SDL_PollEvent)
  int done = 0;

    if (argv[0])
    argc++;
  loadgame(&world);
  //Event loop
  while(!done)
  {
    
    if (flag_up_down) {
      world.man.color[random()%3] += random()%30 ;
      world.man.color[random()%3] += random()%10;
      // man.color[random()%3] += random()%3; 
    } 
    if (!flag_up_down) {
      world.man.color[random()%3] -= random()%30;
      world.man.color[random()%3] -= random()%10;
      // man.color[random()%3] -= random()%10;
    }
    if (world.man.color[0] > 210)
      flag_up_down = false;
    if (world.man.color[0] < 41)
      flag_up_down = true;

    done = processEvents(window, &world);
    
    //Render display
    doRender(&world);
    
    //don't burn up the CPU
    // SDL_Delay(10);
  }
  
  
  // Close and destroy the window
  SDL_DestroyTexture(world.star);
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(world.renderer);
  
  // Clean up
  SDL_Quit();
  return 0;
}
