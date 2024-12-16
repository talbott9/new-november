Cutscene::Cutscene() {
  bgSpeed = 5;
  textbox= {camera.x, camera.h - 128 - camera.h/12, 800, 128};
  wrpBnd = textbox.w - textbox.w/6*3;
  textX = textbox.x + textbox.w/4.5;
  textY = textbox.y + textbox.h/5;
  gTextFont = &gFont;
  for(int i = 0; i < NUM_PORTRAITS; i++) {
    charPortrait[i] = new Portrait(false, false, 0, 0, i);
  }
  for(int i = 0; i < 3; i++)
    choiceBoxes[i] = {textX, textY + 35*i, textbox.w-textbox.w/6*3, 35};
  choiceAlpha = 100;
}

Portrait::Portrait(bool changeM, bool mov, int x, int y, int textureID) {
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
  show = false;
  alpha = 0;
  switch(textureID) {
  case 0:
    gTexture = &gLSPortrait;
    break;
  case 1:
    gTexture = &gHGPortrait;
    break;
  }
}

void Portrait::render() {
  gTexture->render(posX, posY);
}


void Cutscene::reset() {
  doNotType = 0;
  charCount = 0;
  gText.free();
  textWritten = "";
  hasIndexedScript = false;
  lineNumber = 0;
  bgWaitTicks = 0;
}

void Cutscene::addL(charIDEnum characterID, std::string s) {
  std::string name = "";
  switch(characterID) {
  case mom:
    name = "Mom";
    break;
  case nathan:
    name = "Nathan";
    break;
  case mary:
    name = "Mary";
    break;
  }
  charName.push_back(name);
  std::string msg = "";
  if(characterID != none)
    msg += "\"";
  msg += s;
  if(characterID != none)
    msg += "\"";
  scriptLine.push_back(msg);
}

void Cutscene::addChoice(int number, std::string c1, std::string c2, std::string c3) {
  scriptLine.push_back("");
  strChoices[0] = c1;
  strChoices[1] = c2;
  strChoices[2] = c3;
  isChoice[scriptLine.size()-1] = true;
  numChoiceBoxes[scriptLine.size()-1] = number;
}

void Cutscene::changeShowCharacter(charIDEnum characterID, bool show) {
  charPortrait[characterID]->show = show;
  changeShowChar.resize(scriptLine.size());
  changeShowChar.push_back(true);
}

void Cutscene::changeBackground(bgIDEnum id, int wait) {
  int size = scriptLine.size();
  bgID.resize(size);
  changeBg.resize(size);
  bgWaitTime.resize(size);
  bgID.push_back(id);
  changeBg.push_back(true);
  bgWaitTime.push_back(wait);
}


void Cutscene::drawDialogueText(std::string s) {
  //drawTicks++;
  if(isChoice[lineNumber]) {
    for(int i = 0; i < numChoiceBoxes[lineNumber]; i++) {
      gText.loadFromRenderedText(strChoices[i], Grey, wrpBnd, gFontOutline);
      gText.render(textX+25, textY + (choiceBoxes[0].h)*i);
      gText.loadFromRenderedText(strChoices[i], White, wrpBnd, gFont);
      gText.render(textX+25, textY + (choiceBoxes[0].h)*i);
    }
  } else {
    if(charName[lineNumber] != "") {
      gText.loadFromRenderedText(charName[lineNumber], Grey, wrpBnd, gFontOutline);
      gText.render(textX-75, textY);
      gText.loadFromRenderedText(charName[lineNumber], White, wrpBnd, gFont);
      gText.render(textX-75, textY);
    }
    if(!doNotType) {
      if(!pause) {
	if(charCount < scriptLine[lineNumber].size()) {
	  if(s[charCount] != '\\') {
	    textWritten += s[charCount]; charCount++;
	  } else {
	    textWritten += "\n"; charCount++;
	  }
	}
      }
      gText.loadFromRenderedText(textWritten, Grey, wrpBnd, gFontOutline);
      gText.render(textX+25, textY);
      gText.loadFromRenderedText(textWritten, White, wrpBnd, gFont);
      gText.render(textX+25, textY);
	
    } else {
      if(!pause) {
	while(charCount < scriptLine[lineNumber].size()) {
	  if(s[charCount] != '\\') {
	    textWritten += s[charCount]; charCount++;
	  } else {
	    textWritten += "\n"; charCount++;
	  }
	}
      }
      gText.loadFromRenderedText(textWritten, Grey, wrpBnd, gFontOutline);
      gText.render(textX+25, textY);
      gText.loadFromRenderedText(textWritten, White, wrpBnd, gFont);
      gText.render(textX+25, textY);
    }
  }
}


