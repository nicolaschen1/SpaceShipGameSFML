#include "ResourcesManager.h"
#include <iostream>
#include "ExceptionResourceNotFound.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

template<>
std::unordered_map<std::experimental::string_view, sf::Texture> ResourcesManager<sf::Texture>::resources{};

template<>
std::unordered_map<std::experimental::string_view, sf::SoundBuffer> ResourcesManager<sf::SoundBuffer>::resources{};


