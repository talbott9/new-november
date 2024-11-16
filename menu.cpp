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
    //gMenuBG.render(camera.x,camera.y);

    gText.loadFromRenderedText("Start", Blue1, 0, gBigFancyFont);
    gText.render(330, 425);
    gText.loadFromRenderedText("Load", Blue1, 0, gBigFancyFont);
    gText.render(540, 425);
     
    break;
  case scrAttic:
    gAtticBG.render(camera.x,camera.y);
    ;
    std::string dayStr = "Day ";
    for(int j = 0; j < 2-std::to_string(day).length(); j++) {
      dayStr += " ";
    }
    dayStr += std::to_string(day);

    gText.loadFromRenderedText(dayStr, White, 0, gBigFancyFont);
    gText.render(camera.w-camera.w/5, camera.y+camera.h/32);
    
    numBoxes = 13;
    boxes[0].w = 100;
    boxes[0].h = 50;
    boxes[0].x = camera.w - camera.w/8;
    boxes[0].y = camera.y + camera.h/6;
    strs[0] = "Schedule";
    strs[1] = "Items";
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

    if(showSchedule[1]) {
      strs[20] = "Work";
      strs[21] = "Study";
      strs[22] = "Leisure";
      boxes[7] = {camera.x + camera.w/4, camera.y + camera.h/8, 160, 50};
      for(int i = 7; i < 10; i++) {
	boxes[i] = {boxes[7].x + (i-7)*220, boxes[7].y, boxes[7].w, boxes[7].h};
	SDL_SetRenderDrawColor(gRenderer, 0, 30, 105, 255);
	SDL_RenderFillRect(gRenderer, &boxes[i]);
	gText.loadFromRenderedText(strs[i+13], White, 0, gFontBig1);
	gText.render(boxes[i].x, boxes[i].y);
      }

      
      for(int j = 0; j < 3; j++) {
	int renderX = 0;
	if(j == 0) {
	  strs[23] = "Cobble";
	  strs[24] = "Cafe'";
	  strs[25] = "";
	  strs[26] = "";
	  strs[27] = "";
	  strs[28] = "";
	} else if(j == 1) {
	  strs[29] = "Philosophy";
	  strs[30] = "Poetry";
	  strs[31] = "Theology";
	  strs[32] = "History";
	  strs[33] = "Mathematics";
	  strs[34] = "Romance";
	  renderX = 220;
	} else if(j == 2) {
	  strs[35] = "Rest";
	  strs[36] = "Walk";
	  strs[37] = "Fencing";
	  strs[38] = "";
	  strs[39] = "";
	  strs[40] = "Go out";
	  renderX = 220*2;
	}
	 boxes[10+6*j] = {camera.x + camera.w/4 + renderX, camera.y + camera.h/8*2.25, 140, 50};
	for(int i = 10+6*j; i < 16+6*j; i++) {
	  boxes[i] = {boxes[10+6*j].x, boxes[10+6*j].y + (i-10-6*j)*50, boxes[10+6*j].w, boxes[10+6*j].h};
	  SDL_SetRenderDrawColor(gRenderer, 0, 30, 105, 255);
	  SDL_RenderFillRect(gRenderer, &boxes[i]);
	  gText.loadFromRenderedText(strs[i+13], White, 0, gFont);
	  gText.render(boxes[i].x, boxes[i].y);
	}
      }
    } else if(showSchedule[0]) {
      strs[20] = "Morning";
      strs[21] = "Afternoon";
      strs[22] = "Evening";

      for(int i = 0; i < 3; i++) {
	switch(player.scheduleID[i]) {
	case schNothing:
	  strs[23+i] = "Rest";
	  break;
	case schCobble:
	  strs[23+i] = "Cobble";
	  break;
	case schCafe:
	  strs[23+i] = "Cafe'";
	  break;
	case schPhilosophy:
	  strs[23+i] = "Philosophy";
	  break;
	case schPoetry:
	  strs[23+i] = "Poetry";
	  break;
	case schTheology:
	  strs[23+i] = "Theology";
	  break;
	case schHistory:
	  strs[23+i] = "History";
	  break;
	case schMathematics:
	  strs[23+i] = "Mathematics";
	  break;
	case schRomance:
	  strs[23+i] = "Romance";
	  break;
	case schWalk:
	  strs[23+i] = "Walk";
	  break;
	case schFencing:
	  strs[23+i] = "Fencing";
	  break;
	case schVisit:
	  strs[23+i] = "Go out";
	  break;
	}
      }
      
      boxes[7] = {camera.x + camera.w/4, camera.y + camera.h/8, 160, 50};
      for(int i = 7; i < 10; i++) {
	boxes[i] = {boxes[7].x + (i-7)*220, boxes[7].y, boxes[7].w, boxes[7].h};
	SDL_SetRenderDrawColor(gRenderer, 0, 30, 105, 255);
	SDL_RenderFillRect(gRenderer, &boxes[i]);
	gText.loadFromRenderedText(strs[i+13], White, 0, gFontBig1);
	gText.render(boxes[i].x, boxes[i].y);
      }
      boxes[10] = {camera.x + camera.w/4, camera.y + camera.h/8*2.25, 160, 160};
      for(int i = 10; i < 13; i++) {
	boxes[i] = {boxes[10].x + (i-10)*220, boxes[10].y, boxes[10].w, boxes[10].h};
	SDL_SetRenderDrawColor(gRenderer, 0, 30, 105, 255);
	SDL_RenderFillRect(gRenderer, &boxes[i]);
	gText.loadFromRenderedText(strs[i+13], White, 0, gFont);
	gText.render(boxes[i].x, boxes[i].y);
      }
    }

        
    //items
    if(showItems[0]) {
      SDL_Rect genRect = {camera.x + camera.w/4, camera.y + camera.h/8,500,400};
      SDL_SetRenderDrawColor(gRenderer, 0, 30, 105, 255);
      SDL_RenderFillRect(gRenderer, &genRect);
      boxes[6] = {camera.x + camera.w/4*1.15, camera.y + camera.h/8*1.35, 175, 50};
      for(int i = 7; i < 13; i++) {
	boxes[i] = {boxes[6].x, boxes[6].y + (i-7)*55, boxes[6].w, boxes[6].h};
	//SDL_SetRenderDrawColor(gRenderer, 0, 60, 105, 255);
	//SDL_RenderFillRect(gRenderer, &boxes[i]);
	//	gText.loadFromRenderedText(strs[i], White, 0, gFont);
	//gText.render(boxes[i].x, boxes[i].y);
      }
      boxes[13] = {camera.x + camera.w/4*1.15 + 175*1.30, camera.y + camera.h/8*1.35, 175, 50};
      for(int i = 13; i < 19; i++) {
	boxes[i] = {boxes[13].x, boxes[13].y + (i-13)*55, boxes[13].w, boxes[13].h};
	//SDL_SetRenderDrawColor(gRenderer, 0, 60, 105, 255);
	//SDL_RenderFillRect(gRenderer, &boxes[i]);
	//	gText.loadFromRenderedText(strs[i], White, 0, gFont);
	//gText.render(boxes[i].x, boxes[i].y);
      }
      for(int i = 7; i < 19; i++) {
	if(player.heldItems[itemOldSword] && !listedItem[itemOldSword]) {
	  itemStrings[i] = "Old sword";
	  listedItem[itemOldSword] = true;
	}
	else if(player.heldItems[itemRags] && !listedItem[itemRags]) {
	  itemStrings[i] = "Rags";
	  listedItem[itemRags] = true;
	}
	gText.loadFromRenderedText(itemStrings[i], White, 0, gFont);
	gText.render(boxes[i].x, boxes[i].y);
      }
    }
    
    break;
  }
}

