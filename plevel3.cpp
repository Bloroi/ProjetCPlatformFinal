#include "plevel3.h"

/**
 * @brief PLevel3::PLevel3 Classe Panel permettant d'afficher le niveau 3
 * @param window
 */
PLevel3::PLevel3(sf::RenderWindow* window): PGame(window)
{
        //platforms
        readPlatform(platforms,"level/platformsLVL3.txt");

        //ennemies
        readennemy(enemies,"level/enemiesLVL3.txt");

        items.push_back(Item(sf::Vector2f(300,400),sf::Vector2f(11500,275),"images/porte.png"));
}

PLevel3::PLevel3(const PLevel3& b){

        readPlatform(platforms,"level/platformsLVL3.txt");
       /* this->enemyTexture1= b.enemyTexture1;
        this->enemyTexture2= b.enemyTexture2;*/
        readennemy(enemies,"level/enemiesLVL3.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;

        this->items= b.items;

}

PLevel3& PLevel3::operator=(const PLevel3& b){
    if(!(&b==this)){

        readPlatform(platforms,"level/platforms.txt");
        readennemy(enemies,"level/enemiesLVL1.txt");

        this->projectileTexture= b.projectileTexture;

        this->enemies = b.enemies;

        this->items= b.items;

    }
    return *this;
}

PLevel3::~PLevel3()
{}

/*Méthode qui est appelée tout le temps dans le jeu.
 * Sorte de main pour une classe*/
void PLevel3::init()
{
    mainWindow->clear(sf::Color(99,00,00));
    initDeltaTime();

    /*Gestion collision avec les items*/
      if(items[0].GetCollider().CheckCollect(player.GetCollider())){
            se->playCongrats();
            se->goMusic("music/mainTheme.ogg");
            setActiveP(PABOUT);
      }




    collision();
    camera();
    drawAll();

    keyPressedOnce();
}

/**
 * @brief PLevel3::keyPressedOnce Méthode permettant de vérifier si une touche précise est appuyée pour un événement
 */
PLevel3::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }
}
