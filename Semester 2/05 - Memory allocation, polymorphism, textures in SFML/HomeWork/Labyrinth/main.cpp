#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void moveInDirection(sf::Time &elapsed, const sf::Keyboard::Key &key, sf::Sprite &guy, sf::RenderWindow &window, std::vector<sf::Sprite> &walls)
{
    int speed_x = 7;
    int speed_y = 7;
    int right = window.getSize().x;
    int bottom = window.getSize().y;

    for(auto &wall : walls)
    {
        sf::FloatRect guybounds = guy.getGlobalBounds();
        sf::FloatRect wallbounds = wall.getGlobalBounds();
        if(guy.getGlobalBounds().intersects(wallbounds))
        {
            if(guybounds.top > wallbounds.top + wallbounds.height - 5
                && guybounds.left + guybounds.width > wallbounds.left
                    && guybounds.left < wallbounds.left + wallbounds.width)
            {
                guy.setPosition(guy.getPosition().x, wallbounds.top + wallbounds.height);
                break;
            }
            else if(guybounds.top < wallbounds.top - guybounds.height + 5
                    && guybounds.left > wallbounds.left - guybounds.width
                    && guybounds.left < wallbounds.left + wallbounds.width)

            {
                guy.setPosition(guy.getPosition().x, wallbounds.top - guybounds.height);
                break;
            }
            else if(guybounds.left < wallbounds.left - guybounds.width + 5
                    && guybounds.top > wallbounds.top - guybounds.height
                    && guybounds.top < wallbounds.top + wallbounds.height)
            {
                if(guybounds.left + guybounds.width - wallbounds.left > 4)
                    std::cout << guybounds.left + guybounds.width - wallbounds.left << "----";
                guy.setPosition(wallbounds.left - guybounds.width, guy.getPosition().y);
                break;
            }
            else if(guybounds.left > wallbounds.left + wallbounds.width - 5
                    && guybounds.top > wallbounds.top - guybounds.height
                    && guybounds.top < wallbounds.top + wallbounds.height)
            {
                guy.setPosition(wallbounds.left + wallbounds.width, guy.getPosition().y);
                break;
            }
        }
        else
        {
            if(key == sf::Keyboard::Up && !(guybounds.top <= 0.0))
            {
                guy.move(0, -speed_y * elapsed.asSeconds());
            }
            else if(key == sf::Keyboard::Right && !(guybounds.left >= right - guybounds.width))
            {
                guy.move(speed_x * elapsed.asSeconds(), 0);
            }
            else if(key == sf::Keyboard::Down && !(guybounds.top >= bottom - guybounds.height) && !(guybounds.top >= bottom - guybounds.height))
            {
                guy.move(0, speed_y * elapsed.asSeconds());
            }
            else if(key == sf::Keyboard::Left && !(guybounds.left <= 0.0))
            {
                guy.move(-speed_x * elapsed.asSeconds(), 0);
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    sf::Texture texture_grass;
    if (!texture_grass.loadFromFile("grass.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Texture texture_wall;
    if(!texture_wall.loadFromFile("wall.png")) return 1;

    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("guy.png")) return 1;


    texture_grass.setRepeated(true);
    sf::Sprite grass;
    grass.setTexture(texture_grass);
    grass.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));


    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);

    std::vector<sf::Sprite> walls;

    //Borders

    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125));
    wall.setPosition(0.0, 125.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, 0.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125));
    wall.setPosition(window.getSize().x - 50, 125);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, window.getSize().y - 50);
    walls.emplace_back(wall);

    // Vertical Walls

    wall.setTextureRect(sf::IntRect(0, 0, 25, 125));
    wall.setPosition(125.0, 350.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 125));
    wall.setPosition(125.0, 550.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(225.0, 50.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(225.0, 550.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(325.0, 150.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(325.0, 450.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(425.0, 50.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 200));
    wall.setPosition(425.0, 350.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(650.0, 50.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(525.0, 250.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(525.0, 550.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 125));
    wall.setPosition(525.0, 125.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(525.0, 250.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(525.0, 550.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(625.0, 350.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(625.0, 650.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 25, 100));
    wall.setPosition(130.0, 175.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(550.0, 125.0);
    walls.emplace_back(wall);

    // Horizontal Walls
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(150.0, 250.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(650.0, 250.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 500, 25));
    wall.setPosition(150.0, 350.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(250.0, 450.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(550.0, 450.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 100, 25));
    wall.setPosition(150.0, 550.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 200, 25));
    wall.setPosition(550.0, 550.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, 200, 25));
    wall.setPosition(350.0, 637.0);
    walls.emplace_back(wall);


    sf::Sprite guy;
    guy.setTexture(texture_guy);
    guy.setPosition(0.0, 50.0);


    sf::Texture win_texture;
    if(!win_texture.loadFromFile("win.jpg")) std::cerr << "Could not load you win texture" << std::endl;
    sf::Sprite win_background;
    //win_background.setTexture(win_texture);
    win_background.setPosition(0, 0);

   // win_texture.setRepeated(true);
    win_background.setTexture(win_texture);
    win_background.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));


    bool win = false;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            moveInDirection(elapsed, sf::Keyboard::Up, guy, window, walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            moveInDirection(elapsed, sf::Keyboard::Down, guy, window, walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            moveInDirection(elapsed, sf::Keyboard::Left, guy, window, walls);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            moveInDirection(elapsed, sf::Keyboard::Right, guy, window, walls);
        }
        if(guy.getGlobalBounds().left > window.getSize().x - 50)
        {
            win = true;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            return 0;
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.draw(grass);

        for(auto &wall : walls)
        {
            window.draw(wall);
        }
        window.draw(guy);
        if(win == true)
        {
            window.draw(win_background);
        }
        window.display();
    }

    return 0;
}
