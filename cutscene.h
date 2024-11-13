class Portrait {
public:
  Portrait(bool changeM, bool mov, int x, int y);
  void moveToXY(double x, double y, double speed, bool drag = true);
  bool moved, reachedTarget, changeMove, changedMove;
  double distance, accX, accY, dx, dy, speed;
  int posX, posY, defaultPosX, defaultPosY, targetX, targetX1, targetX2;
  SDL_Rect mBox;
  LTexture* gTexture;
  int darkenTicks;
  LTexture* gFace;
  void render();
};

class Cutscene {
 public:
  Cutscene();
  void render(SDL_Rect& camera);
  void handleEvent(SDL_Event& e, std::string s);
  void indexScript();
  void handleEvent(SDL_Event& e, bool controller);
  void drawDialogueText(std::string s);
  void skipText();
  void play();
  void blur();
  void resetCutscene();
  void gameOverScreen();

  SDL_Rect textbox;
  std::string scriptLine[NUM_SCRIPT_LINES];
  bool heroTalking[NUM_SCRIPT_LINES];
  std::string textWritten;
  LTexture* gTextboxTexture = &gTextbox;
  TTF_Font** gTextFont;
  LTexture gText;

  //Control character slide-on-screen animation
  bool createdPortrait[NUM_PORTRAITS];
  Portrait* charPortrait[NUM_PORTRAITS];
  portraitFace charFace[NUM_PORTRAITS][NUM_SCRIPT_LINES];
  std::string charName[NUM_SCRIPT_LINES];
  
 private:
  std::string s;
  char c;
  int i, charCount, lineNumber, totalNumberOfLines, wrpBnd, textX, textY;
  bool doNotType, hasIndexedScript, hasDeterminedScenes, advancedDialogue, tobasu, hasTobasu, canAdvance;
};

Cutscene cutscene;
