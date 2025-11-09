#define fps 60
#define NUM_CHARS 3
#define NUM_PORTRAITS 10
#define NUM_FACES 20
#define NUM_SCRIPT_LINES 200
#define BIG_NUMBER 999999
#define PORTRAIT_WIDTH 2480
#define PORTRAIT_HEIGHT 3508
#define PI 3.14159265

const int defpw = 2480/2.5;
const int defph = 3508/2.5;
const int pX =  (camera.w-defpw)/2;
const int pY = (camera.h-defph)/2 + defph/4.5;
int cPX(float num = 1);
int cPX(float num) {
  return (camera.w-defpw*num)/2;
}
int cPY(float num = 1);
int cPY(float num) {
  return (camera.h-defph*num)/2 + defph*num/4.5;
}

const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

Uint32 frame_time;
float calcFPS;

enum portraitFace {neutralFace, neutralFace2, angryFace, angryFace2, angryFace3, happyFace, happyFace2, happyFace3, 
sadFace, mairiFace, surpriseFace, surpriseFace2, surpriseFace3};

enum playerChars {playerLS, playerHG};
playerChars playerChar = playerHG;
enum friendChars {friendLS, friendHG, friendCAT};
friendChars friendChar = friendCAT;
enum bgIDEnum {bgStreet1, bgStreet1Evening, bgStreet2, bgLivingRoom, bgGrocery, bgStore, bgStoreInside};
enum sceneIDEnum {scene0, scene0_1, scene0_1_1, scene0_1_1_1, scene0_1_1_1_1, scene0_1_1_1_1_1, scene0_1_1_1_1_2, scene0_1_1_1_2, scene0_1_1_2_1, scene0_1_1_2_2, scene0_1_2, scene0_1_1_2, scene0_2, scene0_1_2_2, scene0_1_2_1};
sceneIDEnum sceneID = 	scene0;
enum charIDEnum {unknown = -5, clerk = -4, protag = -3, none = -2, mom = -1, nathan, mary, catie};

bool pressedKey[50];
enum pressedKeys {z, x, c, left, right, up, down, esc, lshift, d, mleft};

bool pause = false;

bool debugMode = false;
