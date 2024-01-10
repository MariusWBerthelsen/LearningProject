#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include "LoginHandler.h"
#include "GameWorld.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    ImGui::SFML::Init(window);

    LoginHandler loginHandler;
    bool showLoginWindow = true;
    GameWorld* gameWorld = nullptr;

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Start a new ImGui frame
        ImGui::SFML::Update(window, deltaClock.restart());

        if (showLoginWindow) {
            loginHandler.loginWindow();
            if (loginHandler.isLoggedIn()) {
                showLoginWindow = false;
                gameWorld = new GameWorld(window);
            }
        }

        window.clear();

        if (!showLoginWindow && gameWorld) {
            sf::Time deltaTime = deltaClock.restart();
            gameWorld->update(deltaTime);
            gameWorld->draw();
        }

        // Render ImGui frame
        if (showLoginWindow) {
            ImGui::Render();
            ImGui::SFML::Render(window);
        }

        window.display();
    }

    ImGui::SFML::Shutdown();
    delete gameWorld; // Clean up
    return 0;
}
