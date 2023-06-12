#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <ctime>

class BallGame {
private:
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

    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
    sf::Sprite howToPlaySprite;
    sf::Sprite gameoverSprite;
    sf::Sprite ground;
    sf::Sprite holeBar;
    sf::Sprite ballSprite;
    sf::Sprite blastSprite;
    sf::Text scoreText;
    sf::Text livesText;
    sf::Text gameOverText;
    sf::Text startText;
    sf::Text continueText;
    sf::Text restartButton;
    sf::Color color1;
    sf::Color color;
    sf::Font font1;
    sf::Font font;
    sf::Vector2f blastPosition;
    sf::SoundBuffer blastSoundBuffer;
    sf::Sound blastSound;
    sf::Music music;
    sf::Music music1;
    sf::Music clickSound;

    bool ballReleased;
    bool passedHole;
    int score;
    int lives;
    float holeWidth;
    float holeMinX;
    float holeMaxX;
    int blastFrame;
    int blastFrameCounter;
    bool blasting;
    bool gameEnded;
    bool restartClicked;
    bool continueClicked;
    bool gameStarted;

public:
    BallGame() :
        window(sf::VideoMode(windowWidth, windowHeight), "Ball Game"),
        ballReleased(false),
        passedHole(false),
        score(0),
        lives(3),
        holeWidth(80.0f),
        holeMinX((windowWidth - holeWidth) / 2),
        holeMaxX(holeMinX + holeWidth),
        blastFrame(0),
        blastFrameCounter(0),
        blasting(false),
        gameEnded(false),
        restartClicked(false),
        continueClicked(false),
        gameStarted(false)
    {
        window.setFramerateLimit(60);

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("Background_.jpg")) {
            std::cout << "Failed to load background image!" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(backgroundTexture);
        backgroundSprite.setTexture(backgroundTexture);

        sf::Texture howToPlayTexture;
        if (!howToPlayTexture.loadFromFile("howToPlay.png")) {
            std::cout << "Failed to load how to play image!" << std::endl;
            return;
        }
        sf::Sprite howToPlaySprite(howToPlayTexture);
        howToPlaySprite.setTexture(howToPlayTexture);
        howToPlaySprite.setPosition(150, 75);

        sf::Texture gameoverTexture;
        if (!gameoverTexture.loadFromFile("gameover.png")) {
            std::cout << "Failed to load game over image!" << std::endl;
            return;
        }
        sf::Sprite gameoverSprite(gameoverTexture);
        gameoverSprite.setTexture(gameoverTexture);

        sf::Texture groundTexture;
        if (!groundTexture.loadFromFile("swampWater.jpg")) {
            std::cout << "Failed to load ground texture!" << std::endl;
            return;
        }
        sf::Sprite ground(groundTexture);
        ground.setTexture(groundTexture);
        ground.setPosition(0, windowHeight - barHeight + 54);


        sf::Texture holeTexture;
        if (!holeTexture.loadFromFile("hole_frog.png")) {
            std::cout << "Failed to load hole texture!" << std::endl;
            return;
        }
         sf::Sprite holeBar(holeTexture);
        holeBar.setTexture(holeTexture);
        holeBar.setPosition(holeMinX, windowHeight - barHeight + 22);

        sf::Texture ballTexture;
        if (!ballTexture.loadFromFile("fly.png")) {
            std::cout << "Failed to load ball texture!" << std::endl;
            return;
        }
        sf::Sprite ballSprite(ballTexture);
        ballSprite.setTexture(ballTexture);
        ballSprite.setOrigin(ballRadius, ballRadius);
        ballSprite.setPosition(windowWidth / 2, windowHeight / 2);

        sf::Texture blastTexture;
        if (!blastTexture.loadFromFile("splash.png")) {
            std::cout << "Failed to load blast texture!" << std::endl;
            return;
        }
        sf::Sprite blastSprite(blastTexture);
        blastSprite.setTexture(blastTexture);
        blastSprite.setOrigin(blastTexture.getSize().x / 2, blastTexture.getSize().y / 2);

        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cout << "Failed to load font!" << std::endl;
            return;
        }

        scoreText.setFont(font);
        scoreText.setCharacterSize(24);
        scoreText.setPosition(10, 10);

        livesText.setFont(font);
        livesText.setCharacterSize(24);
        livesText.setPosition(windowWidth - 110, 10);

        gameOverText.setFont(font);
        gameOverText.setCharacterSize(60);
        gameOverText.setPosition(windowWidth / 2 - 200, windowHeight / 2 - 50);
        gameOverText.setString("Game Over!");

