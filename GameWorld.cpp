#include "GameWorld.h"

GameWorld::GameWorld(sf::RenderWindow& window) : window(window) {
    loadResources();
    view.setSize(800, 600);
    view.setCenter(playerSprite.getPosition());
    window.setView(view);
}

void GameWorld::loadResources() {
    if (!tileTexture.loadFromFile("assets/grass.png")) {
        // Handle error
    }
    tileSprite.setTexture(tileTexture);

    if (!playerTexture.loadFromFile("assets/tree.png")) {
        // Handle error
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(400, 300); // Center of the window

    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            tileMap[x][y] = tileSprite;
            tileMap[x][y].setPosition(x * 64, y * 64);
        }
    }
}

void GameWorld::update(sf::Time deltaTime) {
    // Update player position and view center here
    // Example: playerSprite.move(velocity * deltaTime.asSeconds());
    view.setCenter(playerSprite.getPosition());
    window.setView(view);
}

void GameWorld::draw() {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            window.draw(tileMap[x][y]);
        }
    }
    window.draw(playerSprite);
}
