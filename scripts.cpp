void Cutscene::indexScript() {
  if(!hasIndexedScript) {
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
    case attic1:
      charName[0] = "";
      scriptLine[0] = "What will you do?";
      totalNumberOfLines = 1;
      break;
    }
  }
}
