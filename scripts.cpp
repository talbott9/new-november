void Cutscene::indexScript() {
  if(!hasIndexedScript) {
    scriptLine.clear();
    charName.clear();
    charFace.clear();
    changeBg.clear();
    changeShowChar.clear();
    changeShowChar.resize(NUM_SCRIPT_LINES);
    changeBg.resize(NUM_SCRIPT_LINES);
    bgWaitTime.clear();
    bgWaitTime.resize(NUM_SCRIPT_LINES);
    bgID.clear();
    bgID.resize(NUM_SCRIPT_LINES);
    for(int i = 0; i < NUM_PORTRAITS; i++) {
      charPortrait[i]->face.clear();
      charPortrait[i]->face.resize(NUM_SCRIPT_LINES);
    }
    protagPortrait->face.clear();
    protagPortrait->face.resize(NUM_SCRIPT_LINES);
    isChoice.clear();
    isChoice.resize(NUM_SCRIPT_LINES);
    numChoiceBoxes.clear();
    numChoiceBoxes.resize(NUM_SCRIPT_LINES);
    selectedChoice = -1;
    switch(playerChar) {
    case playerLS:
      protagPortrait->gTexture = gLSPortrait;
      for(int i = 0; i < NUM_FACES; i++)
	protagPortrait->gFace[i] = gNathanFace[i];
      switch(friendChar) {
      case friendHG:
	switch(sceneID) {
	case scene0:
	  changeShowCharacter(protag);
	  changeBackground(bgLivingRoom, 2);
	  addL(none, "*clack*");
	  addL(mom, "Oh, Nathan, thank goodness you're here. Can you do me a favour?");
	  addL(mom, "I forgot to buy eggs for today's supper. Can you go buy them for me?");
	  changeShowCharacter(protag, angryFace);
	  addChoice(2, "Okay", "No");
	  break;
	case scene0_1:
	  addL(nathan, "Okay.");
	  changeBackground(bgStreet1, 2);
	  addL(nathan, "......");
	  break;
	case scene0_2:
	  addL(none, "*clack*");
	  addL(mom, "Oh, Nathan, thank goodness you're here. Can you do me a favour?");
	  addL(mom, "I forgot to buy eggs for today's supper. Can you go buy them for me?");
	  addChoice(2, "Okay", "No");
	  break;
	}
	break;
      }
      break;
    }
    totalNumberOfLines = scriptLine.size();
  }
  protagPortrait->gTexture.mWidth = protagPortrait->sizeX;
  protagPortrait->gTexture.mHeight = protagPortrait->sizeY;
  for(int i = 0; i < NUM_FACES; i++) {
    protagPortrait->gFace[i].mWidth = protagPortrait->sizeX;
    protagPortrait->gFace[i].mHeight = protagPortrait->sizeY;
  }
  hasIndexedScript = true;
}


void Cutscene::determineScene(sceneIDEnum sId, int selButton) {
  switch(selButton) {
  case 0:
    switch(sId) {
    case scene0:
      sceneID = scene0_1;
      break;
    }
    break;
  case 1:
    switch(sId) {
    case scene0:
      sceneID = scene0_2;
      break;
    }
    break;
  }
}
