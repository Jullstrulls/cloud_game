#include "Menu_State.h"
#include "Texture_Manager.h"

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
  
  for (std::shared_ptr<Cloud> cloud_obj : clouds)
  {
    cloud_obj -> move(delta);
  }

}

void Menu_State::render(sf::RenderWindow &window)
{
  window.clear(sf::Color(71,160,255,255));
  for (std::shared_ptr<Cloud> cloud_obj : clouds)
    {
      window.draw(cloud_obj -> cloud);
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
      float random_speed = (rand() % 9) + 1;
      
      clouds.push_back(std::shared_ptr<Cloud>(new Cloud{sf::Vector2f(random_width, random_height), sf::Vector2f(random_x, random_y), random_opacity, random_speed}));	 
    }
}

Menu_State::Cloud::Cloud(sf::Vector2f const& size, sf::Vector2f const& position, float const opacity, float const speed)
  :cloud{size}, size{size}, location{position}, speed{speed}
{
   cloud.setPosition(location);
   cloud.setTexture(Texture_Manager::get("cloud.png"));
   cloud.setFillColor(sf::Color(255,255,255,opacity));
}

void Menu_State::Cloud::move(sf::Time delta)
{
  float distance = speed * (delta.asMicroseconds() / 1000000.0f);
  location.x += 2 * distance;

  if (location.x >= 1024)
    {
      location.x = - size.x;
    }
  cloud.setPosition(location);
}



