/*
StarShipGame C++
VERSION: 1.0

Description: It is a game developed in C++ whose goal is to destroy asteroids or comets with its space ship.
Developer: Nicolas CHEN
*/

#include <SFML/Graphics.hpp>
#include "Space.h"
#include "Game.h"
#include <exception>

using namespace std;

constexpr int WINDOW_LENGTH{800};
constexpr int WINDOW_HEIGHT{600};


int main()
{
    sf::RenderWindow frame{sf::VideoMode{WINDOW_LENGTH, WINDOW_HEIGHT}, "StarShipGame"};
    Coordinates::SpaceInit(WINDOW_LENGTH, WINDOW_HEIGHT);
    auto space = Space{};
    auto game = Game{space};

    auto startGame{false};
    while(frame.isOpen()) {
        try {
            auto event = sf::Event{};
            while (frame.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    frame.close();
                }
                if (event.type == sf::Event::KeyPressed && !game.isInProgress()) {
                    game.start();
                }
            }

            space.refresh();
            space.manageCollisions();

            frame.clear();
            space.show(frame);
            game.show(frame);
            frame.display();
            space.clean();
        } catch(std::exception const& exception) {
            game.initException(exception);
        }


    }
    return 0;
}
