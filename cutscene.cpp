Cutscene::Cutscene() {
  textbox= {camera.x, camera.h - 128 - camera.h/12, 800, 128};
  wrpBnd = textbox.w - textbox.w/6*2;
  textX = textbox.x + textbox.w/4.5;
  textY = textbox.y + textbox.h/5;
  gTextFont = &gFont;
  for(int i = 0; i < NUM_PORTRAITS; i++) {
    for(int j = 0; j < NUM_SCRIPT_LINES; j++)
      charFace[i][j] = neutralFace;
  }
}

Portrait::Portrait(bool changeM, bool mov, int x, int y) {
  changeMove = changeM;
  moved = mov;
  defaultPosX = x;
  defaultPosY = y;
  posX = x;
  posY = y;
  mBox.x = x;
  mBox.y = y;
  dx = 0;
  dy = 0;
  reachedTarget = true;
  distance = 0;
  darkenTicks = 155;
  changedMove = 0;
  targetX = x;
}

void Portrait::render() {
  gTexture->render(posX, posY);
}

void Cutscene::drawDialogueText(std::string s) {
  //drawTicks++;
  gText.loadFromRenderedText(charName[lineNumber], White, wrpBnd, *gTextFont);
  gText.render(textX-75, textY);
  if(!doNotType) {
    if(!pause) {
      if(charCount < scriptLine[lineNumber].size()) {
	if(s[charCount] != '\\') {
	  textWritten += s[charCount]; charCount++;
	} else {
	  textWritten += "\n           "; charCount++;
	}
      }
    }
    gText.loadFromRenderedText(textWritten, White, wrpBnd, *gTextFont);
    gText.render(textX+25, textY);
	
  } else {
    if(!pause) {
      while(charCount < scriptLine[lineNumber].size()) {
	if(s[charCount] != '\\') {
	  textWritten += s[charCount]; charCount++;
	} else {
	  textWritten += "\n           "; charCount++;
	}
      }
    }
    gText.loadFromRenderedText(textWritten, White, wrpBnd, *gTextFont);
    gText.render(textX+25, textY);
  }
}

void Cutscene::handleEvent(SDL_Event& e, bool controller) {
  bool upKey, downKey, leftKey, rightKey, zKey, xKey, cKey, lShiftKey, escKey, lCtrlKey;
  bool mouseLeft;
  int mouseX, mouseY;
  mouseLeft = SDL_GetMouseState(&mouseX, &mouseY) == 1;
    if(!controller) {
      upKey = currentKeyStates[SDL_SCANCODE_UP];
      downKey = currentKeyStates[SDL_SCANCODE_DOWN];
      leftKey = currentKeyStates[SDL_SCANCODE_LEFT];
      rightKey = currentKeyStates[SDL_SCANCODE_RIGHT];
      zKey = currentKeyStates[SDL_SCANCODE_Z] || currentKeyStates[SDL_SCANCODE_J] || currentKeyStates[SDL_SCANCODE_RETURN] || currentKeyStates[SDL_SCANCODE_KP_ENTER];
      xKey = currentKeyStates[SDL_SCANCODE_X];
      cKey = currentKeyStates[SDL_SCANCODE_C];
      lShiftKey = currentKeyStates[SDL_SCANCODE_LSHIFT];
      escKey = currentKeyStates[SDL_SCANCODE_ESCAPE];
      lCtrlKey = currentKeyStates[SDL_SCANCODE_LCTRL];
    } else {
      upKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) || currentKeyStates[SDL_SCANCODE_UP];
      downKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_LEFTSHOULDER) || currentKeyStates[SDL_SCANCODE_DOWN];
      leftKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_LEFT) || currentKeyStates[SDL_SCANCODE_LEFT];
      rightKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || currentKeyStates[SDL_SCANCODE_RIGHT];
      zKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A) || currentKeyStates[SDL_SCANCODE_Z]  || currentKeyStates[SDL_SCANCODE_J] || currentKeyStates[SDL_SCANCODE_RETURN] || currentKeyStates[SDL_SCANCODE_KP_ENTER];
      xKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_Y) || currentKeyStates[SDL_SCANCODE_X];
      lCtrlKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_B) || currentKeyStates[SDL_SCANCODE_LCTRL];
      lShiftKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_X) || currentKeyStates[SDL_SCANCODE_LSHIFT];
      escKey = SDL_GameControllerGetButton(gGameController, SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_START) || currentKeyStates[SDL_SCANCODE_ESCAPE];
    }
    if(canAdvance) {
      if(zKey || mouseLeft) {
	if(!advancedDialogue) {
	  if(charCount < scriptLine[lineNumber].size()) {
	    doNotType = 1;
	  } else {
	    doNotType = 0;
	    charCount = 0;
	    gText.free();
	    textWritten = "";
	    lineNumber++;
	  }
	}
	advancedDialogue = true;
      } else {
	advancedDialogue = false;
      }
    }
    if(lCtrlKey) {
      if(!hasTobasu)
	tobasu = true;
      hasTobasu = true;
    } else {
      tobasu = false;
      if(hasTobasu) {
	//something
      }
      hasTobasu = false;
    }
}

void Cutscene::play() {
  canAdvance = true;
  switch(bgID) {
  case street1:
    break;
  }
  if(menuScreenID == scrAttic)
    canAdvance = false;
  if(menu.blurAlpha == 0) {
    if(createdPortrait[0]) 
      charPortrait[0]->render();
    gTextbox.render(textbox.x,textbox.y);
    indexScript();
    if(!(lineNumber >= totalNumberOfLines))
      drawDialogueText(scriptLine[lineNumber]);
  }
}
