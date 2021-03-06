#pragma once
#include "Common.h"
#include "State.h"

class Game
{
public:
  Game();
  //unika pekare i states kommer försvinna
  ~Game() = default;

  void push_state(std::unique_ptr<State> state);
  void pop_state();

  void run(sf::RenderWindow &window);

private:
  std::vector<std::unique_ptr<State>> states;

  std::shared_ptr<Game> ptr_myself;
  
};
