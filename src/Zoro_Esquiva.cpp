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
        this->sprite.setTextureRect(sf::IntRect(500, 200, 1398, 808)); // Recorta

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
        text.setCharacterSize(100);
        text2.setPosition(699, 200);
        text.setFillColor(sf::Color::Black);

        // Crear un objeto de texto LOTR
        text2.setFont(font2);
        text2.setString("Presiona Enter para comenzar");
        text2.setCharacterSize(80);
        text2.setPosition(100, 700);
        text2.setFillColor(sf::Color::Black);

    }

     void draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
        window.draw(this->sprite);
        window.draw(this->text);   // Dibuja el texto "ONE PIECE"
        window.draw(this->text2); // Dibuja el texto "Presiona Enter para comenzar =D"
    }

    void musica(){
        if (!music.openFromFile("./assets/music/Intro.mp3"))
        {

        }
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
        this->sprite.setTextureRect(sf::IntRect(15, 60, 35, 57)); // Recorta el primer frame

    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
    }

    void update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 35)+15, 0, 35, 57));
            clock.restart();
        }
    }

    void quieto() {
        sprite.setTextureRect(sf::IntRect(15, 60, 35, 57)); // Recorta el primer frame quieto
    }


private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 6; // Número total de frames en la animación
    int frameWidth = 35;
    int frameHeight = 57;
};

int PantallaInicio(sf::RenderWindow& window)
{
    bool enPantallaInicio = true;
    Pantalla inicio;
    inicio.musica();

    while (enPantallaInicio && window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return false; // Si se cierra la ventana, termina el programa
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            {
                enPantallaInicio = false;
                return true; // Si se presiona Enter, continúa el juego
            }
        }
        window.clear();
        inicio.draw(window);
        window.display();
    }
    return false;
}

double velocidad = 0.08; // Velocidad de movimiento del personaje

int main()
{
    // Crear la ventana principal del juego
    sf::RenderWindow window(sf::VideoMode(1398, 808), "Zoro Esquiva");

    // Mostrar pantalla de inicio y salir si el usuario cierra la ventana
    if (!PantallaInicio(window)) {
        return 0;
    }

    Personaje zoro(sf::Vector2f(500, 300));

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

        bool move = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            zoro.move(velocidad * -1, 0);
            zoro.update();
            move = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            zoro.move(velocidad, 0);
            zoro.update();
            move = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            zoro.move(0, velocidad * -1);
            zoro.update();
            move = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            zoro.move(0, velocidad);
            zoro.update();
            move = true;
        }  

        if (!move)
        {
            zoro.quieto();
        }

        window.clear();
        zoro.draw(window);
        window.display();
    }

    return 0;
}