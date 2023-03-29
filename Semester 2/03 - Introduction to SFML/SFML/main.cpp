#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::CircleShape circle(50.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

//    float pos_x = 100.0;
//    sf::RectangleShape rectangle2(sf::Vector2f(80.0, 7.0));
//    for (int i = 1; i <= 2; i++){
//        rectangle2.setPosition(pos_x, 1.0);
//        rectangle2.setFillColor(sf::Color::White);
//        window.draw(rectangle2);
//        pos_x  = pos_x + 80.0;
//    }

    //Creating Spaceship

    sf::ConvexShape spaceship;
    spaceship.setPointCount(8);
    spaceship.setPoint(0, sf::Vector2f(50.0, 0.0));
    spaceship.setPoint(1, sf::Vector2f(30.0, 40.0));
    spaceship.setPoint(2, sf::Vector2f(0.0, 40.0));
    spaceship.setPoint(3, sf::Vector2f(0.0, 60.0));
    spaceship.setPoint(4, sf::Vector2f(50.0, 70.0));
    spaceship.setPoint(5, sf::Vector2f(100.0, 60.0));
    spaceship.setPoint(6, sf::Vector2f(100.0, 40.0));
    spaceship.setPoint(7, sf::Vector2f(70.0, 40.0));

    spaceship.setOutlineColor(sf::Color::Red);
   // spaceship.setOutlineThickness(2);
    spaceship.setPosition(350.0, 530.0);

    //Creating Bar
    sf::RectangleShape rectangle2(sf::Vector2f(80.0, 7.0));
    rectangle2.setPosition(1.0, 1.0);
    rectangle2.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle3(sf::Vector2f(80.0, 7.0));
    rectangle3.setPosition(100.0, 1.0);
    rectangle3.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle4(sf::Vector2f(80.0, 7.0));
    rectangle4.setPosition(200.0, 1.0);
    rectangle4.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle5(sf::Vector2f(80.0, 7.0));
    rectangle5.setPosition(300.0, 1.0);
    rectangle5.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle6(sf::Vector2f(80.0, 7.0));
    rectangle6.setPosition(400.0, 1.0);
    rectangle6.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle7(sf::Vector2f(80.0, 7.0));
    rectangle7.setPosition(500.0, 1.0);
    rectangle7.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle8(sf::Vector2f(80.0, 7.0));
    rectangle8.setPosition(600.0, 1.0);
    rectangle8.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle9(sf::Vector2f(80.0, 7.0));
    rectangle9.setPosition(700.0, 1.0);
    rectangle9.setFillColor(sf::Color::White);


    //

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(2);
    triangle.setPosition(600.0, 100.0);
    sf::Clock clock;

    //Bar velocities

    int spaceship_velocity_x = 100;

    int circle2_velocity_y = 500;

    int rectangle_velocity_x = 0;
    int rectangle_velocity_y = 50;

    int rectangle2_velocity_y = 50;
    int rectangle3_velocity_y = 50;
    int rectangle4_velocity_y = 50;
    int rectangle5_velocity_y = 50;
    int rectangle6_velocity_y = 50;
    int rectangle7_velocity_y = 50;
    int rectangle8_velocity_y = 50;
    int rectangle9_velocity_y = 50;

    int rectangle_angular_velocity = 10;

    bool flag_y = false;
    bool flag_x = false;

//    sf::FloatRect spaceship_bounds = spaceship.getGlobalBounds();

