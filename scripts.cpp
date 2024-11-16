void Cutscene::indexScript() {
  if(!hasIndexedScript) {
    for(int i = 0; i < NUM_SCRIPT_LINES; i++) {
      charName[i] = "";
      changeBg[i] = false;
      bgWaitTime[i] = 0;
    }
    switch(sceneID) {
    case intro:
      bgID[0] = bgBlack;
      charName[0] = "???";
      scriptLine[0] = "...";
      charName[1] = "???";
      scriptLine[1] = "...";
      charName[2] = "???";
      scriptLine[2] = "Oh, he's sleeping again...";
      charName[3] = "???";
      scriptLine[3] = "...";
      charName[4] = "???";
      scriptLine[4] = "...";
      charName[5] = "???";
      scriptLine[5] = "Hey... hey... wake up...!";
      charName[6] = "???";
      scriptLine[6] = "Wake up...!";
      charName[7] = "???";
      scriptLine[7] = "...";
      charName[8] = "???";
      scriptLine[8] = "He's not waking up... What should I do now?";
      charName[9] = "???";
      scriptLine[9] = "Maybe I can just leave it here?";
      charName[10] = "???";
      scriptLine[10] = "What if the wind blows it out the window...? Or a rat takes it away...?";
      charName[11] = "???";
      scriptLine[11] = "No, I'm sure it's fine... I'll just leave it... I'll leave it...";
      charName[12] = "???";
      scriptLine[12] = "Oh, I know, I should leave it on his pillow. Then, he'll see it as soon as he wakes up.";
      charName[13] = "???";
      scriptLine[13] = "...";
      charName[14] = "???";
      scriptLine[14] = "He looks like he's having such a nice dream... And yet...";
      charName[15] = "???";
      scriptLine[15] = "...";
      
      charName[16] = "";
      scriptLine[16] = "......";
      charName[17] = "";
      scriptLine[17] = ".............";
      charName[18] = "";
      scriptLine[18] = "....................";
      bgID[19] = bgAttic;
      changeBg[19] = true;
      charName[19] = player.name;
      scriptLine[19] = "...";
      charName[20] = player.name;
      scriptLine[20] = "...";
      charName[21] = player.name;
      scriptLine[21] = "Ugh... is it morning already?";
      charName[22] = player.name;
      scriptLine[22] = "I don't feel like waking up...";
      charName[23] = player.name;
      scriptLine[23] = "Everyday's the same, anyway... I'll just start making shoes the moment I get up... and then nobody'll buy them.";
      charName[24] = player.name;
      scriptLine[24] = "...";
      charName[25] = player.name;
      scriptLine[25] = "What's this? A letter? That's a rarity.";
      charName[26] = player.name;
      scriptLine[26] = "Could it be a love letter? An invitation to a ball? Or perhaps it's a letter from a distant relative summoning me to take over his fortune?";
      charName[27] = player.name;
      scriptLine[27] = "Let's see, it's from... my landlord.";
      charName[28] = player.name;
      scriptLine[28] = "...";
      charName[29] = player.name;
      scriptLine[29] = "I think I'll stay in bed a bit longer.";
      bgID[30] = bgBlack;
      changeBg[30] = true;
      scriptLine[30] = "......";
      scriptLine[31] = ".............";
      scriptLine[32] = "....................";
      bgID[33] = bgSky;
      changeBg[33] = true;
      bgWaitTime[33] = 2;
      bgID[34] = bgStreet1;
      changeBg[34] = true;
      bgWaitTime[34] = 2;
      bgID[35] = bgOffice;
      changeBg[35] = true;
      bgWaitTime[35] = 2;
      scriptLine[36] = "blah bla";
      totalNumberOfLines = 37;
      break;
    case attic1:
      charName[0] = "";
      scriptLine[0] = "What will you do?";
      totalNumberOfLines = 1;
      break;
    case attic2:
      charName[0] = "";
      scriptLine[0] = "What will be your schedule today?";
      totalNumberOfLines = 1;
      break;
    case atticoldsword:
      charName[0] = "";
      scriptLine[0] = "An old sword. It's an heirloom from your late grandfather. It still cuts quite well.";
      totalNumberOfLines = 1;
      break;
    case atticrags:
      charName[0] = "";
      scriptLine[0] = "Rags. Low-quality clothing.";
      totalNumberOfLines = 1;
      break;
    }
    hasIndexedScript = true;
  }
}
