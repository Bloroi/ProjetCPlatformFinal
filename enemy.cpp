#include "enemy.h"

/**
 * @brief Enemy::Enemy Cette classe permet de créer des objets ennemis
 * @param name nom de l'ennemi
 * @param filename chemin d'accès du fichier
 * @param imageCount nombre d'image par seconde pour l'animation
 * @param size taille de l'ennemi
 * @param position position de l'ennemi
 * @param switchTime
 * @param speed vitesse de l'ennemi
 * @param health vie de l'ennemi
 */
Enemy::Enemy(string name,string filename,sf::Vector2u imageCount,sf::Vector2f size,sf::Vector2f position,float switchTime,float speed, int health)
   {

    cout<<name<<"|"<<filename<<"|"<<imageCount.x<<"|"<<imageCount.y<<"|"<<size.x<<"|"<<position.x<<"|"<<position.y<<"|"<<switchTime<<"|"<<speed<<"|"<<health<<endl;
    this->name = name;

    sf::Texture *texture = new sf::Texture;
    if(!texture->loadFromFile(filename))
        qDebug()<<"Fichier n'existe pas";

    texture->setSmooth(true);

    this->speed = speed;
    this->health = health;
    row = 0;
    faceRight = true;
    body.setPosition(position);

    body.setSize(size);
    body.setOrigin(body.getSize()/2.0f);
    body.setTexture(texture);
    pos =0;
    //body.setFillColor(sf::Color::Red);
    animation = Animation(texture,imageCount,switchTime);
}

Enemy::Enemy(const Enemy& b){

    this->name = b.name;
    this->speed = b.speed;
    this->row = b.row;
    this->faceRight = b.faceRight;
    this->body.setPosition(b.position);

    this->body=b.body;
    pos =0;

}

Enemy& Enemy::operator=(const Enemy& b){
    if(!(&b==this)){

        this->speed = b.speed;
        this->row = b.row;
        this->faceRight = b.faceRight;
        this->body.setPosition(b.position);

        this->body=b.body;
        pos =0;

    }
    return *this;
}

Enemy::~Enemy(){

}

/**
 * @brief Enemy::OnCollision Méthode qui empêche l'ennemi d'avancer dans un mur
 * @param direction direction où regarde l'ennemi
 */
void Enemy::OnCollision(sf::Vector2f direction)
{
    if(direction.x < 0.0f)
    {
        //Collision on the left.
        velocity.x=0.0f;
    }
    else if(direction.x > 0.0f)
    {
        //Collision on the right.
        velocity.x = 0.0f;
    }

    if(direction.y < 0.0f)
    {
        //Collision on the bottom.
        velocity.y=0.0f;
    }
    else if(direction.y > 0.0f)
    {
        //Collision on the top.
        velocity.y = 0.0f;
    }


}

/*Méthode qui permet de faire bouger l'ennemi*/
void Enemy::Update(float deltaTime,vector<Platform> plats){


    velocity.x = 0.0f;
    bool moveOK=false;
    //pos++;

//cout<<pos<<endl;
if(velocity.y==0){
    if(pos<20000)
     {
        for(int i=0;i<plats.size();i++)
        {

            if(plats[i].GetCollider().CheckOnPlatform(this->GetCollider()) ){

               moveOK=true;
               break;

            }


            if(plats[i].GetCollider().CheckWalls(this->GetCollider())){
                pos=20000;
                break;
            }


        }
        if(!moveOK ){
            pos=20000;

             velocity.x +=speed ;
        }
        else
        {
            pos++;
            velocity.x -=speed ;
            if(velocity.x==0){
                pos=20000;
            }
        }

     }
      else
     {
        for(int i=0;i<plats.size();i++)
        {

            if(plats[i].GetCollider().CheckOnPlatform(this->GetCollider())){

               moveOK=true;
               break;

            }

            if(plats[i].GetCollider().CheckWalls(this->GetCollider())){
                pos=0;
                break;
            }

        }
        if(!moveOK){
            pos=0;

            velocity.x -=speed ;
        }
        else
        {
            pos++;
            velocity.x +=speed ;
            if(velocity.x==0){
                pos=0;
            }
        }

     }
    if(pos==40000){
        pos=0;
    }

}


    velocity.y += 981.0f * deltaTime;

    if(velocity.x ==0.0f)
    {
        animation.setSwitchTime(0.3f);
        row=0;
    }
    else
    {
        row = 2;
        animation.setSwitchTime(0.1f);

        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }


    animation.Update(row,deltaTime,faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity*deltaTime);
}




/*Méthode qui permet d'afficher l'ennemi dans le panel*/
void Enemy::Draw(sf::RenderWindow& window){
    window.draw(body);
}

