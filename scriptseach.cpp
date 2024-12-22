void Cutscene::nathanMaryScript() {
  switch(sceneID) {
  case scene0:
    changeShowCharacter(protag);
    changeBackground(bgLivingRoom, 2);
    addL(none, "*clack*");
    addL(mom, "Oh, Nate, thank goodness you're here. Can you do me a favour?");
    addL(mom, "I forgot to buy eggs for today's supper. Can you go buy them for me?");
    // changeShowCharacter(protag, angryFace);
    addChoice(2, "Okay", "No");
    break;
  case scene0_2:
    changeShowCharacter(protag, angryFace);
    addL(nathan, "No.");
    addL(mom, "Then we're having omelettes without eggs for today's supper.");
    changeShowCharacter(protag, neutralFace);
    addL(nathan, ".........");
    break;
  case scene0_1:
    changeShowCharacter(protag);
    addL(nathan, "Okay.");
    changeBackground(bgStreet1, 2);
    addL(nathan, ".........");
    changeShowCharacter(mary, happyFace3, pX, pY, defpw, defph, 0, 1, 3);
    addL(mary, "Gooooooooooooooooood!");
    addL(nathan, ".........");
    addL(mary, "After!");
    addL(mary, "Noon!");
    changeShowCharacter(mary, happyFace2);
    addL(nathan, ".........");
    addL(nathan, "Who are you?");

    changeShowCharacter(mary, surpriseFace);
    addL(mary, "What?! Have you forgotten me already?");
    addL(mary, "It's Mary, Mary van Buren! I'm your classmate!");
    addL(nathan, "You can't expect me to remember every single classmate's name. The school year's just begun.");
    changeShowCharacter(mary, sadFace);
    addL(mary, "It started a month ago!");
    addL(nathan, "Is that a fact?");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "Because I'm a kind person, I'm willing to forgive your outrageous lack of delicacy for the measly price of one Snickers bar.");
    addL(mary, " So, pay up.");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "No.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "Can you at least give a quarter? Then I can buy it at the vending machine.");
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "Is that enough to buy it?");
    addL(mary, "No, that's how much I'm short.");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "Ah...");

    addL(mary, "What?");
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "I'm supposed to go to the grocery store now.");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Oh, that's a coincidence. I was on my way to the grocery store, too!");
    changeShowCharacter(mary, happyFace);
    addL(mary, "We ran out of eggs, so my mom asked to buy more.");
    addL(nathan, ".........");
    addL(mary, "And you? What are you going to buy?");
    addChoice(2, "Eggs", "Plastic model kit");
    break;
  case scene0_1_1:
    changeShowCharacter(protag);
    changeShowCharacter(mary, happyFace, pX, pY, defpw, defph, 0);
    addL(nathan, "Actually, I'm going to buy eggs as well.");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "Perfect! Let's go together, then. I know a good store.");
    addL(nathan, "I'd rather not...");
    changeShowCharacter(mary, sadFace);
    addL(mary, "What? But it's such a nice day.");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "That's irrelevant.");
    addL(mary, "Please?");
    addL(nathan, ".........");
    addL(nathan, "Okay.");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Yay!");
    changeBackground(bgGrocery, 1);
    changeShowCharacter(mary, neutralFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0, 1, 1);
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Chicken... Beef... Bacon...");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "Oh, there it is! My favorite! Soy sauce-flavored ramen!");
    addL(nathan, ".........");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "I don't remember the last time I bought the other flavors.\nShoyu ramen is just better.");
    addL(mary, "For example, chicken ramen doesn't taste like chicken at all.\nI don't know why they named it that.");
    addL(nathan, ".........");
    addL(mary, "Bacon gets close to tasting like bacon, but not quite.");
    changeShowCharacter(mary, neutralFace2);
    addL(mary, "I don't like it. I think they call\n that the \'uncanny valley.\'");
    addL(nathan, ".........");
    addL(mary, "Beef is fine, I suppose. It's kind of neutral. I use the powder to make curry.");
    addL(nathan, ".........");
    addL(nathan, "Didn't you say you were going to buy eggs?");
    changeShowCharacter(mary, surpriseFace);
    addL(mary, "Oh, right, I almost forgot!");
    changeShowCharacter(mary, happyFace);
    addL(mary, "Do you prefer the brown or white eggs?");
    addChoice(2, "White", "They're the same");
    break;
  case scene0_1_2:
    changeShowCharacter(protag);
    changeShowCharacter(mary, happyFace, pX, pY, defpw, defph, 0);
    addL(nathan, "I'm looking for a new plastic model kit.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "You mean those miniature models of boats you assemble from little parts?");
    addL(nathan, "Yeah.");
    changeShowCharacter(mary, neutralFace2);
    addL(mary, "Do they sell those at the grocery store?");
    addL(nathan, "I don't think so.");
    changeShowCharacter(mary, happyFace);
    addL(mary, "That reminds me, have you heard of the new store that opened recently?");
    addL(nathan, "New store?");
    addL(mary, "Yes, I heard they sell all kinds of weird stuff there. They probably have plastic models too.");
    addL(nathan, "Have you been there yet?");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "No, but I will soon!");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Let's-a-go-go!");
	  
    changeBackground(bgStore, 2);
    changeShowCharacter(mary, happyFace, pX + defpw/10, pY, defpw, defph, 0, 1, 1);
    changeShowCharacter(protag, angryFace);
    addL(nathan, "That's the sketchiest store I've ever seen.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "Really? It looks pretty normal to me.");
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "Are you sure they sell plastic model kits here?");
    changeShowCharacter(mary, sadFace);
    addL(mary, "Honestly, I'm not sure.");
    addL(nathan, "...Let's go in.");

    changeBackground(bgStoreInside, 1);
    changeShowCharacter(mary, neutralFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0, 1, 1);
    addL(clerk, "Konnichiwelcome!");
    changeShowCharacter(protag, angryFace);
    addL(nathan, ".........");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "Good afternoon! Would you happen to sell any plastic model kits?");
    addL(clerk, "Yes!");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Great! Can we see them?");
    addL(clerk, "No!");
    changeShowCharacter(mary, sadFace);
    addL(mary, "...");
    addL(clerk, "I no understand English!");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "What language do you speak?");
    addL(clerk, "I no understand English!");
    changeShowCharacter(mary, sadFace);
    addL(mary, "What do we do?");
    addChoice(2, "Speak Spanish", "Use sign language");
    break;
  case scene0_1_2_1:
    changeShowCharacter(mary, neutralFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0, 1);
    changeShowCharacter(protag);
    addL(nathan, "Comprendes español?");
    addL(clerk, "O! Ho mal di stomaco!");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "Estúpido! Non é bo lamentar-se en compañía de mulleres!");
    addL(clerk, "Non è moglie!");
    addL(nathan, "!");
    addL(clerk, "Sciocco!");
    changeShowCharacter(protag, angryFace2);
    addL(nathan, "Que dices!");
    addL(clerk, "Ho bisogno di lassativos!");
    changeShowCharacter(mary, sadFace);
    addL(mary, "I can't understand anything.");
    addL(nathan, "Infeliz, teño vinte años de experiencia en esquí!");
    addL(clerk, "Canaglia!");
    addL(nathan, "Te farei comer patacas!");
    addL(clerk, "Prende questo!");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "Ai!");
    changeShowCharacter(mary, surpriseFace);
    addL(mary, "Wait, why are you fighting?!");
    changeShowCharacter(protag, angryFace2);
    addL(nathan, "Ha!");
    addL(clerk, "Tropo lento!");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "Ui! Doe!");
    addL(clerk, "Ha! Ha! Ha!");
    changeShowCharacter(protag, angryFace2);
    addL(nathan, "É forte de máis! Resta-me unha opción!");
    addL(nathan, "Genki Dama!");
    addL(mary, "Stop! We're indoors!");
    break;
  case scene0_1_2_2:
    changeShowCharacter(mary, neutralFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0, 1);
    changeShowCharacter(protag);
    addL(nathan, "It's all right. I know sign language.");
    addL(mary, "He doesn't seem deaf.");
    addL(nathan, "[Good afternoon.]", false);
    addL(clerk, "[Konnichiwelcome!]", false);
    addL(nathan, "[Do you sell plastic model kits?]", false);
    changeShowCharacter(mary, neutralFace2);
    addL(clerk, "[I cannot understand that sign.]", false);
    addL(nathan, "[I'll spell it.]", false);
    addL(nathan, "[P]", false);
    addL(nathan, "[L]", false);
    changeShowCharacter(mary, neutralFace);
    addL(nathan, "[A]", false);
    addL(nathan, "[S]", false);
    changeShowCharacter(mary, neutralFace2, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0, 1, 4);
    changeShowCharacter(mary, neutralFace2, (camera.w-defpw*0.75)/2 - defpw/7, (camera.h-defph*0.75)/2 + defph*0.75/5, defpw*0.75, defph*0.75, 0, 1, 3);
    addL(clerk, "[Just kidding, I got it the first time.]", false);
    addL(nathan, "[What kind of models do you have?]", false);
    addL(clerk, "[Frog]", false);
    changeShowCharacter(mary, neutralFace);
    addL(nathan, "[Sorry, I think misunderstood you.]", false);
    changeShowCharacter(mary, neutralFace2);
    addL(clerk, "[Frog]", false);
    addL(nathan, "[What is the name of the first president of the United States?]", false);
    doAnim(mary, 1);
    addL(clerk, "[Frog]", false);
    addL(nathan, "[What is the name of the planet closest to Earth?]", false);
    addL(clerk, "[Frog]", false);
    //doAnim(mary, 1);
    addL(nathan, "[What is the name of an insectivorous amphibian?]", false);
    //changeShowCharacter(mary, happyFace2);
    addL(clerk, "[Frog]", false);
    changeShowCharacter(protag, angryFace);
    changeShowCharacter(mary, happyFace2);
    addL(nathan, ".........");
    changeShowCharacter(mary, happyFace2, (camera.w-defpw*0.75)/2 - defpw/7, (camera.h-defph*0.75)/2 + defph*0.75/5, defpw*0.75, defph*0.75, 0, 1, 4);
    changeShowCharacter(mary, happyFace3, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0, 1, 3);
    addL(mary, "Look what I found! Isn't this plastic model of a frog cute?");
    changeShowCharacter(protag, angryFace2);
    addL(nathan, "What?!");
    break;
  case scene0_1_1_1:
    changeShowCharacter(protag);
    changeShowCharacter(mary, happyFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0);
    addL(nathan, "White.");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "Then I'll get the white ones, too.");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Good afternoon! I'd like to buy these eggs.");
    addL(clerk, "Will you pay with cash or credit card?");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "I'm paying with cash. Just a second.");
    doAnim(mary, 2);
    addL(none, "*fumble* *fumble*");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "Huh?");
    doAnim(mary, 2);
    addL(none, "*fumble* *fumble* *fumble*");
    changeShowCharacter(mary, surpriseFace);
    addL(mary, "Huh? Where is it?");
    doAnim(mary, 2);
    addL(none, "*fumble* *fumble*\n*fumble* *fumble*");
    addL(clerk, "...");
    addL(mary, "A-ha-ha... Seems I forgot my wallet at home...");
    addL(mary, "...");
    changeShowCharacter(mary, sadFace);
    addL(mary, "...");
    addL(nathan, "(She's looking this way...)", false);
    addChoice(2, "Help her out", "Stay quiet");
    break;
  case scene0_1_1_2:
    changeShowCharacter(protag);
    changeShowCharacter(mary, happyFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0);
    addL(nathan, "They're the same thing.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "That's why I'm asking.");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "I don't know what you mean.");
    addL(mary, "I don't know what you mean, either. They're clearly different colors.");
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "Do you pick the white or black pieces in chess?");
    changeShowCharacter(mary, happyFace);
    addL(mary, "White, of course. They have a strategical advantage since they move first.");
    addL(nathan, "Why do you know that?");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "My sister's a Grandmaster.");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "...Is that true?");
    changeShowCharacter(mary, neutralFace2);
    addL(mary, "She could be. She's really good at chess.");
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "We'll get the white eggs, then.");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Okey-doke!");

    changeBackground(bgStreet2, 2);
    changeShowCharacter(mary, happyFace2, pX, pY, defpw, defph, 0, 1, 1);
    changeShowCharacter(protag, angryFace);
    addL(mary, "Look! Isn't the sunset beautiful?");
    addL(nathan, ".........");
    changeShowCharacter(mary, sadFace);
    addL(mary, "What's with the face?");
    addL(nathan, "That's just what my face looks like.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "Why are you making that expression?");
    addL(nathan, "Because I'm carrying twenty packets of ramen for a stranger.");
    changeShowCharacter(mary, sadFace);
    addL(mary, "I'm not a stranger! Besides, didn't I tell you you can take two of them?");
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "I don't like soy sauce...");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "Oh. Then I'll give you four.");

    addL(nathan, "That's the wrong operation.");
    changeShowCharacter(mary, sadFace);
    addL(mary, "One?");
    addL(nathan, "That's division.");
    changeShowCharacter(mary, happyFace);
    addL(mary, "Four.");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "That's what you just said.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "Well, what do you want that's not shoyu ramen, then?");
    addChoice(2, "Give me a kiss", "Give me a tuna sandwich");
    break;
  case scene0_1_1_2_1:
    changeShowCharacter(protag);
    changeShowCharacter(mary, neutralFace, pX, pY, defpw, defph, 0, 1);
    addL(nathan, "All right. I want you to...");
    addL(nathan, ".........");
    addL(nathan, "I want you to go by \'Saucy Mol\' for a week.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "What's \'Mol?\'");
    addL(nathan,  "It's short for \'Mary.\'");
    addL(mary, "Oh, I see.");
    addL(nathan, "So when any stranger asks your name, you'll say 'Saucy Mol.'");
    changeShowCharacter(mary, happyFace);
    addL(mary, "Can I call you \'Sauceless Nat?\'");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "...No.");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "It's short for 'Jonathan.'");
    addL(nathan, "I didn't ask.");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "\'Sauceless Nat!\'");
    addL(nathan, "I'm going home.");
    changeShowCharacter(mary, surpriseFace);
    addL(mary, "Wait, Sauceless Nat! My ramen!");
    break;
  case scene0_1_1_2_2:
    changeShowCharacter(protag);
    changeShowCharacter(mary, neutralFace, pX, pY, defpw, defph, 0, 1);
    addL(nathan, "Give me a tuna sandwich.");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "Sure, what do you like in your sandwich? Mayonnaise?\nMustard? Mayonnaise?");
    addL(nathan, "...Caviar.");
    changeShowCharacter(mary, happyFace);
    addL(mary, "What else?");
    addL(nathan, "Truffles. And gold shavings.");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Okay, I'll be back in a second!");
    changeShowCharacter(mary, happyFace3, pX, pY, defpw, defph, 0, 1, 2);
    addL(nathan, ".........");
    addL(nathan, ".........");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "Wait!");
    break;
  case scene0_1_1_1_1:
    changeShowCharacter(protag);
    changeShowCharacter(mary, neutralFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0);
    addL(nathan, "Scan these as well.");
    addL(none, "............");
    addL(clerk, "Have a good afternoon!");
    changeBackground(bgStreet2, 2);
    changeShowCharacter(mary, sadFace, pX, pY, defpw, defph, 0, 1, 1);
    addL(mary, "Sigh... That was scary.");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "Thanks, Jonathan. I'll give you the money back tomorrow.");
    addL(nathan, "Okay.");
    changeShowCharacter(mary, neutralFace2);
    addL(mary, "Well, then, as thanks...");
    addL(nathan, "I don't need it.");
    changeShowCharacter(mary, sadFace);
    addL(mary, "What? But you don't even know what I'm going to give you yet.");
    addL(nathan, "It's probably nothing good.");
    changeShowCharacter(mary, neutralFace);
    addL(mary, "Well, I'll bet five dollars you can't guess what it is.");
    changeShowCharacter(mary, happyFace);
    addL(mary, "I'll give you a hint: you can't\nguess it.");
    addChoice(2, "It's a kiss", "It's a tuna sandwich");
    break;
  case scene0_1_1_1_2:
    changeShowCharacter(protag);
    changeShowCharacter(mary, sadFace, (camera.w-defpw*1.25)/2, (camera.h-defph*1.25)/2 + defph*1.25/5, defpw*1.25, defph*1.25, 0);
    addL(nathan, ".........");
    changeShowCharacter(mary, happyFace2);
    addL(mary, "I said, 'seems I forgot my wallet at home!'");
    addL(none, "*glance*");
    addL(nathan, ".........");
    addL(mary, ".........");
    addL(mary, "...Jonathan?");
    addL(nathan, "Who are you?");
    changeShowCharacter(mary, surpriseFace);
    addL(mary, "What? It's Mary! Don't tell me you forgot again!");
    changeShowCharacter(protag, angryFace2);
    addL(nathan, "I do not know anyone by the name of Mary! I have never met this woman in my life!");
    addL(mary, "Jonathan!");
    addL(nathan, "My name is not Jonathan, and it wasn't me who installed Rensenware on the library computers!");
    addL(nathan, "Goodbye!");
    changeShowCharacter(mary, mairiFace);
    addL(mary, "Wait, Jonathan? Where are you going? Wait!");
    break;
  case scene0_1_1_1_1_1:
    changeShowCharacter(mary, surpriseFace3, pX, pY, defpw, defph, 0);
    changeShowCharacter(protag, angryFace2);
    addL(nathan, "I recognize this setup! You were going to kiss me just like in those corny old romance dramas!");
    addL(nathan, "A melodramatic track would play during the entire scene, while the two lovers confess their feelings to each other...");
    changeShowCharacter(protag, neutralFace);
    changeShowCharacter(mary, neutralFace);
    addL(nathan, "\'Extra Number One, I love you!\'");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "\'What took you so long, Extra Number Two? I love you, too!\'");
    changeShowCharacter(protag, neutralFace);
    changeShowCharacter(mary, happyFace);
    addL(nathan, "They draw each other into a loving embrace...");
    changeShowCharacter(mary, happyFace2);
    addL(nathan, "Then the credits roll as we stare at their black silhouettes outlined against the red–orange sunset...");
    changeShowCharacter(protag, angryFace2);
    addL(nathan, "Directed by Michael Bay.");
    changeShowCharacter(mary, happyFace3);
    addL(mary, "Bravo!");
    changeShowCharacter(mary, happyFace2);
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "Thanks.");
    changeShowCharacter(mary, happyFace);
    addL(mary, "...");
    changeShowCharacter(mary, neutralFace2);
    addL(mary, "...");
    addL(mary, "I don't mind it if it's on the cheek.");
    addL(nathan, ".........");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "What?");
    changeShowCharacter(protag, neutralFace);
    changeShowCharacter(mary, surpriseFace2);
    addL(mary, "N-Never mind! See you at school tomorrow!");
    addL(mary, "Thanks! Bye! Later!");
    changeShowCharacter(mary, neutralFace, pX, pY, defpw, defph, 0, 1, 2);
    changeShowCharacter(protag, neutralFace);
    addL(nathan, ".........");
    changeShowCharacter(protag, happyFace);
    addL(nathan, "The End.");
    break;
  case scene0_1_1_1_1_2:
    changeShowCharacter(mary, surpriseFace3, pX, pY, defpw, defph, 0);
    changeShowCharacter(protag, neutralFace);
    addL(nathan, "Is it a tuna sandwich?");
    changeShowCharacter(mary, surpriseFace);
    addL(mary, "What?! How did you know?!");
    addL(nathan, "I had a feeling.");
    addL(nathan, "You're a psychic! You have ESP!");
    addL(nathan, "No, I just guessed.");
    changeShowCharacter(mary, sadFace);
    addL(mary, "What am I thinking about right now?");
    addL(nathan, "......");
    addL(mary, "......");
    addL(nathan, "Shoyu ramen.");
    changeShowCharacter(mary, surpriseFace);
    addL(mary, "Jumping Jehosaphat! How?!");
    changeShowCharacter(protag, angryFace);
    addL(nathan, "You're too simple...");
    break;
  }
}

