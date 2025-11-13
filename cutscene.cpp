Cutscene::Cutscene() {
  bgSpeed = 5;
  textbox= {camera.x, camera.h - 128 - camera.h/12, 800, 128};
  wrpBnd = textbox.w - textbox.w/6*3.25;
  textX = textbox.x + textbox.w/4.5 - 15;
  textY = textbox.y + textbox.h/5;
  gTextFont = &gFont;
  textColor = {255, 255, 255};
  for(int i = 0; i < NUM_PORTRAITS; i++) {
    charPortrait[i] = new Portrait(false, false, 0, 0, i);
  }
  protagPortrait = new Portrait(false, false, 0, 0, -1);
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
  alpha = 0;
  animTicks = 0;
  animCycle = 0;
  switch(textureID) {
  case 0:
    gTexture = gLSPortrait;
    break;
  case 1:
    gTexture = gHGPortrait;
    break;
  }

  
  sizeX = 2480;
  sizeY = 3508;

  isProtag = false;

  if(textureID == -1) {
    sizeX = 2480*0.35;
    sizeY = 3508*0.35;
    mBox.x = cutscene.textbox.w*0.3;
    mBox.y = cutscene.textbox.y-cutscene.textbox.h*1.5;
    alpha = 255;
    isProtag = true;
  }
}

void Portrait::render() {
  // SDL_Rect clip = {0, 0, 500, 500};
  if(!isProtag) {
    if(!disappear[cutscene.lineNumber] && cutscene.bgAlpha == 255 && (cutscene.bgWaitTicks > cutscene.bgWaitTime[cutscene.lineNumber]*60 || appear2[cutscene.lineNumber])) {
      if(alpha < 255) {
	//if(appear[cutscene.lineNumber])
	alpha += 7;
	//alpha += 10;
	if(alpha > 255)
	  alpha = 255;
      }
    } 
    else if(cutscene.bgAlpha < 255 || disappear[cutscene.lineNumber]) {
      if(alpha > 0) {
	if(disappear[cutscene.lineNumber])
	  alpha -= 7;
	else
	  alpha -= 10;
	if(alpha < 0) {
	  alpha = 0;
	}
      }
    }
    gTexture.setAlpha(alpha);
    gFace[face[cutscene.lineNumber]].setAlpha(alpha);
    gTexture.mWidth = size[0][cutscene.lineNumber];
    gTexture.mHeight = size[1][cutscene.lineNumber];
    gFace[face[cutscene.lineNumber]].mWidth = size[0][cutscene.lineNumber];
    gFace[face[cutscene.lineNumber]].mHeight = size[1][cutscene.lineNumber];
  }

  mBox.x = xy[0][cutscene.lineNumber];
  mBox.y = xy[1][cutscene.lineNumber];
  switch(animationID[cutscene.lineNumber]) {
  case 1:
    mBox.x = xy[0][cutscene.lineNumber] + size[0][cutscene.lineNumber]*0.003*sin(animTicks*PI/180);
    mBox.y = xy[1][cutscene.lineNumber] + size[1][cutscene.lineNumber]*0.003*sin(animTicks*PI/180);
    animTicks += 5;
    if(animTicks > 180) {
      animCycle++;
      animTicks = 0;
      if(animCycle > 1) {
	animCycle = 0;
	animationID[cutscene.lineNumber] = 0;
      }
    }
    break;
  case 2:
    mBox.x = xy[0][cutscene.lineNumber] /*+ size[0][cutscene.lineNumber]*0.003*sin(animTicks*PI/180)*/;
    mBox.y = xy[1][cutscene.lineNumber] + size[1][cutscene.lineNumber]*0.002*sin(animTicks*PI/180);
    animTicks += 10;
    if(animTicks > 180) {
      animCycle++;
      animTicks = 0;
      if(animCycle > 1) {
	animCycle = 0;
	animationID[cutscene.lineNumber] = 0;
      }
    }
    break;
	//jump
  case 3:
    mBox.x = xy[0][cutscene.lineNumber] /*+ size[0][cutscene.lineNumber]*0.003*sin(animTicks*PI/180)*/;
    mBox.y = xy[1][cutscene.lineNumber] - size[1][cutscene.lineNumber]*0.008*sin(animTicks*PI/180);
    animTicks += 30;
    if(animTicks > 180) {
      animCycle++;
      animTicks = 0;
      if(animCycle > 0) {
	animCycle = 0;
	animationID[cutscene.lineNumber] = 0;
      }
    }
    break;
    //shiver
  case 4:
    mBox.x = xy[0][cutscene.lineNumber] + size[0][cutscene.lineNumber]*0.0005*sin(animTicks*PI/180);
    animTicks += 90;
    break;
  }
  
  gTexture.render(mBox.x, mBox.y);
  gFace[face[cutscene.lineNumber]].render(mBox.x, mBox.y);
}

