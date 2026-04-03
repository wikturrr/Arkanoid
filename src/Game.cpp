#include "Game.h"

Game::Game() : window(sf::VideoMode({windowWidth, windowHeight}), "Arkanoid"), score(font,"0",20), lifes(font,"0", 20){
    window.setFramerateLimit(60);
    playground.setFillColor({55, 87, 191});
    playground.setPosition({0.f,100.f});
    playground.setSize({playgroundWidth, PlaygroundHeight});
    if (!font.openFromFile("assets/fonts/ALGER.TTF")){
        std::cerr<<"Nie mozna znalezc czcionki"<<std::endl;
    }
    score.setPosition({25.f,25.f});
    score.setFillColor(sf::Color::White);
    lifes.setPosition({500.f,25.f});
    lifes.setFillColor(sf::Color::White);
}

void Game::run(){
    Player player;
    std::vector<Brick> brick;
    Ball ball;

    for(int i=0; i<12; i++){
        for(int j=0; j<7; j++){
            brick.emplace_back(i*50.f, j*50.f+125.f);
        }
    }
    
    //------------------GAME-LOOP----------------------
    while(window.isOpen()){
        window.clear({21, 41, 92});
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        
        score.setString(ball.GetScore());
        if(ball.getLifes() != 0) {
            lifes.setString("Balls:" + ball.GetLifes());
        }else{
            lifes.setPosition({250.f,25.f});
            lifes.setString("Game Over:");
        }
        player.movement(window);
        ball.movement(window, player);
        window.draw(playground);
        ball.draw(window);
        player.draw(window);
        for(Brick& b: brick){
            b.draw(window);
            ball.collisionWithBrick(b);
        }
        window.draw(score);
        window.draw(lifes);
        window.display();
    }
}