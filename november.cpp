#include "sdlstuff.cpp"
#include "globalvars.h"
#include "collision.cpp"
#include "renderer.h"
#include "renderer.cpp"
#include "media.cpp"
#include "menu.h"
#include "menu.cpp"
#include "cutscene.h"
#include "scriptseach.cpp"
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

    if(menuScreenID == scrNone) {
      cutscene.play();
      cutscene.handleEvent(e, false);
    }

    while( SDL_PollEvent( &e ) != 0 ) {
      //User requests quit
      if( e.type == SDL_QUIT )
	quit = true;
    }

    if(menu.doBlur) {
      menu.blur1();
    } else {
      menu.blurSuccess[0] = false;
      menu.blurSuccess[1] = false;
    }

    if(debugMode) {
      int mouseX, mouseY;
      SDL_GetMouseState(&mouseX, &mouseY);
      printf("Mouse at: %i/%i\n", mouseX, mouseY);
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