        startText.setFont(font);
        startText.setCharacterSize(60);
        startText.setPosition(windowWidth / 2 - 320, windowHeight / 2 - 200);
        startText.setString("Click to Start!");

        continueText.setFont(font);
        continueText.setCharacterSize(60);
        continueText.setPosition(windowWidth / 2 - 200, windowHeight / 2 - 50);
        continueText.setString("Click to Continue!");

        restartButton.setFont(font);
        restartButton.setCharacterSize(30);
        restartButton.setPosition(windowWidth / 2 - 80, windowHeight / 2 + 50);
        restartButton.setString("Restart");

        color1.r = 255;
        color1.g = 153;
        color1.b = 51;

        color.r = 255;
        color.g = 0;
        color.b = 0;

        sf::SoundBuffer blastSoundBuffer;
        if (!blastSoundBuffer.loadFromFile("splash.wav")) {
            std::cout << "Failed to load blast sound!" << std::endl;
            return;
        }
        sf::Sound blastSound;
        blastSound.setBuffer(blastSoundBuffer);

        sf::Music music;
        if (!music.openFromFile("Soundtrack.wav")) {
            std::cout << "Failed to load background music!" << std::endl;
            return;
        }
        music.setLoop(true);
        music.play();

        sf::Music music1;
        if (!music1.openFromFile("Soundtrack.wav")) {
            std::cout << "Failed to load game over music!" << std::endl;
            return;
        }
        music1.setLoop(true);

        sf::Music clickSound;
        if (!clickSound.openFromFile("click.wav")) {
            std::cout << "Failed to load click sound!" << std::endl;
            return;
        }
    }

    void runGame() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space)
                        ballReleased = true;
                }
                else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (gameEnded) {
                            restartClicked = true;
                        }
                        else if (!gameStarted) {
                            gameStarted = true;
                            clickSound.play();
                        }
                        else if (passedHole) {
                            continueClicked = true;
                        }
                        else {
                            ballReleased = true;
                        }
                    }
                }
            }

            window.clear();
            window.draw(backgroundSprite);

            if (!gameStarted) {
                window.draw(startText);
                window.draw(howToPlaySprite);
            }
            else if (gameEnded) {
                window.draw(gameoverSprite);
                window.draw(gameOverText);
                window.draw(restartButton);
            }
            else {
                update();
                draw();
            }

            window.display();
        }
    }

    void update() {
        if (!ballReleased)
            return;

        if (blasting) {
            blastFrameCounter++;
            if (blastFrameCounter >= blastFrameDuration) {
                blastFrameCounter = 0;
                blastFrame++;
                if (blastFrame >= numBlastFrames) {
                    blasting = false;
                    blastFrame = 0;
                }
            }
        }

        if (ballSprite.getPosition().y + ballRadius * 2 > windowHeight - barHeight + 54) {
            if (ballSprite.getPosition().x >= holeMinX && ballSprite.getPosition().x <= holeMaxX) {
                passedHole = true;
                holeSpeed += speedIncrease;
                if (holeSpeed > maxHoleSpeed)
                    holeSpeed = maxHoleSpeed;
                score++;
            }
            else {
                lives--;
                if (lives <= 0) {
                    gameEnded = true;
                    music.stop();
                    music1.play();
                }
                else {
                    ballSprite.setPosition(windowWidth / 2, windowHeight / 2);
                    ballReleased = false;
                    passedHole = false;
                    holeSpeed = 2.0f;
                }
            }
        }

        float ballSpeed = groundSpeed + holeSpeed;
        ballSprite.move(0, ballSpeed);

        if (ballSprite.getPosition().y + ballRadius * 2 > windowHeight - barHeight + 54)
            ballSprite.setPosition(ballSprite.getPosition().x, windowHeight - barHeight + 54 - ballRadius * 2);

        if (blasting) {
            blastSprite.setPosition(blastPosition.x, blastPosition.y);
        }
        else {
            float holeMovement = groundSpeed + holeSpeed;
            holeBar.move(holeMovement, 0);
            if (holeBar.getPosition().x < 0 || holeBar.getPosition().x + holeWidth > windowWidth) {
                holeSpeed = -holeSpeed;
                holeBar.move(holeSpeed, 0);
            }
        }
    }

    void draw() {
        window.draw(ground);
        window.draw(holeBar);
        window.draw(ballSprite);

        if (blasting)
            window.draw(blastSprite);

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        livesText.setString("Lives: " + std::to_string(lives));
        window.draw(livesText);
    }
};

int main() {
    BallGame game;
    game.runGame();
    return 0;
}
