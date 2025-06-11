#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Personaje
{
public:

    Personaje(sf::Vector2f position)
    {

        // Cargar la imagen desde un archivo
        if (!texture.loadFromFile("assets/images/zoro.png"))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
        this->sprite.setTextureRect(sf::IntRect(0, 60, 35, 57)); // Recorta el primer frame

    }

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

    void Musica(){
        if (!music.openFromFile("./assets/music/atack.mp3"))
        {

        }
        music.setLoop(true);
        music.play(); 
    }

    void Move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
    }

    void Draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
    }

    void Update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 35)+15, 0, 35, 57));
            clock.restart();
        }
    }

    void Quieto() {
        sprite.setTextureRect(sf::IntRect(15, 60, 35, 57)); // Recorta el primer frame quieto
    }


private:
    sf::Music music;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 6; // Número total de frames en la animación
    int frameWidth = 35;
    int frameHeight = 57;
};
