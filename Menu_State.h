#pragma once
#include "State.h"

#define NR_OF_MENY_ITEMS 3

class Menu_State : public State
{
public:
  Menu_State(std::shared_ptr<Game> game);
  
  //anropas från run?
  void on_key_press(sf::Keyboard::Key key);

  virtual void update(sf::Time delta, sf::RenderWindow &window) override;
  virtual void render(sf::RenderWindow &window) override;

  int GetPressedItem();

  void add_clouds(int nr_of_clouds);
  
private:
  int selected_item;
  sf::Text menu[NR_OF_MENY_ITEMS];
  vector<sf::RectangleShape> clouds;

  void add_option(int index, string input);
  
};
