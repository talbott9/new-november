enum clothesIDEnum {ragsID};
enum scheduleIDEnum {schNothing, schCobble, schCafe, schPhilosophy, schPoetry, schTheology, schHistory, schMathematics, schRomance, schWalk, schFencing, schVisit};
enum itemID {itemOldSword, itemRags};

class Player {
 public:
  Player();
  int stamina, strength, dexterity, knowledge, looks, breed, character;
  float money;
  clothesIDEnum clothesID;
  scheduleIDEnum scheduleID[3];
  bool heldItems[100];
  std::string name = "Conrad";
};

Player player;
