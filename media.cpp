TTF_Font *gFont, *gFontOutline;
TTF_Font* gFancyFont = NULL;
TTF_Font* gBigFancyFont = NULL;
LTexture gTextbox, gCoastBG, gMenuBG, gStreet1BG, gLivingRoomBG;
LTexture gLSPortrait, gHGPortrait;
LTexture gNathanFace[20];

bool loadMedia() {
  bool success = true;
  if(!gTextbox.loadFromFile("resources/objects/textbox.png"))
    success = false;
  gCoastBG.loadFromFile("resources/bg/coast.png");
  gMenuBG.loadFromFile("resources/bg/menu.png");
  gLivingRoomBG.loadFromFile("resources/bg/livingroom.png");
  gStreet1BG.loadFromFile("resources/bg/street1.png");
  if(!gLSPortrait.loadFromFile("resources/chars/nathan/nathanportrait.png"))
    success = false;
  gHGPortrait.loadFromFile("resources/chars/hildegarde/hildegardeportrait.png");
  if(!gNathanFace[neutralFace].loadFromFile("resources/chars/nathan/nathanfaceneutral.png"))
    success = false;
  gNathanFace[angryFace].loadFromFile("resources/chars/nathan/nathanfaceangry.png");
    return success;
}

void loadFont(int size) {
	gFont= TTF_OpenFont("resources/fonts/font1.ttf", size);
	gFontOutline = TTF_OpenFont("resources/fonts/font1.ttf", size);;
	TTF_SetFontOutline(gFontOutline, 1); 
	gFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 40);
	gBigFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 70);
}
