#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <iostream>

void create_shapes(std::vector<std::unique_ptr<sf::Drawable>> &shapes_vec){

    auto circle = std::make_unique<sf::CircleShape>(100);

//    sf::CircleShape circle(100.0);

    circle->setPosition(100.0, 300.0);
    circle->setFillColor(sf::Color(100, 250, 50));
    shapes_vec.emplace_back(std::move(circle));

    auto rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));



    rectangle->setPosition(100.0, 300.0);
    rectangle->setFillColor(sf::Color(100, 250, 50));
    shapes_vec.emplace_back(std::move(rectangle));

//    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
//    rectangle.setPosition(500.0, 400.0);
//    rectangle.setFillColor(sf::Color(100, 50, 250));

    auto triangle = std::make_unique<sf::ConvexShape>();


        triangle->setPointCount(3);
        triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
        triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
        triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
        triangle->setOutlineColor(sf::Color::Red);
        triangle->setOutlineThickness(5);
        triangle->setPosition(600.0, 100.0);

        shapes_vec.emplace_back(std::move(triangle));


//    sf::ConvexShape triangle;
//    triangle.setPointCount(3);
//    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
//    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
//    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
//    triangle.setOutlineColor(sf::Color::Red);
//    triangle.setOutlineThickness(5);
//    triangle.setPosition(600.0, 100.0);

}

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    std::vector<std::unique_ptr<sf::Drawable>> shapes;

   create_shapes(shapes);

   sf::Texture texture;
   if (!texture.loadFromFile("grass.png")) {
       std::cerr << "Could not load texture" << std::endl;
       return 1;
   }

   sf::Sprite sprite;
   sprite.setTexture(texture);

   sf::Texture texture_guy;
   if(!texture_guy.loadFromFile("guy.png")) { return 1; }

   sf::Sprite guy;
   guy.setTexture(texture_guy);
   guy.setTextureRect(sf::IntRect(10, 20, 20, 15)); //left, top, width, height

   sf::Texture texture_wall;
   if(!texture_wall.loadFromFile("wall.png")) { return 1; }
   texture_wall.setRepeated(true);

   sf::Sprite wall;
   wall.setTexture(texture_wall);
   wall.setScale(0.3, 0.3);
   wall.setTextureRect(sf::IntRect(0, 0, 500, 500));
   wall.setTextureRect(sf::IntRect(10, 20, 20, 15));

    // create some shapes

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
//        window.draw(circle);
//        window.draw(rectangle);
//        window.draw(triangle);

        for (auto &s : shapes){
            window.draw(*s);
        }
        window.draw(sprite);
        window.draw(guy);
        window.draw(wall);

        // end the current frame
        window.display();
    }

    return 0;
}
