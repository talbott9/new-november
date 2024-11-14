TTF_Font* gFont = NULL;
TTF_Font* gFontBig1 = NULL;
TTF_Font* gFancyFont = NULL;
TTF_Font* gBigFancyFont = NULL;
TTF_Font* gMonoFont = NULL;
LTexture gTextbox, gAtticBG, gMenuBG, gStreet1BG;
LTexture gLSPortrait, gHGPortrait;

bool loadMedia() {
  bool success = true;
  if(!gTextbox.loadFromFile("resources/objects/textbox.png"))
    success = false;
  gAtticBG.loadFromFile("resources/bg/attic.png");
  gMenuBG.loadFromFile("resources/bg/menu.png");
  gStreet1BG.loadFromFile("resources/bg/street1.png");
  gLSPortrait.loadFromFile("resources/chars/louis/louisportrait.png");
  gHGPortrait.loadFromFile("resources/chars/hildegarde/hildegardeportrait.png");
  return success;
}

void loadFont(int size) {
	gFont= TTF_OpenFont("resources/fonts/font1.ttf", size);
	gFontBig1 = TTF_OpenFont("resources/fonts/font1.ttf", size*1.5);
	gMonoFont= TTF_OpenFont("resources/fonts/monofont.ttf", size);
	gFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 40);
	gBigFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 70);
}
