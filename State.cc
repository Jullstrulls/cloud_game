#include "State.h"

State::State(std::shared_ptr<Game> game)
  :game{game},font{} 
{
  if (!font.loadFromFile(state_font))
    {
      throw std::logic_error("Failed to load font!");
    }
}
