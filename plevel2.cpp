#include "plevel2.h"


PLevel2::PLevel2(sf::RenderWindow* window): PGame(window)
{
        //platforms
        readPlatform(platforms,"level/platformsLVL2.txt");

        //ennemies
        readennemy(enemies,"level/enemiesLVL2.txt");

        //ITEMS3000,-4950
        items.push_back(Item(sf::Vector2f(80,80),sf::Vector2f(3000,-4950),"images/key.png"));
        items.push_back(Item(sf::Vector2f(150,200),sf::Vector2f(12225,-5025),"images/porte.png"));

}

PLevel2::PLevel2(const PLevel2& b){

        readPlatform(platforms,"level/platformsLVL2.txt");
       /* this->enemyTexture1= b.enemyTexture1;
        this->enemyTexture2= b.enemyTexture2;*/
        readennemy(enemies,"level/enemiesLVL2.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;

        this->items= b.items;

}

PLevel2& PLevel2::operator=(const PLevel2& b){
    if(!(&b==this)){

        readPlatform(platforms,"level/platforms.txt");
        readennemy(enemies,"level/enemiesLVL1.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;

        this->items= b.items;
    }
    return *this;
}

PLevel2::~PLevel2()
{}

/*Méthode qui est appelée tout le temps dans le jeu.
 * Sorte de main pour une classe*/
void PLevel2::init()
{
    initDeltaTime();

    /*Gestion collision avec les items*/
    for(Item& item : items) // for each
    {
        if(items[0].GetCollider().CheckCollect(player.GetCollider())){
            if(item.GetCollider().CheckCollect(player.GetCollider())){
                item.setPos(sf::Vector2f(-10000.0f,-10000.00f));
                player.setKey2(true);
                se->playPickItem();
             }
        }else{
            if(items[1].GetCollider().CheckCollect(player.GetCollider()) && player.getKey2()){
                   setActiveP(PLEVEL3);

            }
        }


    }

    collision();
    camera();
    drawAll();

    keyPressedOnce();
}



PLevel2::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }

}