void Portrait::reset() {
  animTicks = 0;
  animCycle = 0;
}


void Cutscene::reset() {
  doNotType = 0;
  charCount = 0;
  gText.free();
  textWritten = "";
  hasIndexedScript = false;
  lineNumber = 0;
  bgWaitTicks = 0;
  selectedChoice = -1;
  choiceAlpha = 255;
  choiceCycle = 0;
  chosenPath = 0;
  choiceTicks = 0;
  mouseIsOnChoice = false;
}

void Cutscene::addL(charIDEnum characterID, std::string s, bool addQuotes) {
  std::string name = "";
  switch(characterID) {
  case clerk:
    name = "Clerk";
    break;
  case mom:
    name = "Mom";
    break;
  case nathan:
    name = "Nathan";
    break;
  case mary:
    name = "Mary";
    break;
  case catie:
    name = "Catie";
    break;
  case unknown:
    name = "???";
    break;
  case link:
    name = "Link";
    break;
  case hal:
    name = "Hal";
    break;
  case all:
	name = "All";
  case marycatie:
	name = "M. & C.";
	break;
  }
  charName.push_back(name);
  std::string msg = "";
  if(characterID != none && addQuotes)
    msg += "\"";
  msg += s;
  if(characterID != none && addQuotes)
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

//type 3 - fade in, type 5 - fade in w/ pause
//type 4 - fade out, type 2 - fade out with pause
void Cutscene::changeShowCharacter(charIDEnum characterID, portraitFace fac, int x, int y, int w, int h, int textureNumber, bool shew, int type) {
  if(characterID == protag) {
    protagPortrait->alpha = 255;
    protagPortrait->face.resize(scriptLine.size());
    while(protagPortrait->face.size() < NUM_SCRIPT_LINES)
      protagPortrait->face.push_back(fac);
    if(shew != -1) {
      protagPortrait->show.resize(scriptLine.size());
      while(protagPortrait->show.size() < NUM_SCRIPT_LINES)
	protagPortrait->show.push_back(shew);
    }

    protagPortrait->xy[0].resize(scriptLine.size());
    while(protagPortrait->xy[0].size() < NUM_SCRIPT_LINES)
      protagPortrait->xy[0].push_back(protagPortrait->mBox.x);
    
    protagPortrait->xy[1].resize(scriptLine.size());
    while(protagPortrait->xy[1].size() < NUM_SCRIPT_LINES)
      protagPortrait->xy[1].push_back(protagPortrait->mBox.y);

    protagPortrait->size[0].resize(scriptLine.size());
    while(protagPortrait->size[0].size() < NUM_SCRIPT_LINES)
      protagPortrait->size[0].push_back(protagPortrait->gTexture.mWidth);

    protagPortrait->size[1].resize(scriptLine.size());
    while(protagPortrait->size[1].size() < NUM_SCRIPT_LINES)
      protagPortrait->size[1].push_back(protagPortrait->gTexture.mHeight);
    
    
  } else {
    if(type == 5) {
      bgWaitTime.resize(scriptLine.size());
      bgWaitTime.push_back(1);
      addL(none, "");
      // charPortrait[characterID]->alpha = 0;
      charPortrait[characterID]->appear[scriptLine.size()-1] = true;
      charPortrait[characterID]->appear2[scriptLine.size()-1] = true;
    }
    else if(type == 3) {
      //charPortrait[characterID]->alpha = 0;
      charPortrait[characterID]->appear[scriptLine.size()] = true;
    }
    else if(type == 2) {
      bgWaitTime.resize(scriptLine.size());
      bgWaitTime.push_back(1);
      addL(none, "");
      charPortrait[characterID]->disappear[scriptLine.size()-1] = true;
    }
    else if(type == 4) {
      charPortrait[characterID]->disappear[scriptLine.size()-1] = true;
    }
    
    charPortrait[characterID]->face.resize(scriptLine.size());
    while(charPortrait[characterID]->face.size() < NUM_SCRIPT_LINES)
      charPortrait[characterID]->face.push_back(fac);

    if(shew != -1 && type != 2) {
      charPortrait[characterID]->show.resize(scriptLine.size());
      while(charPortrait[characterID]->show.size() < NUM_SCRIPT_LINES)
	charPortrait[characterID]->show.push_back(shew);
    }
    
    if(textureNumber != -1)
      determineTexture(characterID, textureNumber);
    if(w != -1) {
      charPortrait[characterID]->size[0].resize(scriptLine.size());
      while(charPortrait[characterID]->size[0].size() < NUM_SCRIPT_LINES)
	charPortrait[characterID]->size[0].push_back(w);
    }
    if(h != -1) {
      charPortrait[characterID]->size[1].resize(scriptLine.size());
      while(charPortrait[characterID]->size[1].size() < NUM_SCRIPT_LINES)
	charPortrait[characterID]->size[1].push_back(h);
    }
    if(x != -1) {
      charPortrait[characterID]->xy[0].resize(scriptLine.size());
      while(charPortrait[characterID]->xy[0].size() < NUM_SCRIPT_LINES)
	charPortrait[characterID]->xy[0].push_back(x);
    }
    if(y != -1) {
      charPortrait[characterID]->xy[1].resize(scriptLine.size());
      while(charPortrait[characterID]->xy[1].size() < NUM_SCRIPT_LINES)
	charPortrait[characterID]->xy[1].push_back(y);
    }
  }
  changeShowChar.resize(scriptLine.size());
  changeShowChar.push_back(true);
}
void Cutscene::doAnim(charIDEnum characterID, int animID) {
  if(characterID == protag)
    protagPortrait->animationID[scriptLine.size()] = animID;
  else
    charPortrait[characterID]->animationID[scriptLine.size()] = animID;
}

void Cutscene::determineTexture(charIDEnum characterID, int textureNumber) {
  switch(textureNumber) {
  case 0:
    switch(characterID) {
    case nathan:
      charPortrait[characterID]->gTexture = gLSPortrait;
      break;
    case mary:
      charPortrait[characterID]->gTexture = gHGPortrait;
      break;
    case catie:
      charPortrait[characterID]->gTexture = gCatiePortrait;
      break;
	case link:
      charPortrait[characterID]->gTexture = gLinkPortrait;
      break;
	case hal:
      charPortrait[characterID]->gTexture = gHalPortrait;
      break;
    }
    break;
  }
  for(int i = 0; i < NUM_FACES; i++)
    charPortrait[characterID]->gFace[i] = gCharFace[characterID][i];
}

void Cutscene::changeBackground(bgIDEnum id, int wait) {
  int size = scriptLine.size();
  bgID.resize(size);
  changeBg.resize(size);
  bgWaitTime.resize(size);
  bgID.push_back(id);
  changeBg.push_back(true);
  bgWaitTime.push_back(wait);
  if(wait != 0)
    addL(none, "");
}

void Cutscene::doWait(int wait) {
  int size = scriptLine.size();
  bgWaitTime.resize(size);
  bgWaitTime.push_back(wait);
  addL(none, "");
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
    if(skipTextTicks%3 == 0 && skipTextTicks > 0) {
      doNotType = 0;
      charCount = 0;
      gText.free();
      textWritten = "";
      protagPortrait->reset();
      for(int i = 0; i < NUM_CHARS; i++) {
	charPortrait[i]->reset();
	if(charPortrait[i]->disappear[lineNumber]) {
	  charPortrait[i]->show.resize(scriptLine.size());
	  while(charPortrait[i]->show.size() < NUM_SCRIPT_LINES)
	    charPortrait[i]->show.push_back(false);
	}
	if(charPortrait[i]->appear[lineNumber]) {
	  charPortrait[i]->show.resize(scriptLine.size());
	  while(charPortrait[i]->show.size() < NUM_SCRIPT_LINES)
	    charPortrait[i]->show.push_back(true);
	}
      }
      lineNumber++;
      bgWaitTicks = 0;
    } else {
      doNotType = 1;
    }
    for(int i = 0; i < NUM_CHARS; i++) {
      charPortrait[i]->alpha = 255;
    }
    skipTextTicks++;
  } /*else {
    bgAlpha = 255;
    bgWaitTicks = BIG_NUMBER;
    }*/
}

