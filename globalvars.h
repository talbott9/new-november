#define fps 60
#define NUM_CHARS 2
#define NUM_PORTRAITS 10
#define NUM_SCRIPT_LINES 200
#define BIG_NUMBER 999999

const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

Uint32 frame_time;
float calcFPS;

enum portraitFace {neutralFace, happyFace, angryFace, loseFace, mairiFace1, mairiFace2, angryFace1, angryFace2, grinFace, talkFace};

enum playerChars {playerLS, playerHG};
playerChars playerChar = playerLS;
enum friendChars {friendLS, friendHG};
friendChars friendChar = friendHG;
enum bgIDEnum {bgStreet1, bgStreet2, bgLivingRoom};
enum sceneIDEnum {scene1};
sceneIDEnum sceneID = scene1;
enum charIDEnum {none = -2, mom = -1, nathan, mary};

bool pressedKey[50];
enum pressedKeys {z, x, c, left, right, up, down, esc, lshift, d};

bool pause = false;