//    sf::CircleShape circle2(5.0);
//    circle2.setPosition(spaceship_bounds.left+45.0, spaceship_bounds.top - 2.5);
//    circle2.setFillColor(sf::Color(100, 250, 50));

    sf::CircleShape circle2(5.0);

    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();



        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();

       if(rectangle_bounds.top <= 0){
           rectangle_velocity_y = abs(rectangle_velocity_y);
           rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(rectangle_bounds.top + rectangle_bounds.height >= window.getSize().y){
           rectangle_velocity_y = abs(rectangle_velocity_y) * -1;
           rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(rectangle_bounds.left <= 0 ){
          rectangle_velocity_x = abs(rectangle_velocity_x);
          rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(rectangle_bounds.left + rectangle_bounds.width >= window.getSize().x){
           rectangle_velocity_x = abs(rectangle_velocity_x) * -1;
           rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       // Condition for spaceship
       sf::FloatRect spaceship_bounds = spaceship.getGlobalBounds();

       if(spaceship_bounds.left <= 0 ){
          spaceship_velocity_x = abs(spaceship_velocity_x);
          spaceship.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       if(spaceship_bounds.left + spaceship_bounds.width >= window.getSize().x){
           spaceship_velocity_x = abs(spaceship_velocity_x) * -1;
           spaceship.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }

       //space ship shooting
      // sf::CircleShape circle2(5.0);
       circle2.setPosition(350.0, 530.0);
       circle2.setFillColor(sf::Color(100, 250, 50));
//        for (int i = 1; i < 1000; i++){
       circle2.move(0, 1000*circle2_velocity_y*dt * -1);
//        }
       sf::FloatRect circle2_bounds = circle2.getGlobalBounds();
       if(circle2_bounds.top <= 0){
            circle2.setPosition(spaceship_bounds.left+45.0, spaceship_bounds.top - 2.5);
            rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }



       //Bar Conditions

       sf::FloatRect rectangle2_bounds = rectangle2.getGlobalBounds();

       if(rectangle2_bounds.top + rectangle2_bounds.height + 90 >= window.getSize().y){
           rectangle2.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle2.setPosition(0.0, 0.0);
       }

       sf::FloatRect rectangle3_bounds = rectangle3.getGlobalBounds();

       if(rectangle3_bounds.top + rectangle3_bounds.height + 90 >= window.getSize().y){
           rectangle3.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle3.setPosition(100.0, 0.0);
       }

       sf::FloatRect rectangle4_bounds = rectangle4.getGlobalBounds();

       if(rectangle4_bounds.top + rectangle4_bounds.height + 90 >= window.getSize().y){
           rectangle4.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle4.setPosition(200.0, 0.0);
       }

       sf::FloatRect rectangle5_bounds = rectangle5.getGlobalBounds();

       if(rectangle5_bounds.top + rectangle5_bounds.height + 90 >= window.getSize().y){
           rectangle5.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle5.setPosition(300.0, 0.0);
       }

       sf::FloatRect rectangle6_bounds = rectangle6.getGlobalBounds();

       if(rectangle6_bounds.top + rectangle6_bounds.height + 90 >= window.getSize().y){
           rectangle6.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle6.setPosition(400.0, 0.0);
       }

       sf::FloatRect rectangle7_bounds = rectangle7.getGlobalBounds();

       if(rectangle7_bounds.top + rectangle7_bounds.height + 90 >= window.getSize().y){
           rectangle7.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle7.setPosition(500.0, 0.0);
       }

       sf::FloatRect rectangle8_bounds = rectangle8.getGlobalBounds();

       if(rectangle8_bounds.top + rectangle8_bounds.height + 90 >= window.getSize().y){
           rectangle8.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle8.setPosition(600.0, 0.0);
       }

       sf::FloatRect rectangle9_bounds = rectangle9.getGlobalBounds();

       if(rectangle9_bounds.top + rectangle2_bounds.height + 90 >= window.getSize().y){
           rectangle9.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
           rectangle9.setPosition(700.0, 0.0);
       }

       //


        //rectangle.move(rectangle_velocity_x*dt,rectangle_velocity_y*dt);

       // Spaceship Movement

       spaceship.move(spaceship_velocity_x*dt,0);



       //Bar Movement

       rectangle2.move(0,rectangle2_velocity_y*dt);
       rectangle3.move(0,rectangle3_velocity_y*dt*2);
       rectangle4.move(0,rectangle4_velocity_y*dt*3);
       rectangle5.move(0,rectangle5_velocity_y*dt*1.2);
       rectangle6.move(0,rectangle6_velocity_y*dt*1.7);
       rectangle7.move(0,rectangle7_velocity_y*dt*2.3);
       rectangle8.move(0,rectangle8_velocity_y*dt*1.45);
       rectangle9.move(0,rectangle9_velocity_y*dt*1.15);

        //rectangle.rotate(rectangle_angular_velocity*dt);

       //

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
        window.draw(circle);
        window.draw(circle2);
        //window.draw(rectangle2);

        window.draw(rectangle);
        window.draw(triangle);
        window.draw(spaceship);

        // Draw Bar;

        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(rectangle5);
        window.draw(rectangle6);
        window.draw(rectangle7);
        window.draw(rectangle8);
        window.draw(rectangle9);

        //



        // end the current frame
        window.display();

    }

    return 0;
}
