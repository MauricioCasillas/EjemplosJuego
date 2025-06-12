#pragma once
#include <SFML/Graphics.hpp>

class GameOver
{
    public:

        int FinalScore(int finalScore)
        {
            this->score = finalScore; // Guardar el puntaje final
            scoreText.setString("Puntaje Final: " + std::to_string(score)); // <-- Actualiza el texto aquí
            return 0;
        }
        
        void Background()
        {
            if (!texture.loadFromFile("assets/images/nada.jpg"))
            {
                    // Manejar el error si no se puede cargar la fuente      
            }
            this->sprite = sf::Sprite(texture);
            this->sprite.setPosition(200, 10); // Posición inicial sprite

            if (!font.loadFromFile("./assets/fonts/Pixel.ttf")) 
            {
                // Manejar el error si no se puede cargar la fuente
            }
            gameOverText.setFont(font);
            gameOverText.setCharacterSize(80);
            gameOverText.setString("Game Over");
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(300, 270);
            scoreText.setFont(font);
            scoreText.setCharacterSize(40);
            scoreText.setPosition(200, 20);
            scoreText.setFillColor(sf::Color::White);
        }
        
        void Draw(sf::RenderWindow &window)
        {
            window.clear();
            window.draw(this->sprite);
            window.draw(gameOverText);
            window.draw(scoreText);
            window.display();
        }
        
    private:
        
        sf::Texture texture;
        sf::Sprite sprite; // Sprite para la pantalla de Game Over
        sf::Font font; // Fuente para el texto
        sf::Text gameOverText; // Texto de Game Over
        sf::Text scoreText; // Texto de Game Over
        int score=0; // Puntaje final del juego

};