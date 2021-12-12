#pragma once
#include "Common.h"
#include <map>

//hanterar textures
//singleton class
//kopierat från Filip Strömbäck i kursen TDP005 inheritance

class Texture_Manager
{
public:
  //returnerar pekare till texture eller laddar in texture om ej finns
  static sf::Texture *get(const string &name);

private:
  //privat konstruktor, bara vi kan skapa instanser
  Texture_Manager() = default;

  //enda instansen av denna klass
  static Texture_Manager instance;

  //map med sträng på filnamn och pekare till laddad texture
  std::map<string, std::unique_ptr<sf::Texture>> textures;
};
