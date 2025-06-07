#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Window");
    window.setFramerateLimit(60);

    int posx = 500;
    int posy = 0;
    int velx = 5; // Velocidad en x
    int vely = 3; // Velocidad en y

    // Cargar la imagen desde un archivo
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/dvd.jpeg"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }

    sf::Sprite sprite(texture);

    sf::Color fondo = sf::Color::White; // Color inicial del fondo

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(fondo); // Limpiar la ventana con un color de fondo

        window.draw(sprite);
        sprite.setPosition(posx, posy); // Establecer la posición del sprite

        window.display();

        bool reboteX = false;
        bool reboteY = false;

        posx += velx; // Incrementar la posición x del dvd
        posy += vely; // Incrementar la posición y del dvd

        // Rebote en los bordes
        if (posx < 0 || posx + sprite.getGlobalBounds().width > 1000)
        {
            velx = -velx;
            reboteX = true;
        }
        if (posy < 0 || posy + sprite.getGlobalBounds().height > 600)
        {
            vely = -vely;
            window.clear(sf::Color::White); // Limpiar la ventana con un color de fondo
            reboteY = true;
        }
        
        if (reboteX || reboteY)
        {
            // Cambia el color a uno aleatorio
            fondo = sf::Color(rand() % 256, rand() % 256, rand() % 256);
        }
        
    }

    return 0;
}
