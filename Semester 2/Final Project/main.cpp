#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <ctime>


int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int barHeight = 74;
    const int ballRadius = 10;
    float groundSpeed = 2.0f;
    float holeSpeed = 2.0f;
    const float maxHoleSpeed = 8.0f;
    const float speedIncrease = 1.2f;
    const int numBlastFrames = 7;
    const int blastFrameDuration = 5;
    const int barHeight = 20;
    const int ballRadius = 10;
    const float groundSpeed = 2.0f;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Ball Game");
    window.setFramerateLimit(60);

    // Background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Background_.jpg")) {
    if (!backgroundTexture.loadFromFile("Background.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // How to Play image
    sf::Texture howToPlayTexture;
    if (!howToPlayTexture.loadFromFile("howToPlay.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite howToPlaySprite(howToPlayTexture);
    howToPlaySprite.setPosition(150, 75);


    // Game over image
    sf::Texture gameoverTexture;
    if (!gameoverTexture.loadFromFile("gameover.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite gameoverSprite(gameoverTexture);


    // Ground
    sf::Texture groundTexture;
    if (!groundTexture.loadFromFile("swampWater.jpg")) {
        return EXIT_FAILURE;
    }

    sf::Sprite ground(groundTexture);
//    ground.setFillColor(sf::Color::White);
    ground.setPosition(0, windowHeight - barHeight + 54);

    // Hole bar
    sf::Texture holeTexture;
    if (!holeTexture.loadFromFile("hole_frog.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite holeBar(holeTexture);
    float holeWidth = 80.0f;
//    sf::RectangleShape holeBar(sf::Vector2f(holeWidth, barHeight));
//    holeBar.setFillColor(sf::Color::Black);
//    holeBar.setOutlineColor(sf::Color::White);
//    holeBar.setOutlineThickness(1.0f);
    // Ground
    sf::RectangleShape ground(sf::Vector2f(windowWidth, barHeight));
    ground.setFillColor(sf::Color::White);
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
    if (!blastTexture.loadFromFile("splash.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite blastSprite(blastTexture);
    int blastFrame = 0;
    int blastFrameCounter = 0;
    bool blasting = false;
    blastSprite.setTextureRect(sf::IntRect(0, 0, blastTexture.getSize().x / numBlastFrames, blastTexture.getSize().y));
    blastSprite.setOrigin(blastSprite.getTextureRect().width / 2, blastSprite.getTextureRect().height / 2);
    blastSprite.setPosition(windowWidth / 2, windowHeight / 2);
    ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius, 0);

    bool ballReleased = false;
    bool passedHole = false;
    int score = 0;
    int lives = 3;
    float holeMinX = (windowWidth - holeWidth) / 2;
    float holeMaxX = holeMinX + holeWidth;

    sf::Vector2f blastPosition;

    sf::Font font1;
    if(!font1.loadFromFile("BITCBLKAD.ttf")){
        return EXIT_FAILURE;
    }

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Color color1(255, 178, 102);

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font1);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(color1);

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    // Lives text
    sf::Text livesText;
    livesText.setFont(font1);
    livesText.setCharacterSize(30);
    livesText.setFillColor(color1);
    livesText.setPosition(windowWidth - 100, 10);

    // Game Over text
    sf::Color color(0, 76, 156);

    sf::Text gameOverText;
    gameOverText.setFont(font1);
    gameOverText.setCharacterSize(60);
    gameOverText.setFillColor(color);
    //gameOverText.setString("Game Over!");
    gameOverText.setPosition((windowWidth - gameOverText.getLocalBounds().width) / 2, windowHeight / 2);

    const int buttonWidth = 200;
    const int buttonHeight = 50;

    // Start text
    sf::Text startText;
    startText.setFont(font1);
    startText.setCharacterSize(70);
    startText.setFillColor(color);
    startText.setString("Start");
    startText.setPosition((windowWidth - buttonWidth) / 2 + (buttonWidth - startText.getLocalBounds().width) / 2,
                          (windowHeight - buttonHeight) / 2 + (buttonHeight - startText.getLocalBounds().height) / 2);

    // continue text
    sf::Text continueText;
    continueText.setFont(font1);
    continueText.setCharacterSize(70);
    continueText.setFillColor(sf::Color::Green);
    continueText.setString("Continue");
    continueText.setPosition((windowWidth - buttonWidth) / 2 + (buttonWidth - startText.getLocalBounds().width) / 2 + 200,
                          (windowHeight - buttonHeight) / 2 + (buttonHeight - startText.getLocalBounds().height) / 2 + 200);


    // Restart button
    sf::Text restartButton;
    restartButton.setFont(font1);
    restartButton.setCharacterSize(70);
    restartButton.setFillColor(sf::Color::Green);
    restartButton.setString("Restart");
    restartButton.setPosition((windowWidth - buttonWidth) / 2 + (buttonWidth - startText.getLocalBounds().width) / 2,
                              (windowHeight - buttonHeight) / 2 + (buttonHeight - startText.getLocalBounds().height) / 2);

    bool gameEnded = false;
    bool restartClicked = false;
    bool continueClicked = false;

    // Blast sound effect

    sf::SoundBuffer blastSoundBuffer;
    if (!blastSoundBuffer.loadFromFile("splash.wav")) {
        return EXIT_FAILURE;
    }

    sf::Sound blastSound;
    blastSound.setBuffer(blastSoundBuffer);


    sf::Music music;
        if (!music.openFromFile("Soundtrack.wav"))
        {
            return EXIT_FAILURE;
        }
        music.setLoop(true);
        music.play();
    sf::Music music1;
        if (!music1.openFromFile("Soundtrack.wav"))
        {
            return EXIT_FAILURE;
        }
        music1.setLoop(true);
//            music1.play();

        // Click sound
        sf::Music clickSound;
            if (!clickSound.openFromFile("Click.wav"))
            {
                return EXIT_FAILURE;
            }
//            music.setLoop(true);
//            music.play();

    // Background image


    sf::Texture startTexture;
    if (!startTexture.loadFromFile("start.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite startSprite(startTexture);

    // Start button
//    sf::RectangleShape startButton(sf::Vector2f(buttonWidth, buttonHeight));
//    startButton.setFillColor(color);
//    startButton.setPosition((windowWidth - buttonWidth) / 2, (windowHeight - buttonHeight) / 2);



    bool gameStarted = false;

//    srand(NULL);
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
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (startText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        clickSound.play();
                                            gameStarted = true;
                                        }

                    if (continueText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        clickSound.stop();
                        clickSound.play();
                                            continueClicked = true;
                                        }
                    if (restartButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                        clickSound.stop();
                        clickSound.play();
                        // Reset game variables
                        score = 0;
                        lives = 3;
                        holeSpeed = 2.0f;
                        ballReleased = false;
                        passedHole = false;
                        gameEnded = false;
                        restartClicked = true;
                    }
                }
            }
        }
if (gameStarted) {
    if (continueClicked){
    music.stop();
        if (!gameEnded) {
            if (ballReleased) {
                if (ballSprite.getPosition().y + 25 >= windowHeight) {
                    if (!passedHole) {


                        blastPosition = ballSprite.getPosition();

                        blasting = true;
                        blastSound.play();

                        blastFrame = 0;
                        blastFrameCounter = 0;
                        lives--;

                    }
                    ballReleased = false;
                    passedHole = false;
                    ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius, 10);
                }
                else {
                    ballSprite.move(0, 5);
                    if (!passedHole && ballSprite.getPosition().x + ballRadius >= holeBar.getPosition().x &&
                                       ballSprite.getPosition().x - ballRadius <= holeBar.getPosition().x + holeWidth &&
                                       ballSprite.getPosition().y + ballRadius >= holeBar.getPosition().y &&
                                       ballSprite.getPosition().y - ballRadius <= holeBar.getPosition().y + barHeight)
                                   {
                        passedHole = true;
                        holeSpeed *= speedIncrease; //Increase speed as score increases.
                        score++;
                    }
                }
            }

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

            if (blasting) {
                blastFrameCounter++;
                if (blastFrameCounter >= blastFrameDuration) {
                    blastFrame++;
                    blastFrameCounter = 0;
                    if (blastFrame >= numBlastFrames) {
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
                music1.pause();
//                sleep(1);

                restartButton.setPosition((windowWidth - buttonWidth) / 2 + (buttonWidth - startText.getLocalBounds().width) / 2,
                                          (windowHeight - buttonHeight) / 2 + (buttonHeight - startText.getLocalBounds().height) / 2 + 15);
                gameOverText.setPosition((windowWidth - buttonWidth) / 2 + (buttonWidth - startText.getLocalBounds().width) / 2 - 70,
                                         (windowHeight - buttonHeight) / 2 + (buttonHeight - startText.getLocalBounds().height) / 2 - 75);
                gameOverText.setString("Your Score is: " + std::to_string(score));
                window.draw(gameoverSprite);
                window.draw(gameOverText);
                window.draw(restartButton);
            }

            window.display();
        }


        if (restartClicked) {
            music1.play();
            // Reset hole bar position
            holeBar.setPosition((windowWidth - holeWidth) / 2, windowHeight - barHeight);

            // Reset ball position
            ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius + 150, 10);

            // Reset game variables
            score = 0;
            lives = 3;
            holeSpeed = 2.0f;
            ballReleased = false;
            passedHole = false;
            gameEnded = false;
            restartClicked = false;
        }
     }
    else {
        music1.play();
        window.clear();
        window.draw(backgroundSprite);
        window.draw(howToPlaySprite);
        window.draw(continueText);
        window.display();
    }
    }
else {

           window.clear();
//           music1.play();
           // Draw start screen elements
           window.draw(startSprite);
//           window.draw(startButton);
           window.draw(startText);

           window.display();
       }
}

    return 0;
}
        }

        if (!gameEnded) {
                    if (ballReleased) {
                        if (ballSprite.getPosition().y >= windowHeight) {
                            if (!passedHole) {
                                lives--;
                            }
                            ballReleased = false;
                            passedHole = false;
                            ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius, 0);
                        }
                        else {
                            ballSprite.move(0, 5);
                            if (!passedHole && ballSprite.getGlobalBounds().intersects(holeBar.getGlobalBounds())) {
                                passedHole = true;
                                score++;
                            }
                        }
                    }
                    else {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && holeBar.getPosition().x + holeWidth < windowWidth) {
                            //ground.move(groundSpeed, 0);
                            holeBar.move(groundSpeed, 0);
                        }
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && holeBar.getPosition().x > 0) {
                            //ground.move(-groundSpeed, 0);
                            holeBar.move(-groundSpeed, 0);
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
