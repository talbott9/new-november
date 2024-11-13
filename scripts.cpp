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
	  bgID = street1;
	  charName[0] = "Nathan  ";
	  scriptLine[0] = "\"It's been a while since I've been here.\"";
	  charFace[0][0] = neutralFace;
	  charName[1] = "Hilda   ";
	  scriptLine[1] = "Cool story, bro.";
	  charFace[0][1] = neutralFace;
	  totalNumberOfLines = 3;
	  hasIndexedScript = true;
	  break;
	}
	break;
      }
      break;
    }
  }
}
