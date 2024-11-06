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
  gText.loadFromRenderedText(charName, White, wrpBnd, *gTextFont);
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
    gText.render(textX, textY);
	
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
    gText.render(textX, textY);
  }
}

void Cutscene::play() {
  switch(bgID) {
  case street1:
    gStreet1BG.render(0,0);
    break;
  }
  if(menu.blurAlpha == 0) {
    if(createdPortrait[0]) 
      charPortrait[0]->render();
    gTextbox.render(textbox.x,textbox.y);
    indexScript();
    if(!(lineNumber >= totalNumberOfLines))
      drawDialogueText(scriptLine[lineNumber]);
  }
}
