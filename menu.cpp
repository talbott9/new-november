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

void Menu::renderMenu() {
  switch(menuScreenID) {
  case scrMainMenu:
    gAtticBG.render(camera.x,camera.y);
    gMenuBG.render(camera.x,camera.y);

    gText.loadFromRenderedText("Start", Black, 0, gBigFancyFont);
    gText.render(330, 425);
    gText.loadFromRenderedText("Load", Black, 0, gBigFancyFont);
    gText.render(540, 425);
     
    break;
  case scrAttic:
    gAtticBG.render(camera.x,camera.y);
    numBoxes = 13;
    boxes[0].w = 100;
    boxes[0].h = 50;
    boxes[0].x = camera.w - camera.w/8;
    boxes[0].y = camera.y + camera.h/6;
    strs[0] = "Schedule";
    strs[1] = "Skills";
    strs[2] = "Contacts";
    strs[3] = "Save";
    strs[4] = "Load";
    strs[5] = "End";

    boxes[6].w = 135;
    boxes[6].h = 40;
    boxes[6].x = camera.x + camera.w/32;
    boxes[6].y = camera.y + camera.h/16;
    strs[6] =  "Stam.   ";
    strs[7] =  "Stre.   ";
    strs[8] =  "Dext.   ";
    strs[9] =  "Know.   ";
    strs[10] = "Looks   ";
    strs[11] = "Breed   ";
    strs[12] = "Char.   ";
    
    strs[13] =  std::to_string(player.stamina);
    strs[14] =  std::to_string(player.strength);
    strs[15] =  std::to_string(player.dexterity);
    strs[16] =  std::to_string(player.knowledge);
    strs[17] =  std::to_string(player.looks);
    strs[18] =  std::to_string(player.breed);
    strs[19] =  std::to_string(player.character);

    std::string newstrs[8];
    for(int i = 0; i < 7; i++) {
      for(int j = 0; j < 3-strs[i+13].length(); j++) {
	newstrs[i] += " ";
      }
      newstrs[i] += strs[i+13];
    }
    
    for(int i = 0; i < 6; i++) {
      boxes[i] = {boxes[0].x, boxes[0].y + i*70, boxes[0].w, boxes[0].h};
      SDL_SetRenderDrawColor(gRenderer, 0, 30, 105, 255);
      SDL_RenderFillRect(gRenderer, &boxes[i]);
      gText.loadFromRenderedText(strs[i], White, 0, gFont);
      gText.render(boxes[i].x, boxes[i].y);
    }
    for(int i = 6; i < numBoxes; i++) {
      boxes[i] = {boxes[6].x, boxes[6].y + (i-6)*70, boxes[6].w, boxes[6].h};
      SDL_SetRenderDrawColor(gRenderer, 0, 50, 35, 255);
      SDL_RenderFillRect(gRenderer, &boxes[i]);
      gText.loadFromRenderedText(strs[i], White, 0, gFont);
      gText.render(boxes[i].x, boxes[i].y);
    }
    for(int i = 0; i < 7; i++) {
      gText.loadFromRenderedText(newstrs[i], White, 0, gMonoFont);
      gText.render(boxes[i+6].x+camera.w/14, boxes[i+6].y+camera.h/120);
    }
    break;
  }
}

void Menu::handleEvent(SDL_Event& e) {
  bool mouseLeft;
  mouseLeft = SDL_GetMouseState(&mouseX, &mouseY) == 1;
  switch(menuScreenID) {
  case scrMainMenu:
    numBoxes = 2;
    mouseBox = {mouseX,mouseY,5,5};
    //start
    boxes[0] = {325, 420, 160, 65};
    //load
    boxes[1] = {535, 420, 170, 70};


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

	if(checkCollision(mouseBox,boxes[0])) {
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
      menuScreenID = scrAttic;
    }

    break;
  case scrAttic:
    numBoxes = 6;
    mouseBox = {mouseX,mouseY,5,5};

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
      }
    } else {
      pressedKey[pressedKeys{mleft}] = false;
    }
    break;
  case scrNone:
    break;
  }
}

Menu menu;
