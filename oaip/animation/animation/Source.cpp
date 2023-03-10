#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1000, 800), "Animation");
    window.setFramerateLimit(60);

    sf::Sprite sprite;
    sf::Image image;
    sf::Texture texture;
    sf::Clock clock;

    
    int speed = 3;
    double currentposition = 0;

    
    image.loadFromFile("anim.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(500, 50);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 96));

    while (window.isOpen()) {

        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1000;



        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

            if (sprite.getGlobalBounds().top <= -100) {
                sprite.move(0, 850);
            }

            currentposition += 0.005* time;
            if (currentposition > 4) currentposition = 0;
            sprite.setTextureRect(sf::IntRect(int(currentposition) * 64, 288, 64, 96));
            sprite.move(0, -speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

            if (sprite.getGlobalBounds().top >= 850) {
                sprite.move(0, -950);
            }

            currentposition += 0.005 * time;
            if (currentposition > 4) currentposition = 0;
            sprite.setTextureRect(sf::IntRect(int(currentposition) * 64, 0, 64, 96));
            sprite.move(0, speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

            if (sprite.getGlobalBounds().left >= 1050) {
                sprite.move(-1100, 0);
            }

            currentposition += 0.005 * time;
            if (currentposition > 4) currentposition = 0;
            sprite.setTextureRect(sf::IntRect(int(currentposition) * 64, 192, 64, 96));
            sprite.move(speed, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            if (sprite.getGlobalBounds().left <= -50) {
                sprite.move(1050, 0);
            }

            currentposition+=0.005*time;
            if (currentposition > 4) currentposition = 0;
            sprite.setTextureRect(sf::IntRect(int(currentposition) * 64, 96, 64, 96));
            sprite.move(-speed, 0);
        }
        
      

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
