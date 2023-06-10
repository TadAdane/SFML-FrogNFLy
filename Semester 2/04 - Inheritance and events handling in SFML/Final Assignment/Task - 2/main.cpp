#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CustomRectangleShape : public sf::RectangleShape {

public:
    CustomRectangleShape (sf::Vector2f size, sf::Vector2f position) : sf::RectangleShape(size), size_(size){
        setPosition(position);
    }

    void setSpeed(int horizontal_speed, int vertical_speed, int rotational_speed) {
    horizontal_speed_ = horizontal_speed;
    vertical_speed_ = vertical_speed;
    rotational_speed_ = rotational_speed;
    }

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key){
        float dt = elapsed.asSeconds();

        int horizontal_speed_r_ = horizontal_speed_;
        int horizontal_speed_l_ = horizontal_speed_;

        int vertical_speed_t_ = vertical_speed_;
        int vertical_speed_b_ = vertical_speed_;

        sf::FloatRect rectangle_bounds = getGlobalBounds();

       if(rectangle_bounds.top <= top_){
           vertical_speed_t_ = 0;
       }
       else {
           vertical_speed_t_ = vertical_speed_;
       }

       if(rectangle_bounds.top + rectangle_bounds.height >= bottom_){
           vertical_speed_b_ = 0;
       }
       else {
           vertical_speed_b_ = vertical_speed_;
       }

       if(rectangle_bounds.left <= left_ ){
           horizontal_speed_l_ = 0;
       }
       else {
           horizontal_speed_l_ = horizontal_speed_;
       }

       if(rectangle_bounds.left + rectangle_bounds.width >= right_){
           horizontal_speed_r_ = 0;
           setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
       }
       else {
           horizontal_speed_r_ = horizontal_speed_;
       }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            std::cout << "Holding up Up" << std::endl;
            move(0, vertical_speed_t_*dt*-1);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            std::cout << "Holding up Down" << std::endl;
            move(0, vertical_speed_b_*dt);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            std::cout << "Holding up Left" << std::endl;
            move(horizontal_speed_l_*dt*-1, 0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            std::cout << "Holding up Right" << std::endl;
            move(horizontal_speed_r_*dt, 0);
        }
    }

    bool isClicked(sf::Vector2i &mouse_position){

        sf::FloatRect rectangle_bounds = getGlobalBounds();
        if (mouse_position.x >= rectangle_bounds.left &&
                mouse_position.x <= rectangle_bounds.left + rectangle_bounds.width &&
                mouse_position.y >= rectangle_bounds.top &&
                mouse_position.y <= rectangle_bounds.top + rectangle_bounds.height){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//                setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
                setFillColor(sf::Color(255, 0, 0));

                std::cout << "Clicking Right" << std::endl;
                return true;
            }
            setFillColor(sf::Color(0, 255, 0));
        }
        return false;
    }

//    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key, const sf::Vector2i &mouse_position, bool selected){
//        float dt = elapsed.asSeconds();

//        int horizontal_speed_r_ = horizontal_speed_;
//        int horizontal_speed_l_ = horizontal_speed_;

//        int vertical_speed_t_ = vertical_speed_;
//        int vertical_speed_b_ = vertical_speed_;

//        sf::FloatRect rectangle_bounds = getGlobalBounds();

//        if(rectangle_bounds.top <= top_){
//            vertical_speed_t_ = 0;
//        }
//        else {
//            vertical_speed_t_ = vertical_speed_;
//        }

//        if(rectangle_bounds.top + rectangle_bounds.height >= bottom_){
//            vertical_speed_b_ = 0;
//        }
//        else {
//            vertical_speed_b_ = vertical_speed_;
//        }

//        if(rectangle_bounds.left <= left_ ){
//            horizontal_speed_l_ = 0;
//        }
//        else {
//            horizontal_speed_l_ = horizontal_speed_;
//        }

//        if(rectangle_bounds.left + rectangle_bounds.width >= right_){
//            horizontal_speed_r_ = 0;
//            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
//        }
//        else {
//            horizontal_speed_r_ = horizontal_speed_;
//        }

//        if (selected) {
//            // Move the rectangle based on the mouse position
//            setPosition(mouse_position.x, mouse_position.y);
//        } else {
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//            {
//                std::cout << "Holding up Up" << std::endl;
//                move(0, vertical_speed_t_*dt*-1);
//            }

//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//            {
//                std::cout << "Holding up Down" << std::endl;
//                move(0, vertical_speed_b_*dt);
//            }

//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//            {
//                std::cout << "Holding up Left" << std::endl;
//                move(horizontal_speed_l_*dt*-1, 0);
//            }

//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//            {
//                std::cout << "Holding up Right" << std::endl;
//                move(horizontal_speed_r_*dt, 0);
//            }
//        }
//    }


//    bool isClicked(sf::Vector2i &mouse_position){

