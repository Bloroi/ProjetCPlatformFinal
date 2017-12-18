#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "animation.h"
#include "collider.h"
#include "enemy.h"
#include "soundengine.h"

class Player
{

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    bool key;
    bool key2;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
    int health;
    int score;
    SoundEngine *se = SoundEngine::getInstance();

public:
    /*FORME CANONIQUE*/
    Player();
    Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed,float jumpHeight, int score = 0,int health = 5, bool key = false,bool key2 = false);
    Player(const Player& c);
    ~Player();
    Player& operator=(const Player& e);


    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);

    sf::Vector2f GetPosition(){return body.getPosition();}
    bool GetFaceRight(){return faceRight;}
    void setPosition(sf::Vector2f position){ body.setPosition(position);}
    Collider GetCollider(){ return Collider(body);}
    int getScore()const{return score;}
    int getHealth()const{return health;}
    void setScore(int newScore){score = newScore;}
    void setHealth(int newHealth){health = newHealth;}
    int getKey()const{return key;}
    void setKey(int newKey){key = newKey;}
    int getKey2()const{return key2;}
    void setKey2(int newKey){key2 = newKey;}
    /*bool collisions(Enemy e)
    {
        this->getGlo
    }*/

};

#endif // PLAYER_H
