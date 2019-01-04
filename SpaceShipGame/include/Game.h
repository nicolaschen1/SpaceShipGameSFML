#ifndef JEU_H
#define JEU_H

#include "Space.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <exception>

class Game
{
    public:
        Game(Space& p_space);
        void start();
        void finish();
        void addPoints(int points);
        inline bool isInProgress() const { return onGoing; };
        void show(sf::RenderWindow& frame) const;
        void initException(std::exception const& exception);

    protected:

    private:
        void refreshText();
        void refreshBestScore();
        Space& space;
        bool onGoing{false};
        int score{};
        int bestScore{};
        sf::Text bestScoreText{};
        sf::Text scoreText{};
        sf::Sprite homeSprite{};
        sf::Font font{};
        std::unique_ptr<sf::Text> exceptionText{nullptr};
};

#endif // JEU_H
