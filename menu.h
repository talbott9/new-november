enum menuStep {scrMainMenu, scrNone};
menuStep menuScreenID = scrMainMenu;

class Menu { 
public:
  SDL_Rect boxes[20];
  int mouseX, mouseY;
  std::string names[2];
  void renderMenu();
  void reset();
  void handleEvent(SDL_Event& e);
  LTexture gText;
  SDL_Rect mouseBox;
  int numBoxes;
  bool pressedKey[10];
  enum pressedKeys {mleft};
  bool blurSuccess[2];
  bool doBlur, undoBlur;
  void blur1();
  int blurAlpha;
  SDL_Rect blurBoxes[10];
  int blurSpeed = 4;
  int menuBuffer;
};

