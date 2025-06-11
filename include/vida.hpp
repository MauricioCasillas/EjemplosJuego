#include <SFML/Graphics.hpp>

class  Vida
{
    public:
        Vida()
        {
            // Cargar la fuente de texto
            if (!font.loadFromFile("./assets/fonts/Pixel.ttf"))
            {                // Manejar el error si no se puede cargar la fuente
            
            }
                text.setFont(font);
                text.setCharacterSize(25);
                text.setFillColor(sf::Color::White);
                text.setPosition(10, 40); // Posición del puntaje en la ventana
         }

        void Update(int life)
        {
                text.setString("Vida: " + std::to_string(life));
        }

        void Draw(sf::RenderWindow& window)
        {
            window.draw(text);
        }

    private:
        sf::Font font;
        sf::Text text;
    
};