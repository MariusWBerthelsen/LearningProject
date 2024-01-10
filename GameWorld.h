#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <SFML/Graphics.hpp>

class GameWorld {
public:
    GameWorld(sf::RenderWindow& window);
    void loadResources();
    void update(sf::Time deltaTime);
    void draw();

private:
    sf::RenderWindow& window;
    sf::Texture tileTexture;
    sf::Sprite tileSprite;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::View view;

    static const int MAP_WIDTH = 100;
    static const int MAP_HEIGHT = 100;
    sf::Sprite tileMap[MAP_WIDTH][MAP_HEIGHT];
};

#endif // GAMEWORLD_H
