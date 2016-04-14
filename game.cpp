#include "grid.h"
#include <SFML/Graphics.hpp>

struct game
{
    int width, height;
    bool paused;

    grid* g;
    sf::RenderWindow* window;

    game(int w, int h) : width(w), height(h), paused(true)
    {
        g = new grid(width / 8, height / 8);
        window = new sf::RenderWindow(sf::VideoMode(width, height), "Conway's Game of Life");
    }

    void start()
    {
        while (window->isOpen()) {
            sf::Event event;
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space) paused = !paused;
                    if (event.key.code == sf::Keyboard::Escape) window->close();
                }
                if (paused && event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        int x = event.mouseButton.x;
                        int y = event.mouseButton.y;
                        g->cells[x / (width / g->width)][y / (height / g->height)].flip_state();
                    }
                }
            }
            
            window->clear();
            draw();
            window->display();
            if (!paused) g->update();
        }
    }

    void draw()
    {
        for (int i = 0; i < g->width; ++i){
            for (int j = 0; j < g->height; ++j) {
                sf::RectangleShape square(sf::Vector2f(width / g->width, height / g->height));
                square.setPosition(8 * i, 8 * j);
                square.setOutlineThickness(1);
                square.setOutlineColor(sf::Color(49, 79, 79));
                if (g->cells[i][j].is_alive())
                    square.setFillColor(sf::Color(0, 0, 0));
                else
                    square.setFillColor(sf::Color(255, 255, 255));
                window->draw(square);
            }
        }
    }
};


int main()
{
    game g(1280, 1024);
    g.start();

    return 0;
}
