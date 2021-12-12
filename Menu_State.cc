#include "Menu_State.h"
#include "Texture_Manager.h"
#include "Game.h"

Menu_State::Menu_State(std::shared_ptr<Game> game)
  :State{game}, selected_item{0}, rules{false}
{
  game_name.setFont(font);
  game_name.setFillColor(sf::Color::White);
  game_name.setOutlineColor(sf::Color(0,0,0,255));
  game_name.setOutlineThickness(5);
  game_name.setString("CLOUD CHASE");
  game_name.setCharacterSize(80);
  sf::FloatRect textRect =game_name.getLocalBounds();
  game_name.setOrigin(textRect.left + textRect.width/2.0f,
			textRect.top  + textRect.height/2.0f);
  game_name.setPosition(sf::Vector2f(width / 2, 200));
  
  add_option(0, "PLAY");
  add_option(1, "RULES");
  add_option(2, "EXIT");

  add_clouds(10);

  
  if (!buffer.loadFromFile("tik.wav"))
    {
      cout << "failed to load sound tik.wav" << endl;
    }
  switch_sound.setBuffer(buffer);
}

void Menu_State::add_option(int index, string input)
{
  menu[index].setFont(font);
  menu[index].setFillColor(sf::Color::White);
  menu[index].setOutlineColor(sf::Color(0,0,0,255));
  
  if (index == selected_item)
    {
      menu[index].setOutlineThickness(5);
    }
  else
    {
      menu[index].setOutlineThickness(0);
    }  
  menu[index].setString(input);

  sf::FloatRect textRect = menu[index].getLocalBounds();
  menu[index].setOrigin(textRect.left + textRect.width/2.0f,
		 textRect.top  + textRect.height/2.0f);
  menu[index].setPosition(sf::Vector2f(width / 2, ((height) / 8) * (index + 3)));
}

void Menu_State::update(sf::Time delta, sf::RenderWindow &window)
{
  sf::Event event;
  

  
  for (std::shared_ptr<Cloud> cloud_obj : clouds)
  {
    cloud_obj -> move(delta);
  }

  while(window.pollEvent(event))
    {
      switch(event.type)
	{
	case sf::Event::Closed:
	  window.close();
	  break;
	case sf::Event::KeyPressed:
	  on_key_press(event.key.code, window);
	  break;
	default:
	  break;
	}
    }
}

void Menu_State::render(sf::RenderWindow &window)
{
  window.clear(sf::Color(71,160,255,255));
  for (std::shared_ptr<Cloud> cloud_obj : clouds)
    {
      window.draw(cloud_obj -> cloud);
    }
  window.draw(game_name);
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

void Menu_State::on_key_press(sf::Keyboard::Key key, sf::RenderWindow &window)
{
  if (key == sf::Keyboard::Up && selected_item > 0)
    {
      switch_sound.play();
      menu[selected_item].setOutlineThickness(0);
      selected_item--;
      menu[selected_item].setOutlineThickness(5);
    }
  else if (key == sf::Keyboard::Down && selected_item <= 3)
    {
      switch_sound.play();
      menu[selected_item].setOutlineThickness(0);
      selected_item++;
      menu[selected_item].setOutlineThickness(5);
    }
  else if (key == sf::Keyboard::Enter)
    {
      if (selected_item == 0)
	{
	  game -> pop_state();
	}
      else if (selected_item == 1)
	{
	  //byt till rules
	}
      else if (selected_item == 2)
	{
	  window.close();
	}
    }
}

