#pragma once
#include "Common.h"
#include "State.h"

class Game_State : public State
{
public:
  Game_State(std::shared_ptr<Game> game);

  virtual void update(sf::Time delta, sf::RenderWindow &window) override;
  virtual void render(sf::RenderWindow &window) override;

private:
  
  
};
