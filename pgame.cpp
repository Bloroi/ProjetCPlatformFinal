#include "pgame.h"

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
{}

PGame::collision()
{

    /*Personnage en mvt*/
            player.Update(deltaTime);
            /*Ennemi en mvt*/
            for(int i=0;i<enemies.size();i++){

                enemies[i]->Update(deltaTime,platforms);
                if(enemies[i]->GetCollider().CheckCollect(player.GetCollider())){
                    //player.setPosition(sf::Vector2f(0.00f,0.00f));
                    //player.OnCollision(direction);
                    player.setcolordamage(sf::Color::Red);
                    player.setPosition(sf::Vector2f(206.0f,206.0f));
                 }
                else{
                    player.setcolordamage(sf::Color::White);
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

            /*Gestion collision avec les items*/
            for(Item& item : items) // for each
            {
                if(items[0].GetCollider().CheckCollect(player.GetCollider())){
                    if(item.GetCollider().CheckCollect(player.GetCollider())){
                        item.setPos(sf::Vector2f(0.00f,0.00f));
                        player.setKey(true);
                        se->playPickItem();
                     }
                }else{
                    if(items[1].GetCollider().CheckCollect(player.GetCollider()) && player.getKey()){

                    }
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
               if((enemies[i]->GetPosition().x - player.GetPosition().x) <= 500 && (enemies[i]->GetPosition().x - player.GetPosition().x) >= -500){
                   cout<<"OK";
                   Projectile newProjectile(&projectileTexture,sf::Vector2f(20,70),2);
                   newProjectile.setPosition(sf::Vector2f(enemies[i]->GetPosition()));
                   projectileVector.push_back(newProjectile);
               }
               if(enemies[i]->getHealth() <= 0){
                    enemies.erase(enemies.begin()+i);
               }
            }


            for(int i=0;i< projectileVector.size();i++)
            {

                if(projectileVector[i].GetPosition().x>( player.GetPosition().x+500)){
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
                        player.setScore(player.getScore() + 100);
                }


            }

            }
}

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

void PGame::ResizeView()
{
    float aspectRatio = float(mainWindow->getSize().x)/ float(mainWindow->getSize().y);
    viewGame.setSize(VIEW_GAME * aspectRatio,VIEW_GAME);
}
