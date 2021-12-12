#include "Common.h"
#include "Game.h"

const size_t width = 1024;
const size_t height = 768;
const string state_font = "Kid Games.ttf";

int main()
{
  sf::RenderWindow window{sf::VideoMode{width, height}, "Cloud chaser"};
  window.setKeyRepeatEnabled(false);
  window.setVerticalSyncEnabled(true);

  Game game{};
  game.run(window);
}
