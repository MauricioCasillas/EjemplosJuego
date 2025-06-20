#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Obstaculo.hpp>
#include <Pantalla.hpp>
#include <Personaje.hpp>
#include <Puntaje.hpp>
#include <vector>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()
#include <Vida.hpp>
#include<GameOverScreen.hpp>

class ZoroAventuras
{
    public:
        
        void Jugar()
        {
            // Crear la ventana principal del juego
            sf::RenderWindow window(sf::VideoMode(1080, 540), "Las flipantes aventuras de Zoro el cazador de piratas");
            window.setFramerateLimit(60);
            
            while (window.isOpen())         
            {
            sf::Texture texture;
            if (!texture.loadFromFile("./assets/images/fondo.png"))
            {
                // Manejar el error si no se puede cargar la imagen
            }
            sf::Sprite sprite(texture);
            sprite.setTextureRect(sf::IntRect(350, 306, 1080, 540)); // Recorta

                // Mostrar pantalla de inicio y salir si el usuario cierra la ventana
                if (!PantallaInicio(window)) {
                }
                
                Pantalla inicio;
                inicio.Musica2(); // Reproducir música de inicio

                std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializar aleatoriedad

                int posx = 500;
                int posy = 0;
                int velx = 2; // Velocidad en x
                int vely = 4; // Velocidad en y

                std::vector<Obstaculo> obstaculos;
                
                Vida vida; // Crear un objeto de vida
                int vidaActual = 100; // Vida inicial del personaje
                vida.Update(vidaActual); // Actualizar la vida inicial

                Personaje zoro(sf::Vector2f(417, 271)); // Posición inicial del personaje Zoro
                zoro.Musica(); // Reproducir música de ataque

                int score1 = 0;
                Puntaje puntaje; // Crear un objeto de puntaje

                while (window.isOpen())
                {
                    bool move = false;
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                        {
                            window.close();
                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        zoro.Move(velocidad * -1, 0);
                        zoro.Update();
                        move = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        zoro.Move(velocidad, 0);
                        zoro.Update();
                        move = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        zoro.Move(0, velocidad * -1);
                        zoro.Update();
                        move = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        zoro.Move(0, velocidad);
                        zoro.Update();
                        move = true;
                    }  

                    if (!move)
                    {
                        zoro.Quieto();
                    }

                    // Borrar obstáculo si colisiona con Zoro
                    for (auto it = obstaculos.begin(); it != obstaculos.end(); )
                    {
                        if (zoro.getBounds().intersects(it->getBounds())) {
                            vidaActual -= 20; // Restar vida al colisionar
                            it = obstaculos.erase(it); // Borrar obstáculo y avanzar iterador
                        } else {
                            ++it;
                        }
                        if (!music.openFromFile("./assets/music/golpe.mp3"))
                        {

                        }
                        music.play(); 
                    }
                
                    // Actualizar el puntaje
                    if (scoreClock.getElapsedTime().asSeconds() >= 1.0f) {
                        score1 += 100; // Incrementar el puntaje cada segundo
                        scoreClock.restart();
                    }

                    // Generar nuevos obstáculos cada 4 segundos
                    // Verificar si ha pasado el tiempo para generar un nuevo obstáculo
                    if (obstaClock.getElapsedTime().asSeconds() >= 2.0f) {
                        // Generar posición aleatoria dentro de la ventana
                        int randX = std::rand() % (window.getSize().x - 50); // 50: ancho estimado del obstáculo
                        int randY = std::rand() % (window.getSize().y - 50); // 50: alto estimado del obstáculo
                        obstaculos.emplace_back(sf::Vector2f(randX, randY), velx, vely);
                        obstaClock.restart();
                    }

                    posx += velx; // Incrementar la posición x del obstaculo
                    posy += vely; // Incrementar la posición y del obstaculo

                    window.clear();
                    window.draw(sprite);


                    for (auto& obstaculo : obstaculos) {
                        obstaculo.Update();
                        sf::FloatRect bounds = obstaculo.getBounds();

                        // Rebote horizontal
                        if (bounds.left <= 0 || bounds.left + bounds.width >= window.getSize().x) {
                            obstaculo.velx = -obstaculo.velx;
                        }
                        // Rebote vertical
                        if (bounds.top <= 0 || bounds.top + bounds.height >= window.getSize().y) {
                            obstaculo.vely = -obstaculo.vely;
                        }

                        obstaculo.Move(obstaculo.velx, obstaculo.vely);
                        obstaculo.Draw(window);
                    }

                    if (vidaActual <= 0) {
                        // Si la vida llega a 0, termina el juego
                        window.clear();
                        
                        GameOver gameOver;
                        gameOver.FinalScore(score1); // Guardar el puntaje final
                        gameOver.Background(); // Configurar el fondo y el texto de Game Over
                        gameOver.Draw(window); // Dibujar la pantalla de Game Over
                        
                        sf::sleep(sf::seconds(3)); // Esperar 3 segundos antes de regresar al menú principal
                        break; // Salir del bucle principal para terminar el juego
                    }
                    puntaje.Update(score1); // Actualizar el puntaje
                    vida.Update(vidaActual); // Actualizar la vida del personaje
                    vida.Draw(window); // Dibujar la vida del personaje
                    zoro.Draw(window);
                    puntaje.Draw(window); // Dibujar el puntaje
                    window.display();
                }
            }
        }

        private:

            sf::Texture texture;
            sf::Event event;
            sf::Clock scoreClock; // Reloj para el puntaje
            sf::Clock obstaClock; // Reloj para los obstáculos
            sf::Music music; // Crear un objeto de música

            int PantallaInicio(sf::RenderWindow& window)
            {
                bool enPantallaInicio = true; // Variable para controlar si estamos en la pantalla de inicio
                Pantalla inicio;
                inicio.Musica();

                while (enPantallaInicio && window.isOpen())
                {
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
                    inicio.Draw(window);
                    window.display();
                }
                return false;
            }
            double velocidad = 6; // Velocidad de movimiento del personaje
};
