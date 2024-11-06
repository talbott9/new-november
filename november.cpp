#include "sdlstuff.cpp"
#include "globalvars.h"
#include "renderer.h"
#include "renderer.cpp"
#include "media.cpp"
#include "menu.h"
#include "menu.cpp"

int main(int argv, char** args) {
  if(!init()) {
    printf( "Failed to initialize!\n" );
  }
  if(!loadMedia()) {
    printf( "Failed to load media!\n" );
  }
  loadFont(25);

  bool quit = false;
  SDL_Event e;
  
  while(!quit) {
    Uint32 starting_tick = SDL_GetTicks();

    menu.renderMenu();

    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);

    while( SDL_PollEvent( &e ) != 0 ) {
      //User requests quit
      if( e.type == SDL_QUIT )
	quit = true;
    }
    
    if( (1000/fps) > SDL_GetTicks() - starting_tick )
      SDL_Delay(1000/fps - (SDL_GetTicks() - starting_tick));
    frame_time = SDL_GetTicks()-starting_tick;
    calcFPS = (frame_time > 0) ? 1000.0f / frame_time : 0.0f;
  }
  
  close();
  return 0;
}
