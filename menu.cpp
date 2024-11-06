void Menu::renderMenu() {
  switch(menuScreenID) {
  case scrMainMenu:
    gCoastBG.render(camera.x,camera.y);
    gMenuBG.render(camera.x,camera.y);
    break;
  }
}

void Menu::handleEvent(SDL_Event& e) {
}

Menu menu;
