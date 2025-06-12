#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Obstaculo
{
    public:
        
        sf::Sprite sprite;
        float velx, vely;

        Obstaculo(sf::Vector2f pos, float vx, float vy) : velx(vx), vely(vy)
        {
            // Cargar la imagen desde un archivo solo una vez
            if (!texture_loaded) {
                texture.loadFromFile("assets/images/zoro.png");
                texture_loaded = true;
            }
            this->sprite.setTexture(texture);
            this->sprite.setPosition(pos); // Posición inicial sprite
            this->sprite.setTextureRect(sf::IntRect(13, 422, 41, 57)); // Recorta el primer frame
        }

        sf::FloatRect getBounds() const {
            return sprite.getGlobalBounds();
        }

        void Move(float offsetX, float offsetY)
        {
            sprite.move(offsetX, offsetY);
        }

        void Update()
        {
            // Actualizar el frame de la animación
            if (clock.getElapsedTime().asSeconds() >= frameTime)
            {
                currentFrame = (currentFrame + 1) % numFrames;
                sprite.setTextureRect(sf::IntRect((currentFrame * 50)+13, 422, 41, 57));
                clock.restart();
            }
        }

        void Draw(sf::RenderWindow &window)
        {
            window.draw(this->sprite);
        }

        


    private:
        sf::Clock clock;
        float frameTime = 0.1f; // Tiempo entre cada frame en segundos
        int currentFrame = 0;
        int numFrames = 4; // Número total de frames en la animación
        int frameWidth = 50;
        int frameHeight = 57;

        // Textura compartida por todos los obstáculos
        static sf::Texture texture;
        static bool texture_loaded;
};

    // Definición de los miembros estáticos
    sf::Texture Obstaculo::texture;
    bool Obstaculo::texture_loaded = false;