void Menu::handleEvent(SDL_Event& e) {
  bool mouseLeft, mouseRight;
  mouseLeft = SDL_GetMouseState(&mouseX, &mouseY) == 1;
  mouseRight = SDL_GetMouseState(&mouseX, &mouseY) == 4;
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
      menuScreenID = scrNone;
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

    if(showSchedule[1]) {
      for(int i = 10; i < 28; i++) {
	if(checkCollision(mouseBox,boxes[i])) {
	  SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);	
	  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 100);
	  SDL_RenderFillRect(gRenderer, &boxes[i]);
	}
      }
    }
    else if(showSchedule[0]) {
      for(int i = 10; i < 13; i++) {
	if(checkCollision(mouseBox,boxes[i])) {
	  SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);	
	  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 100);
	  SDL_RenderFillRect(gRenderer, &boxes[i]);
	}
      }
    } else if(showItems[0]) {
      bool touched = false;
      for(int i = 7; i < 19; i++) {
	if(checkCollision(mouseBox,boxes[i])) {
	  touched = true;
	  if(itemStrings[i] == "Old sword") {
	    if(sceneID != atticoldsword) {
	      cutscene.reset();
	      sceneID = atticoldsword;
	    }
	  } else if(itemStrings[i] == "Rags") {
	    if(sceneID != atticrags) {
	      cutscene.reset();
	      sceneID = atticrags;
	    }
	  }
	}
      }
    
      if(!touched && sceneID != attic1) {
	cutscene.reset();
	sceneID = attic1;
      }
    }

    if(mouseRight) {
      if(!pressedKey[pressedKeys{mright}]) {
	pressedKey[pressedKeys{mright}] = true;
	if(showSchedule[1]) {
	  showSchedule[1] = false;
	}
	else if(showSchedule[0]) {
	  showSchedule[0] = false;
	  showSchedule[1] = false;
	  cutscene.reset();
	  sceneID = attic1;
	}
	if(showItems[0]) {
	  showItems[0] = false;
	}
      }
    } else {
      pressedKey[pressedKeys{mright}] = false;
    }
    
    if(mouseLeft) {
      if(!pressedKey[pressedKeys{mleft}]) {
	pressedKey[pressedKeys{mleft}] = true;
	if(checkCollision(mouseBox,boxes[0])) {
	  showItems[0] = false;
	  if(showSchedule[0]) {
	    sceneID = attic1;
	    cutscene.reset();
	    showSchedule[0] = false;
	    showSchedule[1] = false;
	  } else {
	    sceneID = attic2;
	    cutscene.reset();
	    showSchedule[0] = true;
	  }
	}

	else if(checkCollision(mouseBox,boxes[1])) {
	  if(showItems[0]) {
	    showItems[0] = false;
	  } else {
	    showItems[0] = true;
	    for(int i = 0; i < 50; i++) {
	      listedItem[i] = false;
	    }
	    showSchedule[0] = false;
	    showSchedule[1] = false;
	  }
	}
	
	if(showSchedule[1]) {
	  bool clicked = false;
	  std::string message = "";
	  if(checkCollision(mouseBox,boxes[10])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schCobble;
	    message = "make shoes";
	  } else if(checkCollision(mouseBox,boxes[11])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schCafe;
	    message = "work at the cafe'";
	  } else if(checkCollision(mouseBox,boxes[16])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schPhilosophy;
	    message = "study philosophy";
	  }  else if(checkCollision(mouseBox,boxes[17])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schPoetry;
	    message = "study poetry";
	  }  else if(checkCollision(mouseBox,boxes[18])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schTheology;
	    message = "study theology";
	  }  else if(checkCollision(mouseBox,boxes[19])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schHistory;
	    message = "study history";
	  }  else if(checkCollision(mouseBox,boxes[20])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schMathematics;
	    message = "study mathematics";
	  }  else if(checkCollision(mouseBox,boxes[21])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schRomance;
	    message = "read a romance";
	  }  else if(checkCollision(mouseBox,boxes[22])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schNothing;
	    message = "rest";
	  } else if(checkCollision(mouseBox,boxes[23])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schWalk;
	    message = "take a walk";
	  }  else if(checkCollision(mouseBox,boxes[24])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schFencing;
	    message = "fence";
	  } else if(checkCollision(mouseBox,boxes[27])) {
	    clicked = true;
	    player.scheduleID[chosenSchedule] = schVisit;
	    message = "go out";
	  }
	  
	  if(clicked) {
	    showSchedule[1] = false;
	    cutscene.reset();
	    std::string whatTime = "morning";
	    if(chosenSchedule == 1)
	      whatTime = "afternoon";
	    else if(chosenSchedule == 2)
	      whatTime = "evening";
	    cutscene.scriptLine[0] = "You decide to " + message + " this " + whatTime + ".";
	    sceneID = attic3;
	  }
	}
	else if(showSchedule[0]) {
	  if(checkCollision(mouseBox,boxes[10])) {
	    showSchedule[1] = true;
	    chosenSchedule = 0;
	  }
	  else if(checkCollision(mouseBox,boxes[11])) {
	    showSchedule[1] = true;
	    chosenSchedule = 1;
	  }
	  else if(checkCollision(mouseBox,boxes[12])) {
	    showSchedule[1] = true;
	    chosenSchedule = 2;
	  }
	}
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
