#pragma once
#include "Common.h"

class Game;

class State
{
 public:
  State(std::shared_ptr<Game> game);
  virtual ~State() = default;
  
  //delete copy constructor, assignment
  //delete move constructor, assignment
  
  virtual void update(sf::Time delta, sf::RenderWindow &window) = 0;
  virtual void render(sf::RenderWindow &window) = 0;

protected:
  //shared ptr pga kommer finnas flera instanser av state
  std::shared_ptr<Game> game;
  sf::Font font;
};
