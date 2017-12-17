#include "plevel.h"

PLevel::PLevel(sf::RenderWindow* window): PGame(window)
{

    //platforms
        readPlatform(platforms,"level/platformsLVL1.txt");

        //ennemies
        readennemy(enemies,"level/enemiesLVL1.txt");

        //ITEMS
        items.push_back(Item(sf::Vector2f(80,80),sf::Vector2f(570,420)));
}

PLevel::PLevel(const PLevel& b){

        readPlatform(platforms,"level/platforms.txt");
       /* this->enemyTexture1= b.enemyTexture1;
        this->enemyTexture2= b.enemyTexture2;*/
        readennemy(enemies,"level/enemiesLVL1.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;

        this->items= b.items;

}

PLevel& PLevel::operator=(const PLevel& b){
    if(!(&b==this)){

        readPlatform(platforms,"level/platforms.txt");
        readennemy(enemies,"level/enemiesLVL1.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;

        this->items= b.items;
    }
    return *this;
}

PLevel::~PLevel()
{}

/*Méthode qui est appelée tout le temps dans le jeu.
 * Sorte de main pour une classe*/
void PLevel::init()
{
    initDeltaTime();
    collision();
    camera();
    drawAll();

    keyPressedOnce();
}

PLevel::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }
}
