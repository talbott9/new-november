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
    charFace.resize(2);
    charFace[0].resize(NUM_SCRIPT_LINES);
    charFace[1].resize(NUM_SCRIPT_LINES);
    isChoice.clear();
    isChoice.resize(NUM_SCRIPT_LINES);
    numChoiceBoxes.clear();
    numChoiceBoxes.resize(NUM_SCRIPT_LINES);
    selectedChoice = -1;
    switch(playerChar) {
    case playerLS:
      switch(friendChar) {
      case friendHG:
	switch(sceneID) {
	case scene1:
	  changeBackground(bgLivingRoom);
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
  hasIndexedScript = true;
}
