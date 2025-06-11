#pragma once
#include <SFML/Graphics.hpp>

class Puntaje
{
    public:
        Puntaje()
        {
            // Cargar la fuente de texto
            if (!font.loadFromFile("./assets/fonts/Pixel.ttf"))
            {
                // Manejar el error si no se puede cargar la fuente
            }
            text.setFont(font);
            text.setCharacterSize(25);
            text.setFillColor(sf::Color::White);
            text.setPosition(10, 10); // Posición del puntaje en la ventana
        }

        void Update(int score)
        {
            text.setString("Puntaje: " + std::to_string(score));
        }

        void Draw(sf::RenderWindow& window)
        {
            window.draw(text);
        };

    private:
        sf::Font font;
        sf::Text text;
        sf::Clock clock;
};
