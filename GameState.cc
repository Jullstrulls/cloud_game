#include "GameState.h"

Game_State::Game_State(std::shared_ptr<Game> game)
  :State{game} {}

void Game_State::update(sf::Time delta, sf::RenderWindow &window)
{
  
  sf::Event event;
  
  while(window.pollEvent(event))
    {
      switch(event.type)
	{
	case sf::Event::Closed:
	  window.close();
	  break;
	default:
	  break;
	}
    }
}

void Game_State::render(sf::RenderWindow &window)
{
  window.clear(sf::Color(71,160,255,255));
  window.display();
}
