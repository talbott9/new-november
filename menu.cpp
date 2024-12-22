void Menu::blur1() {
  blurBoxes[0] = {camera.x,camera.y,SCREEN_WIDTH,SCREEN_HEIGHT};
  if(undoBlur) {
    blurAlpha -= blurSpeed;
    if(blurAlpha < 0) {
      blurAlpha = 0;
      undoBlur = false;
      blurSuccess[1] = true;
      doBlur = false;
    }
  } else {
    blurAlpha += blurSpeed;
    if(blurAlpha > 255) {
      undoBlur = true;
      blurAlpha = 255;
      blurSuccess[0] = true;
      doBlur = false;
    }
  }
  SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);	
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, blurAlpha);
  SDL_RenderFillRect(gRenderer, &blurBoxes[0]);
}

void Menu::reset() {
  menuBuffer = 0;
}

void Menu::renderMenu() {
  switch(menuScreenID) {
  case scrMainMenu:
    gCoastBG.render(camera.x,camera.y);
    gMenuBG.render(camera.x,camera.y);

    switch(playerChar) {
    case playerLS:
      names[0] = "Nathan";
      break;
    case playerHG:
      names[0] = "Mary";
      break;
    }
     switch(friendChar) {
    case friendLS:
      names[1] = "Nathan";
      break;
    case friendHG:
      names[1] = "Mary";
      break;
    }
    
    gText.loadFromRenderedText(names[0], Black, 0, gFancyFont);
    gText.render(90, 450);
    gText.loadFromRenderedText(names[1], Black, 0, gFancyFont);
    gText.render(90, 510);

    gText.loadFromRenderedText("Start", Black, 0, gBigFancyFont);
    gText.render(330, 425);
    gText.loadFromRenderedText("Load", Black, 0, gBigFancyFont);
    gText.render(540, 425);
     
    break;
  }
}

void Menu::handleEvent(SDL_Event& e) {
  menuBuffer++;
  if(menuBuffer > 15) {
    bool mouseLeft;
    mouseLeft = SDL_GetMouseState(&mouseX, &mouseY) == 1;
    switch(menuScreenID) {
    case scrMainMenu:
      numBoxes = 4;
      mouseBox = {mouseX,mouseY,5,5};
      //start
      boxes[0] = {325, 420, 160, 65};
      //load
      boxes[1] = {535, 420, 170, 70};
      //name1
      boxes[2] = {90, 445, 190, 45};
      //name2
      boxes[3] = {90, 505, 190, 45};

      for(int i = 0; i < numBoxes; i++) {
	if(checkCollision(mouseBox,boxes[i])) {
	  SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);	
	  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 100);
	  SDL_RenderFillRect(gRenderer, &boxes[i]);
	}
      }

      if(mouseLeft) {
	if(!pressedKey[pressedKeys{mleft}]) {
	  pressedKey[pressedKeys{mleft}] = true;
      
	  if(checkCollision(mouseBox,boxes[2])) {
	    switch(playerChar) {
	    case playerLS: playerChar = playerHG;
	      break;
	    case playerHG: playerChar = playerLS;
	      break;
	    }
	  } else if(checkCollision(mouseBox,boxes[3])) {
	    switch(friendChar) {
	    case friendLS: friendChar = friendHG;
	      break;
	    case friendHG: friendChar = friendLS;
	      break;
	    }
	  } else if(checkCollision(mouseBox,boxes[0])) {
	    blurSuccess[0] = false;
	    blurSuccess[1] = false;
	    doBlur = true;
	  }
	}
      } else {
	pressedKey[pressedKeys{mleft}] = false;
      }

      if(blurSuccess[0]) {
	doBlur = true;
	menuScreenID = scrNone;
      }

      break;
    case scrNone:
      break;
    }
  }
}

Menu menu;
