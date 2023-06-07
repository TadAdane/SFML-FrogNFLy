#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int barHeight = 20;
    const int ballRadius = 10;
    float groundSpeed = 2.0f;
    float holeSpeed = 2.0f;
    const float maxHoleSpeed = 8.0f;
    const float speedIncrease = 1.2f;
    const int numBlastFrames = 7;
    const int blastFrameDuration = 5;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Ball Game");
    window.setFramerateLimit(60);

    // Background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Background.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // Ground
    sf::Texture groundTexture;
    if (!groundTexture.loadFromFile("ground.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite ground(groundTexture);
//    ground.setFillColor(sf::Color::White);
    ground.setPosition(0, windowHeight - barHeight);

    // Hole bar
    float holeWidth = 80.0f;
    sf::RectangleShape holeBar(sf::Vector2f(holeWidth, barHeight));
    holeBar.setFillColor(sf::Color::Black);
    holeBar.setOutlineColor(sf::Color::White);
    holeBar.setOutlineThickness(1.0f);
    holeBar.setPosition((windowWidth - holeWidth) / 2, windowHeight - barHeight);

    // Ball sprite
    sf::Texture ballTexture;
    if (!ballTexture.loadFromFile("ball.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite ballSprite(ballTexture);
    ballSprite.setOrigin(ballRadius, ballRadius);
    ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius + 150, 10);

    // Blast sprite
       sf::Texture blastTexture;
       if (!blastTexture.loadFromFile("blast.png"))
       {
           return EXIT_FAILURE;
       }

    sf::Sprite blastSprite(blastTexture);
    int blastFrame = 0;
    int blastFrameCounter = 0;
    bool blasting = false;
    blastSprite.setTextureRect(sf::IntRect(0, 0, blastTexture.getSize().x / numBlastFrames, blastTexture.getSize().y));
    blastSprite.setOrigin(blastSprite.getTextureRect().width / 2, blastSprite.getTextureRect().height / 2);
    blastSprite.setPosition(windowWidth / 2, windowHeight / 2);


    bool ballReleased = false;
    bool passedHole = false;
    int score = 0;
    int lives = 3;
    float holeMinX = (windowWidth - holeWidth) / 2;
    float holeMaxX = holeMinX + holeWidth;

    sf::Vector2f blastPosition;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    // Lives text
    sf::Text livesText;
    livesText.setFont(font);
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(windowWidth - 100, 10);

    // Game Over text
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Red);
    //gameOverText.setString("Game Over!");
    gameOverText.setPosition((windowWidth - gameOverText.getLocalBounds().width) / 2, windowHeight / 2);

    bool gameEnded = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    ballReleased = true;
                }
            }
        }

        if (!gameEnded) {
                    if (ballReleased) {
                        if (ballSprite.getPosition().y + 25 >= windowHeight) {
                            if (!passedHole) {
                                lives--;

                                blastPosition = ballSprite.getPosition();

                                blasting = true;
                                blastFrame = 0;
                                blastFrameCounter = 0;
                            }
                            ballReleased = false;
                            passedHole = false;
                            ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius, 10);
                        }
                        else {
                            ballSprite.move(0, 5);
                            if (!passedHole && ballSprite.getGlobalBounds().intersects(holeBar.getGlobalBounds())) {
                                passedHole = true;
                                holeSpeed *= speedIncrease; //Increase speed as score increases.
                                score++;
                            }
                        }
                    }
//                    else {
//                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && holeBar.getPosition().x + holeWidth < windowWidth) {
//                            //ground.move(groundSpeed, 0);
//                            holeBar.move(groundSpeed, 0);
////                            blasting = true;
//                        }
//                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && holeBar.getPosition().x > 0) {
//                            //ground.move(-groundSpeed, 0);
//                            holeBar.move(-groundSpeed, 0);
//                        }
//                    }

                    // Move the hole bar automatically
                    if (!ballReleased) {
                        holeBar.move(holeSpeed, 0);

                        // Check for collision with window edges and change direction
                        if (holeBar.getPosition().x <= 0) {
                            holeBar.setPosition(0, windowHeight - barHeight);
                            holeSpeed = -holeSpeed;
                        }
                        else if (holeBar.getPosition().x + holeWidth >= windowWidth) {
                            holeBar.setPosition(windowWidth - holeWidth, windowHeight - barHeight);
                            holeSpeed = -holeSpeed;
                        }
                    }

                    window.clear();

                    // Draw background
                    window.draw(backgroundSprite);

                    // Draw ground
                    window.draw(ground);

                    // Draw hole bar
                    window.draw(holeBar);

                    // Draw ball sprite
                    window.draw(ballSprite);

                    if (blasting){
                        blastFrameCounter++;
                        if (blastFrameCounter >= blastFrameDuration){
                            blastFrame++;
                            blastFrameCounter = 0;
                            if (blastFrame >= numBlastFrames){
                                blasting = false;
                                blastFrame = 0;
                                }
                        }
                        blastSprite.setTextureRect(sf::IntRect(blastFrame * blastSprite.getTextureRect().width, 0, blastSprite.getTextureRect().width, blastSprite.getTextureRect().height));
                        blastSprite.setPosition(blastPosition);
                        window.draw(blastSprite);
                    }

                    scoreText.setString("Score: " + std::to_string(score));
                    window.draw(scoreText);

                    livesText.setString("Lives: " + std::to_string(lives));
                    window.draw(livesText);


                    if (lives <= 0) {
                        gameEnded = true;
                        gameOverText.setPosition((windowWidth - gameOverText.getLocalBounds().width) / 2, (windowHeight - gameOverText.getLocalBounds().height) / 2);
                        gameOverText.setString("Game Over! \nYour Score is: " + std::to_string(score));
                        window.draw(gameOverText);
                    }
                    window.display();
                }
            }

            return 0;
        }
