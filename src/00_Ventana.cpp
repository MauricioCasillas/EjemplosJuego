#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana de SFML
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    // Primer cuadrado
    sf::CircleShape square1(100.f);
    square1.setPointCount(4);
    square1.setFillColor(sf::Color::Red);
    square1.setPosition(0.f, 0.f); 

    // Segundo cuadrado
    sf::CircleShape square2(100.f);
    square2.setPointCount(4);
    square2.setFillColor(sf::Color::Blue);
    square2.setPosition(200.f, 0.f);
    
    // Tercer cuadrado
    sf::CircleShape square3(100.f);
    square3.setPointCount(4);
    square3.setFillColor(sf::Color::Blue);
    square3.setPosition(0.f, 200.f); 

    // Cuarto cuadrado
    sf::CircleShape square4(100.f);
    square4.setPointCount(4);
    square4.setFillColor(sf::Color::Red);
    square4.setPosition(200.f, 200.f);

    // Circulo
    sf::CircleShape square5(100.f);
    square5.setPointCount(4);
    square5.setFillColor(sf::Color::Green);
    square5.setPosition(100.f, 100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Verificar si se ha cerrado la ventana
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar la forma en la ventana
        window.draw(square1);
        window.draw(square2);
        window.draw(square3);
        window.draw(square4);
        window.draw(square5);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}