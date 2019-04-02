/* This is a simple demonstration of how to calculate
 * the frames-per-second in an SFML application.  This simple
 * concept can also be applied to other frameworks as well.
 * 
 * Tech Cogs 2019
 * @techcogs on GitHub
 */

#include <iostream>
#include <SFML/Window.hpp>

int main() {
    sf::Window window(sf::VideoMode(800, 600), "SFML FPS");
    //window.setFramerateLimit(60);
    sf::Clock clock;
    float time = 0;
    int frames = 0;
    
    while (window.isOpen()) {
        sf::Event event;
        time += clock.getElapsedTime().asSeconds();
        frames++;
        clock.restart();
        
        if (time >= 1.0f) {
            std::cout << frames << "\n";
            time = 0;
            frames = 0;
        }
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.display();
    }
    
    return 0;
}
