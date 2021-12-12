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
  struct Cloud
  {
    Cloud(sf::Vector2f const& size, sf::Vector2f const& position, float const opacity, float const speed);
    void move(sf::Time delta);
    sf::RectangleShape cloud;
    sf::Vector2f size;
    sf::Vector2f location;
    float speed;
  };
  
  int selected_item;
  sf::Text menu[NR_OF_MENY_ITEMS];
  vector<std::shared_ptr<Cloud>> clouds;  

  void add_option(int index, string input);
  
};