//        sf::FloatRect rectangle_bounds = getGlobalBounds();
//        if (mouse_position.x >= rectangle_bounds.left &&
//                mouse_position.x <= rectangle_bounds.left + rectangle_bounds.width &&
//                mouse_position.y >= rectangle_bounds.top &&
//                mouse_position.y <= rectangle_bounds.top + rectangle_bounds.height){
//            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//                if (!selected_) {
//                    select();
//                } else {
//                    deselect();
//                }
//                return true;
//            }
//            setFillColor(sf::Color(0, 255, 0));
//        }
//        return false;
//    }

    void MouseButtonReleased(sf::Vector2i &mouse_position) {
        if (isClicked(mouse_position)) {
            select();
        }
        else {
            deselect();
        }
    }


    void select() {
        selected_ = true;
        setFillColor(sf::Color(255, 0, 0));
    }

    void deselect() {
        selected_ = false;
        setFillColor(sf::Color(0, 255, 0));
    }

    void setBounds(int l, int r, int t, int b){
        left_ = l;
        right_ = r;
        top_ = t;
        bottom_ = b;

    }

private:

    int horizontal_speed_ = 0.0;
    int vertical_speed_ = 0.0;
    int rotational_speed_ = 0.0;

    int left_;
    int right_;
    int top_;
    int bottom_;
    sf::Vector2f size_;
    bool selected_ = false;


};


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes

    CustomRectangleShape rectangle1(sf::Vector2f(100.0, 80.0), sf::Vector2f(120.0, 60.0));
    rectangle1.setFillColor(sf::Color(100, 150, 250));
    rectangle1.setSpeed(100, 150, 10);
    rectangle1.setBounds(0, window.getSize().x, 0, window.getSize().y);

    std::vector<CustomRectangleShape> rectangles;

    for(int i=0; i<10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }

    for(auto &rec : rectangles)
    {
        rec.setFillColor(sf::Color(0, 255, 0));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 10);
    }

    sf::Clock clock;

    bool clicked;

    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        sf::Vector2i position = sf::Mouse::getPosition(window);

        sf::FloatRect rectangle_bounds = rectangle1.getGlobalBounds();

        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window.close();

//            if(event.type == sf::Event::MouseButtonPressed) {
//                if (event.type == sf::Event::MouseMoved){
//                    for (auto &rec : rectangles) {
//                                        rec.moveInDirection(elapsed, event.key.code);
//                                    }
//                }
//                //                     if(event.mouseButton.button == sf::Mouse::Left)
//               // sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
////                for (auto &rec : rectangles) {

////                    if (rec.isClicked(position)) {
////                        rec.select();
////                    }
////                    else {
////                        rec.deselect();
////                    }
////                }
//                clicked = true;
//            }
//            if(event.type == sf::Event::MouseButtonReleased) {
//                clicked = false;
//            }
////            if(event.type == sf::Event::KeyPressed) {
////                //                                if(event.key.code == sf::Keyboard::Space)
////                for (auto &rec : rectangles) {
////                    rec.moveInDirection(elapsed, event.key.code);
////                }
////            }
////            if(clicked && event.type == sf::Event::MouseMoved) {
////                //sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
////                for (auto &rec : rectangles) {
////                    rec.moveInDirection(elapsed, event.key.code);
////                }
////            }
//        }


        sf::Event event;
                while (window.pollEvent(event)) {
                    // "close requested" event: we close the window
                    if (event.type == sf::Event::Closed)
                        window.close();

                    if(event.type == sf::Event::MouseButtonPressed) {
                        if (event.type == sf::Event::MouseMoved){
                            for (auto &rec : rectangles) {
                                rec.moveInDirection(elapsed, event.key.code);
                            }
                        }
                        if(event.mouseButton.button == sf::Mouse::Left) {
                            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                            for (auto &rec : rectangles) {
                                if (rec.isClicked(mouse_pos)) {
                                    rec.select();
                                }
                                else {
                                    rec.deselect();
                                }
                            }
                        }
                    }
                    if(event.type == sf::Event::MouseButtonReleased) {
                        clicked = false;
                    }
                    if(clicked && event.type == sf::Event::MouseMoved) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                        for (auto &rec : rectangles) {
                            rec.moveInDirection(elapsed, event.key.code);
                        }
                    }
                }





        //rectangle1.isClicked(position);

        //rectangle1.moveInDirection(elapsed, event.key.code);

        // clear the window with black color
        window.clear(sf::Color::Black);

        //rectangle1.animate(elapsed);

        window.draw(rectangle1);

        for(auto &rec : rectangles)
        {
            if (rec.isClicked(position) == 1){
                rec.moveInDirection(elapsed, event.key.code);
            }

            window.draw(rec);
        }

        // end the current frame
        window.display();
    }

    return 0;
}
