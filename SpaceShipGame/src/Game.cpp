#include "Game.h"

#include "Ship.h"
#include "Asteroid.h"
#include <memory>
#include "ResourcesManager.h"
#include <experimental/string_view>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

using namespace std::string_literals;

const sf::Color SHIP_COLOR{sf::Color{128,255,128}};

Game::Game(Space& p_space) : space{p_space}
{
    font.loadFromFile("resources/Chump_Change.otf");
    scoreText.setFont(font);
    scoreText.move(0, 30);
    bestScoreText.setFont(font);

    auto file = std::ifstream{"bestScore.txt"};
    if (file.is_open()) {
        file >> bestScore;
    }
    file.close();

    refreshBestScore();
    try {
        homeSprite.setTexture(ResourcesManager<sf::Texture>::getRessource("resources/homeGame.png"));
    } catch (std::exception const& exception) {
        initException(exception);
    }
}

void Game::start() {
    onGoing = true;
    score = 0;
    refreshText();
    space.add(std::make_unique<Ship>(*this, space, SHIP_COLOR));
    space.add(std::make_unique<Asteroid>(*this, space));
    space.add(std::make_unique<Asteroid>(*this, space));
    space.add(std::make_unique<Asteroid>(*this, space));
}

void Game::addPoints(int points) {
    score += points;
    refreshText();
}

void Game::finish() {
    onGoing = false;
    if (score > bestScore) {
        bestScore = score;
        refreshBestScore();
        auto file = std::ofstream{"bestScore.txt"};
        //file.open("bestScore.txt");
        if (file.is_open()) {
            file << bestScore;
        } else {
            throw std::runtime_error{"Impossible d'ouvrir le file bestScore en écriture"};
        }
        file.close();
    }
    space.empty();
}

void Game::show(sf::RenderWindow& frame) const {
    if (exceptionText) {
        frame.draw(*exceptionText);
    } else {
        if (!onGoing && space.isEmpty()) {
            frame.draw(homeSprite);
        } else {
            frame.draw(scoreText);
        }
        frame.draw(bestScoreText);
    }
}

void Game::initException(std::exception const& exception) {
    exceptionText = std::make_unique<sf::Text>();
    //exceptionText->setFont(font);
    exceptionText->setString(exception.what());
    exceptionText->setFillColor(sf::Color::Red);
}

void Game::refreshText() {
    scoreText.setString("Score : "s + std::to_string(score));
}

void Game::refreshBestScore() {
    bestScoreText.setString("Meilleur score : "s + std::to_string(bestScore));
}
