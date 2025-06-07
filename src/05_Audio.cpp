#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(713, 560), "Reproductor de musica");

    sf::Music music;
    if (!music.openFromFile("./assets/music/zoro.mp3"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/zorojaja.jpg"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    // Reproducir la música
    music.play();

    //Bucle principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        
        // Dibujar el sprite en la ventana
        window.draw(sprite);

        // Dibujar elementos adicionales en la ventana si es necesario
        window.display();

        // Esperar hasta que la música termine
        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}