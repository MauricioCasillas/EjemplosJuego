#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Pantalla
{
public:
    Pantalla()
    {
        // Cargar la imagen desde un archivo
        if (!texture.loadFromFile("assets/images/intro.png"))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setTextureRect(sf::IntRect(0, 0, 1080, 540)); // Recorta 

        if (!font.loadFromFile("./assets/fonts/OP.ttf"))
        {
            
        }

        // Cargar una fuente de texto
        if (!font2.loadFromFile("./assets/fonts/Ring.ttf"))
        {


        }
         // Crear un objeto de texto
        text.setFont(font);
        text.setString("ONE PIECE");
        text.setCharacterSize(90);
        text.setPosition(100, 50);
        text.setFillColor(sf::Color::Black);

        // Crear un objeto de texto LOTR
        text2.setFont(font2);
        text2.setString("Presiona Enter para comenzar");
        text2.setCharacterSize(30);
        text2.setPosition(70, 200);
        text2.setFillColor(sf::Color::Black);

    }

     void Draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
        window.draw(this->sprite);
        window.draw(this->text);   // Dibuja el texto "ONE PIECE"
        window.draw(this->text2); // Dibuja el texto "Presiona Enter para comenzar =D"
    }

    void Musica(){
        if (!music.openFromFile("./assets/music/Intro.mp3"))
        {

        }
        music.play(); // Reproducir en bucle
    }
    void Musica2(){
        music.openFromFile("./assets/music/start.mp3");
        music.play(); // Reproducir en bucle
    }

private:
    sf::Text text;
    sf::Text text2;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Music music;
    sf::Font font;
    sf::Font font2;
};