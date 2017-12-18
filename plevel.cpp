#include "plevel.h"

PLevel::PLevel(sf::RenderWindow* window): PGame(window)
{

        //platforms
        readPlatform(platforms,"level/platformsLVL1.txt");

        //ennemies
        readennemy(enemies,"level/enemiesLVL1.txt");

        //ITEMS
        items.push_back(Item(sf::Vector2f(80,80),sf::Vector2f(13000,-1050),"images/key.png"));
        items.push_back(Item(sf::Vector2f(150,200),sf::Vector2f(15125,-5900),"images/porte.png"));
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

    /*Gestion collision avec les items*/
    for(Item& item : items) // for each
    {
        if(items[0].GetCollider().CheckCollect(player.GetCollider())){
            if(item.GetCollider().CheckCollect(player.GetCollider())){
                item.setPos(sf::Vector2f(-10000.0f,-10000.0f));
                player.setKey(true);
                se->playPickItem();
             }
        }else{
            if(items[1].GetCollider().CheckCollect(player.GetCollider()) && player.getKey()){
                   setActiveP(PLEVEL2);
                   se->goMusic("music/level2.wav");

            }
        }


    }



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
