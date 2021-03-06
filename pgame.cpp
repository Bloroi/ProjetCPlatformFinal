#include "pgame.h"

/**
 * @brief PGame::PGame superclasse des différents panel niveaux
 * @param window
 */
PGame::PGame(sf::RenderWindow* window) : Panel(window)
{

   this->viewGame = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(Panel::VIEW_GAME,VIEW_GAME));
  /*PLAYER*/
    if(!playerTexture.loadFromFile("images/playerRedmond.png")){
            QFileInfo file("images/persogrille2.png");
            qDebug() << file.absolutePath() << file.exists()<<"Fichier n'existe pas";
        }
    playerTexture.setSmooth(true);

    this->player = Player(&playerTexture, sf::Vector2u(4,3),0.1f,350.0f,500.0f);
    this->player.setScore(0);
    if(!projectileTexture.loadFromFile("images/Boule_Feu.png")){

    }




}

PGame::PGame(const PGame& b){

    this->viewGame = b.viewGame;
    this->playerTexture = b.playerTexture;
    this->player = b.player;

}

PGame& PGame::operator=(const PGame& b){
    if(!(&b==this)){

        this->viewGame = b.viewGame;
        this->playerTexture = b.playerTexture;


        this->player = b.player;

    }
    return *this;
}

PGame::~PGame()
{
    for(int i =0;i<enemies.size();i++){
            delete(enemies.at(i));
            enemies.at(i) =0;
        }
    enemies.clear();
    platforms.clear();
    items.clear();

}

/**
 * @brief PGame::collision Méthode appellée par les sous classe pour compléter le init() pour les collisions
 */
PGame::collision()
{

    /*Personnage en mvt*/
            player.Update(deltaTime);
            /*Ennemi en mvt*/
            for(int i=0;i<enemies.size();i++){

                enemies[i]->Update(deltaTime,platforms);
                if(enemies[i]->GetCollider().CheckCollect(player.GetCollider())){
                    player.setPosition(sf::Vector2f(206.0f,206.0f));
                 }
            }


            sf::Vector2f direction;

            if(player.GetPosition().y > 1000){
               player.setPosition(sf::Vector2f(206.0f,206.0f));
            }


            /*Gestion des collisions avec la platforme*/
            for(Platform& platform : platforms) // for each
            {
                if(platform.GetCollider().CheckCollision(player.GetCollider(),direction,1.00f))
                    player.OnCollision(direction);

                for(int i=0;i<enemies.size();i++)
                {
                    if(platform.GetCollider().CheckCollision(enemies[i]->GetCollider(),direction,1.00f))
                       enemies[i]->OnCollision(direction);
                }
            }



            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){

                if( player.GetFaceRight())
                {

                     Projectile newProjectile(&projectileTexture,sf::Vector2f(20,70),2);
                     newProjectile.setPosition(sf::Vector2f(player.GetPosition()));
                     projectileVector.push_back(newProjectile);

                }
                else
                {

                     Projectile newProjectile(&projectileTexture,sf::Vector2f(20,70),-2);
                     newProjectile.setPosition(sf::Vector2f(player.GetPosition()));
                     projectileVector.push_back(newProjectile);
                }

            }


            for(int i=0; i<enemies.size();i++){
               if(player.GetCollider().CheckCollision(enemies[i]->GetCollider(),direction,1.00f)){
                    player.setPosition(sf::Vector2f(206.0f,206.0f));
                    se->playOuch();
               }
               if(enemies[i]->getHealth() <= 0){
                    enemies.erase(enemies.begin()+i);
                    player.setScore(player.getScore() + 100);
               }
            }


            for(int i=0;i< projectileVector.size();i++)
            {

                if(projectileVector[i].GetPosition().x>( player.GetPosition().x+500)||projectileVector[i].GetPosition().x<( player.GetPosition().x-500)){
                    projectileVector.erase(projectileVector.begin()+i);
                }
                else
                {
                    projectileVector[i].Draw(*mainWindow);
                    projectileVector[i].fire();
                }

                for(int j=0; j<enemies.size();j++){
                    if(projectileVector[i].GetCollider().CheckCollision(enemies[j]->GetCollider(),direction,0.10f)){
                        enemies[j]->setHealth(enemies[j]->getHealth() - 1);
                        projectileVector.clear();

                }


                }

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F4)){
               player.setKey(true);
               player.setKey2(true);
              std::cout<<"OKOK";
            }
}

/**
 * @brief PGame::camera Méthode appellée par les sous classe pour compléter le init() pour la caméra view
 */
PGame::camera()
{
    aspectRatio = float(mainWindow->getSize().x)/float(mainWindow->getSize().y);

    //Empêche la caméra d'aller plus loin d'un certain x et y
            viewGame.setCenter(player.GetPosition().x,player.GetPosition().y-200);


            if(viewGame.getCenter().x<(VIEW_GAME*aspectRatio)/2){
                viewGame.setCenter((VIEW_GAME*aspectRatio)/2,viewGame.getCenter().y);
            }

            if(viewGame.getCenter().y>0){
                viewGame.setCenter(viewGame.getCenter().x,0);
            }


         mainWindow->setView(viewGame);
}

/**
 * @brief PGame::drawAll Méthode appellée par les sous classe pour compléter le init() pour dessiner les divers éléments dans la window
 */
PGame::drawAll()
{
    player.Draw(*mainWindow);


    for(int i=0;i<enemies.size();i++)
    {
       enemies[i]->Draw(*mainWindow);
    }


   for(Platform& platform : platforms){
        platform.Draw(*mainWindow);
   }

   for(Item item : items){
        item.Draw(*mainWindow);
    }

}


/*Initialiser le delta time*/
void PGame::initDeltaTime(){
 deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f /20.0f){
            deltaTime = 1.0f /20.0f;
        }
}

/**
 * @brief PGame::ResizeView Cette méthode permet de mettre la view à la bonne taille si la fenêtre change de taille
 */
void PGame::ResizeView()
{
    float aspectRatio = float(mainWindow->getSize().x)/ float(mainWindow->getSize().y);
    viewGame.setSize(VIEW_GAME * aspectRatio,VIEW_GAME);
}
