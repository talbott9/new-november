class Portrait {
public:
  Portrait(bool changeM, bool mov, int x, int y, int textureID);
  void moveToXY(double x, double y, double speed, bool drag = true);
  bool moved, reachedTarget, changeMove, changedMove;
  double distance, accX, accY, dx, dy, speed;
  int posX, posY, defaultPosX, defaultPosY, targetX, targetX1, targetX2;
  SDL_Rect mBox;
  LTexture gTexture;
  LTexture gFace[20];
  int darkenTicks, alpha;
  void render();
  void reset();
  int sizeX, sizeY;
  std::vector<portraitFace> face;
  std::vector<int> size[2];
  std::vector<int> xy[2];
  std::vector<bool> show;
  bool isProtag;
  bool disappear[NUM_SCRIPT_LINES];
  bool appear[NUM_SCRIPT_LINES];
  bool appear2[NUM_SCRIPT_LINES];
  int animationID[NUM_SCRIPT_LINES];
  float animTicks;
  int animCycle;
};

class Cutscene {
 public:
  Cutscene();
  void render(SDL_Rect& camera);
  void handleEvent(SDL_Event& e, std::string s);
  void nathanMaryScript(), maryNathanScript();
  void indexScript();
  void handleEvent(SDL_Event& e, bool controller);
  void drawDialogueText(std::string s);
  void skipText();
  void play();
  void blur();
  void reset();
  void gameOverScreen();
  void addL(charIDEnum characterID, std::string s, bool addQuotes = true);
  void addChoice(int number, std::string c1 = "", std::string c2 = "", std::string c3 = "");
  void changeBackground(bgIDEnum id, int wait = 0);
  void changeShowCharacter(charIDEnum characterID, portraitFace fac = neutralFace, int x = -1, int y = -1, int w = -1, int h = -1, int textureNumber = -1, bool show = true, int type = -1);
  void doAnim(charIDEnum characterID, int animID);
  void choiceBoxAnim();
  void determineScene(sceneIDEnum sId, int selButton);
  void determineTexture(charIDEnum characterID, int textureNumber);

  SDL_Rect textbox, mouseBox;
  SDL_Rect choiceBoxes[3];
  std::vector<std::string> scriptLine;
  bool heroTalking[NUM_SCRIPT_LINES];
  std::string textWritten;
  LTexture* gTextboxTexture = &gTextbox;
  TTF_Font** gTextFont;
  LTexture gText;

  //Control character slide-on-screen animation
  bool createdPortrait[NUM_PORTRAITS];
  Portrait* charPortrait[NUM_PORTRAITS];
  Portrait* protagPortrait;
  bool showProtag;
  std::vector<std::vector<portraitFace>> charFace;
  std::vector<bgIDEnum> bgID;
  std::vector<std::string> charName;
  std::vector<bool> changeBg;
  LTexture gOldBackground, gBackground;
  int bgAlpha, bgSpeed, bgWaitTicks, skipTextTicks;
  std::vector<int> bgWaitTime;
  std::vector<bool> changeShowChar;
  bool showChar[NUM_PORTRAITS];
  std::vector<bool> isChoice;
  std::vector<int> numChoiceBoxes;
  std::string strChoices[3];
  int selectedChoice, choiceAlpha, choiceCycle, chosenPath, choiceTicks;
  bool mouseIsOnChoice;
  std::string s;
  char c;
  int i, charCount, lineNumber, totalNumberOfLines, wrpBnd, textX, textY;
  bool doNotType, hasIndexedScript, hasDeterminedScenes, advancedDialogue, tobasu, hasTobasu, canAdvance;
};

Cutscene cutscene;
