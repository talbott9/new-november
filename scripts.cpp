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
    for(int i = 0; i < NUM_CHARS; i++) {
      charPortrait[i]->face.clear();
      charPortrait[i]->face.resize(NUM_SCRIPT_LINES);
      charPortrait[i]->show.clear();
      charPortrait[i]->show.resize(NUM_SCRIPT_LINES);
      for(int j = 0; j < 2; j++) {
	charPortrait[i]->size[j].clear();
	charPortrait[i]->size[j].resize(scriptLine.size());
	charPortrait[i]->xy[j].clear();
	charPortrait[i]->xy[j].resize(scriptLine.size());
      }
      for(int j = 0; j < NUM_SCRIPT_LINES; j++) {
	charPortrait[i]->disappear[j] = false;
	charPortrait[i]->appear[j] = false;
	charPortrait[i]->appear2[j] = false;
	charPortrait[i]->animationID[j] = 0;
      }
    }
    protagPortrait->show.clear();
    protagPortrait->show.resize(NUM_SCRIPT_LINES);
    protagPortrait->face.clear();
    protagPortrait->face.resize(NUM_SCRIPT_LINES);
    for(int j = 0; j < NUM_SCRIPT_LINES; j++) {
      protagPortrait->animationID[j] = 0;
    }
    isChoice.clear();
    isChoice.resize(NUM_SCRIPT_LINES);
    numChoiceBoxes.clear();
    numChoiceBoxes.resize(NUM_SCRIPT_LINES);
    selectedChoice = -1;
    switch(playerChar) {
    case playerLS:
      
      protagPortrait->gTexture = gLSPortrait;
      for(int i = 0; i < NUM_FACES; i++)
	protagPortrait->gFace[i] = gCharFace[nathan][i];
      protagPortrait->mBox.x = cutscene.textbox.w*0.3;
      protagPortrait->mBox.y = cutscene.textbox.y-cutscene.textbox.h*1.5;
      
      switch(friendChar) {
      case friendHG:
	nathanMaryScript();
	break;
      }
      
      break;

    case playerHG:
      
      protagPortrait->gTexture = gHGPortrait;
      for(int i = 0; i < NUM_FACES; i++)
	protagPortrait->gFace[i] = gCharFace[mary][i];
     protagPortrait->mBox.x = cutscene.textbox.w*0.325;
     protagPortrait->mBox.y = cutscene.textbox.y-cutscene.textbox.h*2;
      
      switch(friendChar) {
      case friendLS:
	maryNathanScript();
	break;
	case friendCAT:
	maryCatieScript();
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
    case scene0_1:
      sceneID = scene0_1_1;
      break;
    case scene0_1_1:
      sceneID = scene0_1_1_1;
      break;
    case scene0_1_1_1:
      sceneID = scene0_1_1_1_1;
      break;
    case scene0_1_1_1_1:
      sceneID = scene0_1_1_1_1_1;
      break;
    case scene0_1_2:
      sceneID = scene0_1_2_1;
      break;
      
    case scene0_1_1_2:
      sceneID = scene0_1_1_2_1;
      break;
    }
    break;
  case 1:
    switch(sId) {
    case scene0:
      sceneID = scene0_2;
      break;
    case scene0_1:
      sceneID = scene0_1_2;
      break;
    case scene0_1_1:
      sceneID = scene0_1_1_2;
      break;
    case scene0_1_1_1:
      sceneID = scene0_1_1_1_2;
      break;
    case scene0_1_1_2:
      sceneID = scene0_1_1_2_2;
      break;
    case scene0_1_1_1_1:
      sceneID = scene0_1_1_1_1_2;
      break;
    case scene0_1_2:
      sceneID = scene0_1_2_2;
      break;
    }
    break;
  }
}
