#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
<<<<<<< HEAD
<<<<<<< HEAD
#include <unistd.h>
#include <ctime>
=======
>>>>>>> 42d99f0 (Added Blast sound effect)
=======
#include <unistd.h>
#include <ctime>
>>>>>>> e18a912 (Added soundtrack)


int main()
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    const int barHeight = 74;
<<<<<<< HEAD
    const int ballRadius = 10;
    float groundSpeed = 2.0f;
    float holeSpeed = 2.0f;
    const float maxHoleSpeed = 8.0f;
    const float speedIncrease = 1.2f;
    const int numBlastFrames = 7;
    const int blastFrameDuration = 5;
    const int barHeight = 20;
=======
>>>>>>> 0275351 (Added a start button and edited sprites)
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
    if (!backgroundTexture.loadFromFile("Background_.jpg")) {
<<<<<<< HEAD
    if (!backgroundTexture.loadFromFile("Background.jpg")) {
=======
>>>>>>> 0275351 (Added a start button and edited sprites)
        return EXIT_FAILURE;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 3fcc762 (Added Instructions)
    // How to Play image
    sf::Texture howToPlayTexture;
    if (!howToPlayTexture.loadFromFile("howToPlay.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite howToPlaySprite(howToPlayTexture);
    howToPlaySprite.setPosition(150, 75);


<<<<<<< HEAD
=======
>>>>>>> 7ec9272 (Added Gameover background)
=======
>>>>>>> 3fcc762 (Added Instructions)
    // Game over image
    sf::Texture gameoverTexture;
    if (!gameoverTexture.loadFromFile("gameover.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite gameoverSprite(gameoverTexture);


<<<<<<< HEAD
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
=======
>>>>>>> 7ec9272 (Added Gameover background)
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
    holeBar.setPosition((windowWidth - holeWidth) / 2, windowHeight - barHeight);

    // Ball sprite
    sf::Texture ballTexture;
    if (!ballTexture.loadFromFile("fly.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite ballSprite(ballTexture);
    ballSprite.setOrigin(ballRadius, ballRadius);
    ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius + 150, 10);

    // Blast sprite
<<<<<<< HEAD
<<<<<<< HEAD
    sf::Texture blastTexture;
    if (!blastTexture.loadFromFile("splash.png")) {
        return EXIT_FAILURE;
    }
=======
       sf::Texture blastTexture;
       if (!blastTexture.loadFromFile("blast.png"))
       {
           return EXIT_FAILURE;
       }
>>>>>>> c30bbfb (Added blast effect for ball)
=======
    sf::Texture blastTexture;
    if (!blastTexture.loadFromFile("splash.png")) {
        return EXIT_FAILURE;
    }
>>>>>>> 2185298 (Added Restart Button)

    sf::Sprite blastSprite(blastTexture);
    int blastFrame = 0;
    int blastFrameCounter = 0;
    bool blasting = false;
    blastSprite.setTextureRect(sf::IntRect(0, 0, blastTexture.getSize().x / numBlastFrames, blastTexture.getSize().y));
    blastSprite.setOrigin(blastSprite.getTextureRect().width / 2, blastSprite.getTextureRect().height / 2);
    blastSprite.setPosition(windowWidth / 2, windowHeight / 2);
<<<<<<< HEAD
    ballSprite.setPosition(rand() % (windowWidth - ballRadius * 2) + ballRadius, 0);
=======

<<<<<<< HEAD
>>>>>>> c30bbfb (Added blast effect for ball)

=======
>>>>>>> 2185298 (Added Restart Button)
    bool ballReleased = false;
    bool passedHole = false;
    int score = 0;
    int lives = 3;
    float holeMinX = (windowWidth - holeWidth) / 2;
    float holeMaxX = holeMinX + holeWidth;

    sf::Vector2f blastPosition;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> e18a912 (Added soundtrack)
    sf::Font font1;
    if(!font1.loadFromFile("BITCBLKAD.ttf")){
        return EXIT_FAILURE;
    }

<<<<<<< HEAD
=======
>>>>>>> c30bbfb (Added blast effect for ball)
=======
>>>>>>> e18a912 (Added soundtrack)
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Color color1(255, 178, 102);
<<<<<<< HEAD

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font1);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(color1);
=======
>>>>>>> e18a912 (Added soundtrack)

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font1);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(color1);
    scoreText.setPosition(10, 10);

    // Lives text
    sf::Text livesText;
    livesText.setFont(font1);
    livesText.setCharacterSize(30);
    livesText.setFillColor(color1);
<<<<<<< HEAD
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
=======
>>>>>>> e18a912 (Added soundtrack)
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                    if (startText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        clickSound.play();
                                            gameStarted = true;
                                        }

                    if (continueText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        clickSound.stop();
                        clickSound.play();
                                            continueClicked = true;
                                        }
<<<<<<< HEAD
=======
                    if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
=======
                    if (startText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
>>>>>>> e18a912 (Added soundtrack)
                                            gameStarted = true;
                                        }
>>>>>>> 0275351 (Added a start button and edited sprites)
                    if (restartButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                        clickSound.stop();
                        clickSound.play();
=======
                    if (restartButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
>>>>>>> 2185298 (Added Restart Button)
=======
                    if (restartButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                        clickSound.stop();
                        clickSound.play();
>>>>>>> 3fcc762 (Added Instructions)
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
<<<<<<< HEAD
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
=======
>>>>>>> 2185298 (Added Restart Button)
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
