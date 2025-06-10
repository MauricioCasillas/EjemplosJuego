#pragma once
#include <SFML/Graphics.hpp>

class Obstaculo
{
public:
    Obstaculo(sf::Vector2f position)
    {
        // Cargar la imagen desde un archivo
        if (!texture.loadFromFile("assets/images/zoro.png"))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
        this->sprite.setTextureRect(sf::IntRect(13, 422, 41, 57)); // Recorta el primer frame
    }

    void update()
    {
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 50)+13, 422, 41, 57));
            clock.restart();
        }
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
    }

    

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 50;
    int frameHeight = 57;
};