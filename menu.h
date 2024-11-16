enum menuStep {scrMainMenu, scrNone, scrAttic};
menuStep menuScreenID = scrMainMenu;

class Menu { 
public:
  SDL_Rect boxes[50];
  std::string strs[50];
  int mouseX, mouseY;
  std::string names[2];
  void renderMenu();
  void handleEvent(SDL_Event& e);
  LTexture gText;
  SDL_Rect mouseBox;
  int numBoxes;
  bool pressedKey[10];
  enum pressedKeys {mleft, mright};
  bool blurSuccess[2];
  bool doBlur, undoBlur;
  void blur1();
  int blurAlpha;
  SDL_Rect blurBoxes[10];
  int blurSpeed = 4;
  bool showSchedule[2];
  int chosenSchedule;
  bool showItems[2];
  bool listedItem[100];
  std::string itemStrings[50];
};

