#ifndef PGAME_H
#define PGAME_H
#include "panel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <button.h>
#include <vector>
#include "player.h"
#include "item.h"
#include "projectile.h"

using namespace std;

class PGame : public Panel
{
    protected:
     sf::Texture playerTexture;
     sf::View viewGame;

     /*TEXTURE*/
     sf::Texture projectileTexture;
     /*PROJECTILE*/
     std::vector<Projectile> projectileVector;
     std::vector<Projectile> projectileVectorEnemy;
     std::vector<Enemy*> enemies;
     std::vector<Platform> platforms;
     std::vector<Item> items;
     float deltaTime = 0.0f;
     sf::Clock clock;
    public:
     /*FORME CANONIQUE*/
     PGame(){}
     PGame(sf::RenderWindow* window);
     PGame(const PGame& c);
     virtual ~PGame();
     PGame& operator=(const PGame& e);

     collision();
     camera();
     drawAll();
     void initDeltaTime();

     void ResizeView();
};

#endif // PGAME_H
