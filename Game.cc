#include "Game.h"
#include "Menu_State.h"
#include "GameState.h"

Game::Game()
  :states{}, ptr_myself{this}
{
  push_state(std::move(std::unique_ptr<State> (new Game_State{ptr_myself})));
  push_state(std::move(std::unique_ptr<State> (new Menu_State{ptr_myself})));
}

void Game::push_state(std::unique_ptr<State> state)
{
  states.push_back(std::move(state));
}

void Game::pop_state()
{
  //cout << states.size() << endl;
  states.pop_back(); 
}

void Game::run(sf::RenderWindow &window)
{
  sf::Clock clock;

  while(window.isOpen())
    {
      auto delta = clock.restart();

      states.back() -> update(delta, window);
      states.back() -> render(window);
    }
}
