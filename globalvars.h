#define fps 60
#define NUM_CHARS 2
#define NUM_PORTRAITS 3
#define NUM_SCRIPT_LINES 200

Uint32 frame_time;
float calcFPS;

enum portraitFace {neutralFace, happyFace, angryFace, loseFace, mairiFace1, mairiFace2, angryFace1, angryFace2, grinFace, talkFace};

enum playerChars {playerLS, playerHG};
playerChars playerChar = playerLS;
enum friendChars {friendLS, friendHG};
friendChars friendChar = friendHG;
enum bgIDEnum {street1, street2, bgAttic, bgBlack, bgSky, bgOffice, bgStreet1};
//bgIDEnum bgID = street1;
enum sceneIDEnum {intro, scene1, attic1, attic2, attic3, atticoldsword, atticrags};
sceneIDEnum sceneID = intro;

int day = 1;

bool pause = false;