void Cutscene::choiceBoxAnim() {
  if(mouseIsOnChoice) {
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
}

void Cutscene::handleEvent(SDL_Event& e, bool controller) {
  bool upKey, downKey, leftKey, rightKey, zKey, xKey, cKey, lShiftKey, escKey, lCtrlKey;
  bool mouseLeft;
  int mouseX, mouseY;
  mouseIsOnChoice = false;
  mouseLeft = SDL_GetMouseState(&mouseX, &mouseY) == 1;
  mouseBox = {mouseX,mouseY,1,1};
  if(!controller) {
    upKey = currentKeyStates[SDL_SCANCODE_UP];
    downKey = currentKeyStates[SDL_SCANCODE_DOWN];
    leftKey = currentKeyStates[SDL_SCANCODE_LEFT];
    rightKey = currentKeyStates[SDL_SCANCODE_RIGHT];
    zKey = currentKeyStates[SDL_SCANCODE_RETURN] || currentKeyStates[SDL_SCANCODE_KP_ENTER] || currentKeyStates[SDL_SCANCODE_SPACE] ;
    xKey = currentKeyStates[SDL_SCANCODE_X];
    cKey = currentKeyStates[SDL_SCANCODE_C];
    lShiftKey = currentKeyStates[SDL_SCANCODE_LSHIFT];
    escKey = currentKeyStates[SDL_SCANCODE_ESCAPE];
    lCtrlKey = currentKeyStates[SDL_SCANCODE_LCTRL] || currentKeyStates[SDL_SCANCODE_RCTRL];
  }
    if(canAdvance && !tobasu) {
      if(zKey || mouseLeft) {
	if(!pressedKey[z]) {
	  if(charCount < scriptLine[lineNumber].size()) {
	    doNotType = 1;
	  } else {
	    doNotType = 0;
	    charCount = 0;
	    gText.free();
	    textWritten = "";
	    protagPortrait->reset();
	    for(int i = 0; i < NUM_CHARS; i++) {
	      charPortrait[i]->reset();
	      if(charPortrait[i]->disappear[lineNumber]) {
		charPortrait[i]->show.resize(scriptLine.size());
		while(charPortrait[i]->show.size() < NUM_SCRIPT_LINES)
		  charPortrait[i]->show.push_back(false);
	      }
	      if(charPortrait[i]->appear[lineNumber]) {
		charPortrait[i]->show.resize(scriptLine.size());
		while(charPortrait[i]->show.size() < NUM_SCRIPT_LINES)
		  charPortrait[i]->show.push_back(true);
	      }
	    }
	    lineNumber++;
	    bgWaitTicks = 0;
	  }
	}
        pressedKey[z] = true;
      } else {
	pressedKey[z] = false;
      }
    }
    if(lCtrlKey) {
      if(!hasTobasu)
	tobasu = true;
      hasTobasu = true;
    } else {
      tobasu = false;
      skipTextTicks = 0;
      if(hasTobasu) {
	//something
      }
      hasTobasu = false;
    }

    if(isChoice[lineNumber]) {
      choiceTicks++;
      if(choiceTicks > 30) {
	bool chose = false;
	if(upKey) {
	  if(!pressedKey[up]) {
	    /*
	    selectedChoice--;
	    if(selectedChoice < 0)
	    selectedChoice = 0;*/
	    SDL_WarpMouseInWindow(gWindow, choiceBoxes[0].x + choiceBoxes[0].w/1.25, choiceBoxes[0].y + choiceBoxes[0].h/2);
	  }
	  pressedKey[up] = true;
	} else {
	  pressedKey[up] = false;
	}
	if(downKey) {
	  if(!pressedKey[down]) {
	    /*
	    selectedChoice++;
	    if(selectedChoice >= numChoiceBoxes[lineNumber])
	    selectedChoice = numChoiceBoxes[lineNumber]-1;*/
	    SDL_WarpMouseInWindow(gWindow, choiceBoxes[1].x + choiceBoxes[1].w/1.25, choiceBoxes[1].y + choiceBoxes[1].h/2);
	  }
	  pressedKey[down] = true;
	} else {
	  pressedKey[down] = false;
	}
      
	if(zKey) {
	  if(!pressedKey[z]) {
	    chose = true;
	  }
	  pressedKey[z] = true;
	} else {
	  pressedKey[z] = false;
	}
      
	for(int i = 0; i < numChoiceBoxes[lineNumber]; i++) {
	  if(checkCollision(mouseBox,choiceBoxes[i])) {
	    mouseIsOnChoice = true;
	    selectedChoice = i;
	    if(mouseLeft) {
	      if(!pressedKey[mleft])
		chose = true;
	      pressedKey[mleft] = true;
	    } else {
	      pressedKey[mleft] = false;
	    }
	  }
	}
	if(chose && selectedChoice != -1) {
	  canAdvance = true;
	  determineScene(sceneID, selectedChoice);
	  reset();
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
    case bgStreet1Evening:
      gBackground = gStreet1EveningBG;
      break;
    case bgStreet2:
      gBackground = gStreet2BG;
      break;
    case bgLivingRoom:
      gBackground = gLivingRoomBG;
      break;
    case bgGrocery:
      gBackground = gGroceryBG;
      break;
    case bgStore:
      gBackground = gStoreBG;
      break;
    case bgStoreInside:
      gBackground = gStoreInsideBG;
      break;
    }
    bgAlpha = 0;
    bgWaitTicks = 0;
    changeBg[lineNumber] = false;
  }
  /*
  if(changeShowChar[lineNumber]) {
    for(int i = 0; i < NUM_CHARS; i++) {
      if(charPortrait[i]->show) {
	showChar[i] = true;
      } else {
	showChar[i] = false;
      }
    }
    if(protagPortrait->show)
      showProtag = true;
    else
      showProtag = false;
    changeShowChar[lineNumber] = false;
    }*/
  
  bgAlpha += bgSpeed;
  if(bgAlpha > 255) {
    bgAlpha = 255;
    gOldBackground = gBackground;
  }
  if(bgAlpha < 255)
    gOldBackground.render(0,0);
  gBackground.setAlpha(bgAlpha);
  gBackground.render(0,0);

  bool disp = false;
  for(int i = 0; i < NUM_CHARS; i++) {
    if(charPortrait[i]->disappear[lineNumber]) {
      disp = true;
      if(charPortrait[i]->alpha == 0) {
	charPortrait[i]->disappear[lineNumber] = false;
	charPortrait[i]->show.clear();
	while(charPortrait[i]->show.size() < NUM_SCRIPT_LINES)
	  charPortrait[i]->show.push_back(false);
      }
    }
    if(charPortrait[i]->appear[lineNumber]) {
      charPortrait[i]->show.clear();
      while(charPortrait[i]->show.size() < NUM_SCRIPT_LINES)
	charPortrait[i]->show.push_back(true);
      if(!charPortrait[i]->disappear[lineNumber])
	charPortrait[i]->alpha = 0;
      charPortrait[i]->appear[lineNumber] = false;
    }
	
    if(charPortrait[i]->show[lineNumber]) 
      charPortrait[i]->render();
  }
  
  if(menu.blurAlpha == 0 && bgAlpha == 255 && bgWaitTicks > bgWaitTime[lineNumber]*60) {
    if(!(lineNumber >= totalNumberOfLines)) {
      gTextbox.render(textbox.x,textbox.y);
      if(isChoice[lineNumber]) {
	canAdvance = false;
	choiceBoxAnim();
      }
      if(protagPortrait->show[lineNumber]) {
	protagPortrait->render();
      }
      drawDialogueText(scriptLine[lineNumber]);
    } else {
      reset();
      menuScreenID = scrMainMenu;
      menu.reset();
      sceneID = scene0;
      for(int i = 0; i < NUM_CHARS; i++) {
	showChar[i] = false;
	charPortrait[i]->reset();
      }
      gOldBackground.mTexture = NULL;
    }
  } else {
    canAdvance = false;
  }
  if(tobasu)
    skipText();
}