void Cutscene::maryNathanScript() {
  switch(sceneID) {
  case scene0:
    changeShowCharacter(protag, happyFace);
    changeBackground(bgLivingRoom, 2);
    addL(mary, "I'm back from school, Mom!");
    addL(mom, "Oh, Molly, thank goodness you're here. Can you do me a favour?");
    addL(mom, "I forgot to buy eggs for today's supper. Can you go buy them for me?");
    // changeShowCharacter(protag, angryFace);
    addChoice(2, "Sure", "No");
    break;
  case scene0_2:
    changeShowCharacter(protag, sadFace);
    addL(mary, "I don't want to.");
    addL(mom, "Then we're having omelettes without eggs for today's supper.");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "Okay.");
    addL(mary, "...");
    changeShowCharacter(protag, surpriseFace);
    addL(mary, "What?!");
    break;
  case scene0_1:
    changeShowCharacter(protag, happyFace3);
     changeShowCharacter(nathan, neutralFace2, cPX(0.75)-defpw/5, cPY(0.75), defpw*0.75, defph*0.75, 0, 0, -1);
    addL(mary, "Sure!");
    changeBackground(bgStreet1, 2);
    changeShowCharacter(protag, happyFace2);
    addL(mary, "La-la-la! ♪\n Going to the grocery store! ♪\n In the sunshine! ♪");
    changeShowCharacter(nathan, neutralFace2, cPX(0.75)-defpw/5, cPY(0.75), defpw*0.75, defph*0.75, 0, 1, 5);
    changeShowCharacter(nathan, neutralFace2, cPX(0.75)-defpw/5, cPY(0.75), defpw*0.75, defph*0.75, 0, 1, 2);
    addL(mary, "Oh, it's Jonathan!");
    changeShowCharacter(nathan, neutralFace2, cPX(1), cPY(1), defpw, defph, 0, 1, 2);
    changeShowCharacter(nathan, neutralFace, cPX(1), cPY(1), defpw, defph, 0, 1, 3);
    changeShowCharacter(protag, happyFace3);
    addL(mary, "Gooooooooooooooooood!");
    addL(mary, "After!");
    addL(mary, "Noon!");
    changeShowCharacter(protag, happyFace2);
    addL(nathan, ".........");
    changeShowCharacter(nathan, neutralFace2, cPX(1), cPY(1), defpw, defph, 0, 1, 2);
    changeShowCharacter(protag, mairiFace);
    addL(mary, "Wait! Don't just nod and walk away!");
    changeShowCharacter(nathan, neutralFace, cPX(1), cPY(1), defpw, defph, 0, 1, 3);
    addL(nathan, "Who are you?");
    changeShowCharacter(protag, surpriseFace);
    addL(mary, "What?! Have you forgotten me already?");
    addL(mary, "It's Mary, Mary van Buren! I'm your classmate!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "You can't expect me to remember every single classmate's name. The school year's just begun.");
    changeShowCharacter(protag, sadFace);
    addL(mary, "It started a month ago!");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "Really?");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Because I'm a kind person, I'm willing to forgive your outrageous lack of delicacy for the measly price of one Snickers bar.");
    addL(mary, "So, pay up.");
    addL(nathan, "That's hardly a kind tone.");
    addL(mary, "Pay up, please.");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "Your English grades must be really low.");
    changeShowCharacter(protag, sadFace);
    addL(mary, "That's rude. They're average, actually.");
    addL(nathan, "I don't believe it.");
    addL(mary, "Ask me any English-related question. I bet I can answer it.");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "Who wrote 'Romeo and Juliet?'");
    addChoice(2, "Isaac Newton", "George Washington");
    break;
  case scene0_1_1:
    changeShowCharacter(protag, neutralFace);
    changeShowCharacter(nathan, neutralFace, cPX(), cPY(), defpw, defph, 0);
    addL(mary, "Isaac Newton?");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, ".......");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "Or was he the one who wrote 'Crime and Punishment?'");
    addL(nathan, ".......");
    changeShowCharacter(protag, sadFace);
    addL(mary, "Okay, maybe my grades are slightly below average.");
    
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "Shouldn't you be heading to the grocery store?");
    changeShowCharacter(protag, surpriseFace);
    addL(mary, "Suffering catfish! How did you know?!");
    addL(nathan, "I heard you singing it. The grocery song.");
    changeShowCharacter(protag, mairiFace);
    addL(mary, "Geez, you heard that? That's embarrassing.");
    changeShowCharacter(protag, happyFace);
    addL(mary, "And you? Where are you going?!");
    addL(nathan, "To the grocery store.");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "What a coincidence! Let's go together, then!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "I'd rather not...");
    changeShowCharacter(protag, happyFace3);
    addL(mary, "Let's-a-go-go!");
    
    changeBackground(bgGrocery, 1);
    changeShowCharacter(nathan, neutralFace, cPX(1.25), cPY(1.25), defpw*1.25, defph*1.25, 0, 1, 1);
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Chicken... Beef... Bacon...");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Oh, there it is! My favorite! Soy sauce-flavored ramen!");
    addL(nathan, ".........");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "I don't remember the last time I bought the other flavors.\nSoy sauce is just better.");
    addL(mary, "For example, chicken ramen doesn't taste like chicken at all.\nI don't know why they named it that.");
    addL(nathan, ".........");
    addL(mary, "Bacon gets close to tasting like bacon, but not quite.");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "I don't like it. I think they call\n that the \'uncanny valley.\'");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, ".........");
    addL(nathan, "Are you here to buy eggs or instant noodles?");
    changeShowCharacter(protag, neutralFace);
    addChoice(2, "Eggs", "Ramen");
    break;
  case scene0_1_2:
    changeShowCharacter(protag, happyFace2);
    changeShowCharacter(nathan, neutralFace, cPX(), cPY(), defpw, defph, 0);
    addL(mary, "George Washington!");
    addL(nathan, "No, George Washington didn't produce any literature of note.");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "It was pretty close, though, wasn't it?");
    addL(nathan, "No.");
    changeShowCharacter(protag, sadFace);
    addL(mary, "He was a great man, though.");
    addL(nathan, "That's not relevant.");
    addL(mary, "He freed the slaves.");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "That was Abraham Lincoln.");
    changeShowCharacter(protag, mairiFace);
    addL(mary, "Piers... P-Pake... Pearson...");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "How many hours do you study a day?");
    changeShowCharacter(protag, surpriseFace);
    addL(mary, "Hours?!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "Good grief. You're going to have a hard time after you graduate.");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Are you worried about me?");
    addL(nathan, "Of course I am. You're a worse case than my sister.");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "Now, that you mention it, I haven't met your sister yet.");
    changeShowCharacter(nathan, neutralFace2);
    addL(nathan, "Well, she doesn't go outside much.");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "I'll go meet her now!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "Wait...");
    
    changeBackground(bgLivingRoom, 2);
    changeShowCharacter(nathan, neutralFace, cPX(1.25), cPY(1.25), defpw*1.25, defph*1.25, 0, 1, 1);
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Excuse me! Anyone at home?");
    addL(mom, "Oh, are you back already, Nate?");
    addL(mom, "My word, and there's a girl with you! Is that your girlfriend?");
    addChoice(2, "We're friends", "We've been dating for a month");
    break;
  case scene0_1_2_1:
    changeShowCharacter(protag, sadFace);
    changeShowCharacter(nathan, angryFace, cPX(1.25), cPY(1.25), defpw*1.25, defph*1.25, 0, 1, 1);
    addL(mary, "We're friends!");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "That's a wise choice.");
    changeShowCharacter(protag, happyFace3);
    addL(mary, "Good afternoon! I'd like to buy these eggs.");
    addL(clerk, "Will you pay with cash or credit card?");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "I'm paying with cash. Just a second.");
    doAnim(protag, 2);
    addL(none, "*fumble* *fumble*");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Huh?");
    doAnim(protag, 2);
    addL(none, "*fumble* *fumble* *fumble*");
    changeShowCharacter(protag, surpriseFace);
    addL(mary, "Huh? Where is it?");
    doAnim(protag, 2);
    addL(none, "*fumble* *fumble*\n*fumble* *fumble*");
    addL(nathan, ".......");
    changeShowCharacter(protag, surpriseFace3);
    addL(nathan, "Excuse me. We're taking this as well.");
    changeShowCharacter(protag, neutralFace);
    addL(none, "............");
    addL(clerk, "Have a good afternoon!");
    changeBackground(bgStreet2, 2);
    changeShowCharacter(nathan, neutralFace, cPX(), cPY(), defpw, defph, 0, 1, 1);
    changeShowCharacter(protag, sadFace);
    addL(mary, "Sigh... That was scary.");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Thanks, Jonathan. I'll give you the money back tomorrow.");
    addL(nathan, "Okay.");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "Well, then, as thanks...");
    addChoice(2, "Sing a song", "Do a hand stand");
    break;
  case scene0_1_1_1:
    changeShowCharacter(protag, sadFace);
    changeShowCharacter(nathan, angryFace, cPX(1.25), cPY(1.25), defpw*1.25, defph*1.25, 0, 1, 1);
    addL(mary, "I'll buy the eggs. I don't want my mom to yell at me.");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "That's a wise choice.");
    changeShowCharacter(protag, happyFace3);
    addL(mary, "Good afternoon! I'd like to buy these eggs.");
    addL(clerk, "Will you pay with cash or credit card?");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "I'm paying with cash. Just a second.");
    doAnim(protag, 2);
    addL(none, "*fumble* *fumble*");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Huh?");
    doAnim(protag, 2);
    addL(none, "*fumble* *fumble* *fumble*");
    changeShowCharacter(protag, surpriseFace);
    addL(mary, "Huh? Where is it?");
    doAnim(protag, 2);
    addL(none, "*fumble* *fumble*\n*fumble* *fumble*");
    addL(nathan, ".......");
    changeShowCharacter(protag, surpriseFace3);
    addL(nathan, "Excuse me. We're taking this as well.");
    changeShowCharacter(protag, neutralFace);
    addL(none, "............");
    addL(clerk, "Have a good afternoon!");
    changeBackground(bgStreet2, 2);
    changeShowCharacter(nathan, neutralFace, cPX(), cPY(), defpw, defph, 0, 1, 1);
    changeShowCharacter(protag, sadFace);
    addL(mary, "Sigh... That was scary.");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Thanks, Jonathan. I'll give you the money back tomorrow.");
    addL(nathan, "Okay.");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "Well, then, as thanks...");
    addChoice(2, "Sing a song", "Do a hand stand");
    break;
  case scene0_1_1_2:
    changeShowCharacter(protag, sadFace);
    changeShowCharacter(nathan, angryFace, cPX(1.25), cPY(1.25), defpw*1.25, defph*1.25, 0, 1, 1);
    addL(mary, "Sorry, Mom, but I like ramen more than omelettes.");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "You can buy both, you know.");
    addL(mary, "But then my love for ramen will seem insincere!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "...Who cares?");
    addL(mary, "Nissin Foods.");
    addL(nathan, "Is that a fact?");
    changeShowCharacter(protag, happyFace);
    addL(mary, "What's your favorite brand?");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "I don't have one.");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "I guess I'll get this one, then.");
    
    changeBackground(bgStreet2, 2);
    changeShowCharacter(nathan, angryFace, cPX(), cPY(), defpw, defph, 0, 1, 1);
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Look! Isn't the sunset beautiful?");
    addL(nathan, ".........");
    changeShowCharacter(protag, sadFace);
    addL(mary, "What's with the face?");
    addL(nathan, "That's just what my face looks like.");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Why are you making that expression?");
    addL(nathan, "Because I'm carrying twenty packets of ramen for a stranger.");
    changeShowCharacter(protag, sadFace);
    addL(mary, "I'm not a stranger! Besides, didn't I tell you you can take two of them?");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "I don't like soy sauce...");
    addL(mary, "Why didn't you say that earlier? Then I would've gotten the other flavors.");
    addL(nathan, "I don't like instant ramen...");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "What do you like?");
    addL(nathan, "Tuna.");
    addL(mary, "What else?");
    addL(nathan, "Peanut butter.");
    addL(mary, "What else?");
    addL(nathan, "Cheese.");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Then I'll make you a tuna-\npeanut-butter-cheese sandwich!");
    addL(nathan, "..........");
    addL(nathan, "That sounds delicious.");
    changeShowCharacter(protag, happyFace3);
    addL(mary, "Right?");
    break;
  case scene0_1_1_1_1:
    changeShowCharacter(protag, happyFace2);
    changeShowCharacter(nathan, neutralFace, cPX(), cPY(), defpw, defph, 0, 1, 1);
    addL(mary, "I'm going to write and sing you a custom theme song!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "What?");
    changeShowCharacter(protag, happyFace3);
    changeShowCharacter(nathan, neutralFace);
    addL(mary, "Have you seen him?\nJonathan! ♪");
    addL(mary, "Have you heard of him?\nJonathan! ♪");
    changeShowCharacter(protag, sadFace);
    addL(mary, "He's sleep-deprived! ♪\nHe's below-average height! ♪\nHe's my classmate! ♪");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "If you were to describe him by three feelings, it would be... ♪");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "Justice, love, and friendship! ♪");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "That's just Mazinger Z's ending song with worse lyrics.");
    changeShowCharacter(protag, sadFace);
    addL(mary, "It's hard to come up with original lyrics.");
    break;
  case scene0_1_1_1_2:
    changeShowCharacter(protag, happyFace2);
    changeShowCharacter(nathan, neutralFace, cPX(), cPY(), defpw, defph, 0, 1, 1);
    addL(mary, "I'm going to do a hand stand!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "I don't think that's a good idea.");
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Why?");
    addL(nathan, "You're wearing a skirt.");
    changeShowCharacter(protag, mairiFace);
    addL(mary, "Oh, right. Never mind, then.");
    changeShowCharacter(protag, neutralFace2);
    addL(mary, "What's some other way I could show my gratitude?");
    changeShowCharacter(nathan, neutralFace);
    addL(nathan, "I don't think you need to do anything.");
    changeShowCharacter(protag, happyFace2);
    addL(mary, "I see, so just my presence is already enough thanks to you!");
    changeShowCharacter(nathan, angryFace);
    addL(nathan, "Nobody said that.");
    addL(mary, "He-he-he.");
    changeShowCharacter(nathan, happyFace);
    addL(nathan, "Good grief.");
    changeBackground(bgStreet1Evening, 3);
    changeShowCharacter(nathan, neutralFace);
    changeShowCharacter(protag, neutralFace);
    addL(mary, "Oh, my house is that way.");
    addL(nathan, "I'll see you tomorrow, then.");
    changeShowCharacter(protag, happyFace);
    addL(mary, "Bye! See you at school!");
    addL(nathan, "Later.");
    changeShowCharacter(nathan, neutralFace, cPX(), cPY(), defpw, defph, 0, 1, 2);
    changeShowCharacter(protag, happyFace2);
    addL(mary, "La-la-la! ♪\n Going home! ♪");
    break;
  }
}