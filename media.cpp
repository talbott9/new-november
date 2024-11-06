TTF_Font* gFont = NULL;
TTF_Font* gFancyFont = NULL;
TTF_Font* gBigFancyFont = NULL;
LTexture gTextbox, gCoastBG, gMenuBG;

bool loadMedia() {
  bool success = true;
  if(!gTextbox.loadFromFile("resources/objects/textbox.png"))
    success = false;
  gCoastBG.loadFromFile("resources/bg/coast.png");
  gMenuBG.loadFromFile("resources/bg/menu.png");
  return success;
}

void loadFont(int size) {
	gFont= TTF_OpenFont("resources/fonts/font1.ttf", size);
	gFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 40);
	gBigFancyFont = TTF_OpenFont("resources/fonts/Basic Roman-BoldItalic.ttf", 70);
}
