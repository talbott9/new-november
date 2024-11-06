void Cutscene::indexScript() {
  if(!hasIndexedScript) {
    switch(playerChar) {
    case playerLS:
      charPortrait[0] = new Portrait(true, false,0,0);
      createdPortrait[0] = true;
      charPortrait[0]->gTexture = &gLSPortrait;
      switch(friendChar) {
      case friendHG:
	charPortrait[1] = new Portrait(true, false,0,0);
	createdPortrait[1] = true;
	charPortrait[1]->gTexture = &gHGPortrait;
	switch(sceneID) {
	case scene1:
	  charName = "Louis: ";
	  scriptLine[0] = "It's been a while since I've been";
	  charFace[0][0] = neutralFace;
	  bgID = street1;
	  totalNumberOfLines = 1;
	  hasIndexedScript = true;
	  break;
	}
	break;
      }
      break;
    }
  }
}
