#include "Menu_State.h"

Menu_State::Menu_State(std::shared_ptr<Game> game)
  :State{game}, selected_item{0}
{
  add_option(0, "PLAY");
  add_option(1, "RULES");
  add_option(2, "EXIT");

  add_clouds(10);
}

void Menu_State::add_option(int index, string input)
{
  menu[index].setFont(font);
  menu[index].setFillColor(sf::Color::White);
  
  if (index == selected_item)
    {
      menu[index].setOutlineColor(sf::Color(0,0,0,255));
      menu[index].setOutlineThickness(5);
    }  
  menu[index].setString(input);

  sf::FloatRect textRect = menu[index].getLocalBounds();
  menu[index].setOrigin(textRect.left + textRect.width/2.0f,
		 textRect.top  + textRect.height/2.0f);
  menu[index].setPosition(sf::Vector2f(width / 2, (height / 4) * (index + 1)));
}

void Menu_State::update(sf::Time delta, sf::RenderWindow &window)
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

  float distance = 5 * (delta.asMicroseconds() / 1000000.0f);
  for (sf::RectangleShape cloud : clouds)
    {
      // cout << "tho" << endl;
      // sf::Vector2f location{cloud.getPosition()};
      // location.x += 5 * distance;
      cloud.setPosition(sf::Vector2f(20,20));//location);
    }
}

void Menu_State::render(sf::RenderWindow &window)
{
  window.clear(sf::Color(71,160,255,255));
  for (sf::RectangleShape cloud : clouds)
    {
      window.draw(cloud);
    }
  for (int i{0}; i < 3; i++)
    {
      window.draw(menu[i]);
    }
  window.display();
}

void Menu_State::add_clouds(int nr_of_clouds)
{
  for (int i{0}; i < nr_of_clouds; i++)
    {
      float random_width = rand() % 500;
      float random_height  = rand() % 300;
      float random_x = rand() % 1024;
      float random_y = rand() % 768;
      float random_opacity = rand() % 255;
      
      sf::RectangleShape cloud{sf::Vector2f(random_width, random_height)};
      cloud.setPosition(sf::Vector2f(random_x, random_y));
      cloud.setFillColor(sf::Color(255,255,255,random_opacity));

      clouds.push_back(cloud);	 
    }
}
