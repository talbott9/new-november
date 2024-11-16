Player::Player() {
  stamina = 100;
  strength = 5;
  dexterity = 10;
  knowledge = 5;
  looks = 5;
  breed = 5;
  character = 10;
  money = 10;
  clothesID = ragsID;
  for(int i = 0; i < 3; i++)
    scheduleID[i] = schNothing;
  heldItems[itemOldSword] = true;
  heldItems[itemRags] = true;
}
