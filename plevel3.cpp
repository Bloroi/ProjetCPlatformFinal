#include "plevel3.h"


PLevel3::PLevel3(sf::RenderWindow* window): PGame(window)
{
        //platforms
        readPlatform(platforms,"level/platformsLVL3.txt");

        //ennemies
        readennemy(enemies,"level/enemiesLVL3.txt");


}

PLevel3::PLevel3(const PLevel3& b){

        readPlatform(platforms,"level/platformsLVL3.txt");
       /* this->enemyTexture1= b.enemyTexture1;
        this->enemyTexture2= b.enemyTexture2;*/
        readennemy(enemies,"level/enemiesLVL3.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;



}

PLevel3& PLevel3::operator=(const PLevel3& b){
    if(!(&b==this)){

        readPlatform(platforms,"level/platforms.txt");
        readennemy(enemies,"level/enemiesLVL1.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;

    }
    return *this;
}

PLevel3::~PLevel3()
{}

/*Méthode qui est appelée tout le temps dans le jeu.
 * Sorte de main pour une classe*/
void PLevel3::init()
{
    initDeltaTime();



    collision();
    camera();
    drawAll();

    keyPressedOnce();
}

PLevel3::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }
}
