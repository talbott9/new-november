TTF_Font *gFont, *gFontOutline;
TTF_Font* gFancyFont = NULL;
TTF_Font* gBigFancyFont = NULL;
LTexture gTextbox, gCoastBG, gMenuBG, gStreet1BG, gStreet2BG, gLivingRoomBG, gGroceryBG, gStoreBG, gStoreInsideBG;
LTexture gLSPortrait, gHGPortrait;
LTexture gCharFace[2][20];

bool loadMedia() {
  bool success = true;
  std::string faceDir[20];
  std::string nameStr[NUM_CHARS];
  nameStr[nathan] = "nathan";
  nameStr[mary] = "mary";
  
  faceDir[neutralFace] = "faceneutral.png";
  faceDir[neutralFace2] = "faceneutral2.png";
  faceDir[angryFace] = "faceangry.png";
  faceDir[angryFace2] = "faceangry2.png";
  faceDir[sadFace] = "facesad.png";
  faceDir[happyFace] = "facehappy.png";
  faceDir[happyFace2] = "facehappy2.png";
  faceDir[happyFace3] = "facehappy3.png";
  faceDir[mairiFace] = "facemairi.png";
  faceDir[surpriseFace] = "facesurprise.png";
  faceDir[surpriseFace2] = "facesurprise2.png";
  faceDir[surpriseFace3] = "facesurprise3.png";
  
  if(!gTextbox.loadFromFile("resources/objects/textbox.png"))
    success = false;
  gCoastBG.loadFromFile("resources/bg/coast.png");
  gMenuBG.loadFromFile("resources/bg/menu.png");
  gLivingRoomBG.loadFromFile("resources/bg/livingroom.png");
  gStreet1BG.loadFromFile("resources/bg/street1.png");
  gStreet2BG.loadFromFile("resources/bg/street2.png");
  gGroceryBG.loadFromFile("resources/bg/grocery.png");
  gStoreBG.loadFromFile("resources/bg/store.png");
  gStoreInsideBG.loadFromFile("resources/bg/storeinside.png");
  if(!gLSPortrait.loadFromFile("resources/chars/nathan/nathanportrait.png"))
    success = false;
  if(!gHGPortrait.loadFromFile("resources/chars/mary/maryportrait.png"))
    success = false;

  for(int i = 0; i < NUM_CHARS; i++) {
    for(int j = 0; j < NUM_FACES; j++) {
      gCharFace[i][j].loadFromFile("resources/chars/" + nameStr[i] + "/" + nameStr[i] + faceDir[j]);
    }
  }
  return success;
}

void loadFont(int size) {
	gFont= TTF_OpenFont("resources/fonts/font1.ttf", size);
	gFontOutline = TTF_OpenFont("resources/fonts/font1.ttf", size);;
	TTF_SetFontOutline(gFontOutline, 1); 
	gFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 40);
	gBigFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 70);
}
