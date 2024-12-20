
 NUMBER 0


 NUMBER 1
const int pX =  (camera.w-defpw)/2;
const int pY = (camera.h-defph)/2 + defph/5;

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
      for(int j = 0; j < 2; j++) {
	charPortrait[i]->size[j].clear();
	charPortrait[i]->size[j].resize(scriptLine.size());
      }
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
	protagPortrait->gFace[i] = gCharFace[nathan][i];
      switch(friendChar) {
      case friendHG:
	switch(sceneID) {
	case scene0:
	  changeShowCharacter(protag);
	  changeBackground(bgLivingRoom, 2);
	  addL(none, "*clack*");
	  addL(mom, "Oh, Nate, thank goodness you're here. Can you do me a favour?");
	  addL(mom, "I forgot to buy eggs for today's supper. Can you go buy them for me?");
	  changeShowCharacter(protag, angryFace);
	  addChoice(2, "Okay", "No");
	  break;
	case scene0_1:
	  addL(nathan, "Okay.");
	  changeBackground(bgStreet1, 2);
	  addL(nathan, ".........");
	  changeShowCharacter(mary, happyFace3, pX, pY, defpw, defph, 0);
	  addL(mary, "Gooooooooooooooooood!");
	  addL(nathan, ".........");
	  addL(mary, "After!");
	  addL(mary, "Noon!");
	  changeShowCharacter(mary, happyFace2);
	  addL(nathan, ".........");
	  addL(nathan, "Who are you?");

	  changeShowCharacter(mary, surpriseFace);
	  addL(mary, "What?! Have you forgotten me already?");
	  addL(mary, "It's Mary, Mary van Buren! I'm your classmate!");
	  addL(nathan, "You can't expect me to remember every single classmate's name. The school year's just begun.");
	  changeShowCharacter(mary, sadFace);
	  addL(mary, "It started a month ago!");
	  addL(nathan, "Is that a fact?");
	  changeShowCharacter(mary, happyFace2);
	  addL(mary, "Because I'm a kind person, I'm willing to forgive your outrageous lack of delicacy for the measly price of one Snickers bar.");
	  addL(mary, " So, pay up.");
	  changeShowCharacter(protag, angryFace);
	  addL(nathan, "No.");
	  changeShowCharacter(mary, neutralFace);
	  addL(mary, "Can you at least give a quarter? Then I can buy it at the vending machine.");
	  changeShowCharacter(protag, neutralFace);
	  addL(nathan, "Is that enough to buy it?");
	  addL(mary, "No, that's how much I'm short.");
	  changeShowCharacter(protag, angryFace);
	  addL(nathan, "Ah...");

	  addL(mary, "What?");
	  changeShowCharacter(protag, neutralFace);
	  addL(nathan, "I'm supposed to go to the grocery store now.");
	  changeShowCharacter(mary, happyFace3);
	  addL(mary, "Oh, that's a coincidence. I was on my way to the grocery store, too!");
	  changeShowCharacter(mary, happyFace);
	  addL(mary, "We ran out of eggs, so my mom asked to buy more.");
	  addL(nathan, ".........");
	  addL(mary, "And you? What are you going to buy?");
	  addChoice(2, "Eggs", "Plastic model kit");
	  break;
	case scene0_1_1:
	  changeShowCharacter(mary, happyFace, pX, pY, defpw, defph, 0);
	  addL(nathan, "Actually, I'm going to buy eggs as well.");
	  changeShowCharacter(mary, happyFace2);
	  addL(mary, "Perfect! Let's go together, then. I know a good store.");
	  addL(nathan, "I'd rather not...");
	  changeShowCharacter(mary, sadFace);
	  addL(mary, "What? But it's such a nice day.");
	  changeShowCharacter(protag, angryFace);
	  addL(nathan, "That's irrelevant.");
	  addL(mary, "Please?");
	  addL(nathan, ".........");
	  changeShowCharacter(protag, neutralFace);
	  addL(nathan, "Okay.");
	  changeShowCharacter(mary, happyFace3);
	  addL(mary, "Yay!");
	  changeBackground(bgGrocery, 1);
	  changeShowCharacter(mary, neutralFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0);
	  addL(mary, "Chicken... Beef... Bacon...");
	  changeShowCharacter(mary, happyFace2);
	  addL(mary, "Oh, there it is! My favorite! Soy sauce-flavored ramen!");
	  addL(nathan, ".........");
	  changeShowCharacter(mary, neutralFace);
	  addL(mary, "I don't remember the last time I bought the other flavors.\nSoy sauce is just better.");
	  addL(mary, "For example, chicken ramen doesn't taste like chicken at all.\nI don't know why they named it that.");
	  addL(nathan, ".........");
	  addL(mary, "Bacon gets close to tasting like bacon, but not quite.");
	  changeShowCharacter(mary, neutralFace2);
	  addL(mary, "I don't like it. I think they call\n that the \'uncanny valley.\'");
	  addL(nathan, ".........");
	  addL(mary, "Beef is fine, I suppose. It's kind of neutral. But it doesn't taste like beef, either.");
	  addL(nathan, ".........");
	  addL(nathan, "Didn't you say you were going to buy eggs?");
	  changeShowCharacter(mary, surpriseFace);
	  addL(mary, "Oh, right, I almost forgot!");
	  changeShowCharacter(mary, happyFace);
	  addL(mary, "Do you prefer the brown or white eggs?");
	  addChoice(2, "White", "They're the same");
	  break;
	case scene0_2:
	  changeShowCharacter(protag, angryFace);
	  addL(nathan, "No.");
	  addL(mom, "Then we're having omelettes without eggs for today's supper.");
	  changeShowCharacter(protag, neutralFace);
	  addL(nathan, ".........");
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
    }
    break;
  }
}


 NUMBER 2


 NUMBER 3


 NUMBER 4


 NUMBER 5


 NUMBER 6


 NUMBER 7


 NUMBER 8


 NUMBER 9


 NUMBER 10


 NUMBER 11
LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mBox.x = 0; mBox.y = 0;
	mBox.w = 1; mBox.h = 1;
}

LTexture::~LTexture()
{
	//Deallocate
	//free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
  //Modulate texture rgb
  SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

SDL_Rect LTexture::getBox() {
	return mBox;
}

bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor, int wrapBoundary, TTF_Font* gFont)
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped( gFont, textureText.c_str(), textColor, wrapBoundary );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return mTexture != NULL;
}


 NUMBER 12
void Menu::blur1() {
  blurBoxes[0] = {camera.x,camera.y,SCREEN_WIDTH,SCREEN_HEIGHT};
  if(undoBlur) {
    blurAlpha -= blurSpeed;
    if(blurAlpha < 0) {
      blurAlpha = 0;
      undoBlur = false;
      blurSuccess[1] = true;
      doBlur = false;
    }
  } else {
    blurAlpha += blurSpeed;
    if(blurAlpha > 255) {
      undoBlur = true;
      blurAlpha = 255;
      blurSuccess[0] = true;
      doBlur = false;
    }
  }
  SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);	
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, blurAlpha);
  SDL_RenderFillRect(gRenderer, &blurBoxes[0]);
}

void Menu::reset() {
  menuBuffer = 0;
}

void Menu::renderMenu() {
  switch(menuScreenID) {
  case scrMainMenu:
    gCoastBG.render(camera.x,camera.y);
    gMenuBG.render(camera.x,camera.y);

    switch(playerChar) {
    case playerLS:
      names[0] = "Louis";
      break;
    case playerHG:
      names[0] = "Hildegarde";
      break;
    }
     switch(friendChar) {
    case friendLS:
      names[1] = "Louis";
      break;
    case friendHG:
      names[1] = "Hildegarde";
      break;
    }
    
    gText.loadFromRenderedText(names[0], Black, 0, gFancyFont);
    gText.render(90, 450);
    gText.loadFromRenderedText(names[1], Black, 0, gFancyFont);
    gText.render(90, 510);

    gText.loadFromRenderedText("Start", Black, 0, gBigFancyFont);
    gText.render(330, 425);
    gText.loadFromRenderedText("Load", Black, 0, gBigFancyFont);
    gText.render(540, 425);
     
    break;
  }
}

void Menu::handleEvent(SDL_Event& e) {
  menuBuffer++;
  if(menuBuffer > 15) {
    bool mouseLeft;
    mouseLeft = SDL_GetMouseState(&mouseX, &mouseY) == 1;
    switch(menuScreenID) {
    case scrMainMenu:
      numBoxes = 4;
      mouseBox = {mouseX,mouseY,5,5};
      //start
      boxes[0] = {325, 420, 160, 65};
      //load
      boxes[1] = {535, 420, 170, 70};
      //name1
      boxes[2] = {90, 445, 190, 45};
      //name2
      boxes[3] = {90, 505, 190, 45};

      for(int i = 0; i < numBoxes; i++) {
	if(checkCollision(mouseBox,boxes[i])) {
	  SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);	
	  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 100);
	  SDL_RenderFillRect(gRenderer, &boxes[i]);
	}
      }

      if(mouseLeft) {
	if(!pressedKey[pressedKeys{mleft}]) {
	  pressedKey[pressedKeys{mleft}] = true;
      
	  if(checkCollision(mouseBox,boxes[2])) {
	    switch(playerChar) {
	    case playerLS: playerChar = playerHG;
	      break;
	    case playerHG: playerChar = playerLS;
	      break;
	    }
	  } else if(checkCollision(mouseBox,boxes[3])) {
	    switch(friendChar) {
	    case friendLS: friendChar = friendHG;
	      break;
	    case friendHG: friendChar = friendLS;
	      break;
	    }
	  } else if(checkCollision(mouseBox,boxes[0])) {
	    blurSuccess[0] = false;
	    blurSuccess[1] = false;
	    doBlur = true;
	  }
	}
      } else {
	pressedKey[pressedKeys{mleft}] = false;
      }

      if(blurSuccess[0]) {
	doBlur = true;
	menuScreenID = scrNone;
      }

      break;
    case scrNone:
      break;
    }
  }
}

Menu menu;


 NUMBER 13