void Cutscene::skipText() {
  if(canAdvance) {
    skipTextTicks++;
    if(skipTextTicks%3 == 0) {
      doNotType = 0;
      charCount = 0;
      gText.free();
      textWritten = "";
      lineNumber++;
    } else {
      doNotType = 1;
    }
  } else {
    bgAlpha = 255;
    bgWaitTicks = BIG_NUMBER;
  }
}

void Cutscene::choiceBoxAnim() {
  if(selectedChoice >= 0) {
    if(choiceCycle == 0) {
      choiceAlpha -= 4;
      if(choiceAlpha <= 50) {
	choiceAlpha = 50;
	choiceCycle = 1;
      }
    } else if(choiceCycle == 1) {
      choiceAlpha += 4;
      if(choiceAlpha >= 200) {
	choiceAlpha = 200;
	choiceCycle = 0;
      }
    }
    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);	
    SDL_SetRenderDrawColor(gRenderer, 255, 155, 155, choiceAlpha);
    SDL_RenderFillRect(gRenderer, &choiceBoxes[selectedChoice]);
  } else {
    choiceAlpha = 200;
    choiceCycle = 0;
  }
}

void Cutscene::handleEvent(SDL_Event& e, bool controller) {
  bool upKey, downKey, leftKey, rightKey, zKey, xKey, cKey, lShiftKey, escKey, lCtrlKey;
  bool mouseLeft;
  int mouseX, mouseY;
  mouseLeft = SDL_GetMouseState(&mouseX, &mouseY) == 1;
  mouseBox = {mouseX,mouseY,1,1};
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

    if(isChoice[lineNumber]) {
      if(upKey) {
	if(!pressedKey[up]) {
	  selectedChoice--;
	  if(selectedChoice < 0)
	    selectedChoice = 0;
	}
	pressedKey[up] = true;
      } else {
	pressedKey[up] = false;
      }
      if(downKey) {
	if(!pressedKey[down]) {
	  selectedChoice++;
	  if(selectedChoice >= numChoiceBoxes[lineNumber])
	    selectedChoice = numChoiceBoxes[lineNumber]-1;
	}
	pressedKey[down] = true;
      } else {
	pressedKey[down] = false;
      }
      for(int i = 0; i < numChoiceBoxes[lineNumber]; i++) {
	if(checkCollision(mouseBox,choiceBoxes[i])) {
	  selectedChoice = i;
	}
      }
    }
    
}

void Cutscene::play() {
  canAdvance = true;
  indexScript();
  /*SDL_Rect genRect = {0,0,camera.w,camera.h};
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderFillRect(gRenderer, &genRect);*/
  bgWaitTicks++;
  if(bgWaitTicks >= bgWaitTime[lineNumber]*60 && bgWaitTime[lineNumber] > 0)
    lineNumber++;
  
  if(changeBg[lineNumber]) {
    switch(bgID[lineNumber]) {
    case bgStreet1:
      gBackground = gStreet1BG;
      break;
    case bgLivingRoom:
      gBackground = gLivingRoomBG;
      break;
    }
    bgAlpha = 0;
    bgWaitTicks = 0;
    changeBg[lineNumber] = false;
  }

  if(changeShowChar[lineNumber]) {
    for(int i = 0; i < NUM_PORTRAITS; i++) {
      if(charPortrait[i]->show) {
	showChar[i] = true;
      } else {
	showChar[i] = false;
      }
    }
    changeShowChar[lineNumber] = false;
  }
  
  bgAlpha += bgSpeed;
  if(bgAlpha > 255) {
    bgAlpha = 255;
    gOldBackground = gBackground;
  }
  if(bgAlpha < 255)
    gOldBackground.render(0,0);
  gBackground.setAlpha(bgAlpha);
  gBackground.render(0,0);
  
  if(menu.blurAlpha == 0 && bgAlpha == 255 && bgWaitTicks > bgWaitTime[lineNumber]*60) {
    for(int i = 0; i < NUM_PORTRAITS; i++) {
      if(showChar[i]) {
	charPortrait[i]->render();
      }
    }
    if(!(lineNumber >= totalNumberOfLines)) {
      gTextbox.render(textbox.x,textbox.y);
      if(isChoice[lineNumber]) {
	choiceBoxAnim();
	canAdvance = false;
      }
      drawDialogueText(scriptLine[lineNumber]);
    } else {
      reset();
    }
  } else {
    canAdvance = false;
  }

  if(tobasu)
    skipText();
}
