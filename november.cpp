#include "sdlstuff.cpp"
#include "globalvars.h"
#include "collision.cpp"
#include "renderer.h"
#include "renderer.cpp"
#include "media.cpp"
#include "player.h"
#include "player.cpp"
#include "cutscene.h"
#include "menu.h"
#include "menu.cpp"
#include "scripts.cpp"
#include "cutscene.cpp"

int main(int argv, char** args) {
  if(!init()) {
    printf( "Failed to initialize!\n" );
  }
  if(!loadMedia()) {
    printf( "Failed to load media!\n" );
  }
  loadFont(22);

  bool quit = false;
  SDL_Event e;
  
  while(!quit) {
    Uint32 starting_tick = SDL_GetTicks();

    menu.renderMenu();
    menu.handleEvent(e);

    if(menuScreenID == scrAttic || menuScreenID == scrNone)
      cutscene.play();

    while( SDL_PollEvent( &e ) != 0 ) {
      //User requests quit
      if( e.type == SDL_QUIT )
	quit = true;
    }

    cutscene.handleEvent(e, false);

    if(menu.doBlur) {
      menu.blur1();
    } else {
      menu.blurSuccess[0] = false;
      menu.blurSuccess[1] = false;
    }
    
    
    if( (1000/fps) > SDL_GetTicks() - starting_tick )
      SDL_Delay(1000/fps - (SDL_GetTicks() - starting_tick));
    frame_time = SDL_GetTicks()-starting_tick;
    calcFPS = (frame_time > 0) ? 1000.0f / frame_time : 0.0f;
    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);

  }
  
  close();
  return 0;
}
