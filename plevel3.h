#ifndef PLEVEL3_H
#define PLEVEL3_H
#include "pgame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"
#include <vector>
#include "functions.h"
#include "item.h"
#include "projectile.h"
#include <SFML/Audio.hpp>


class PLevel3 : public PGame
{
public:
    /*FORME CANONIQUE*/
    PLevel3(){}
    PLevel3(sf::RenderWindow* window);
    PLevel3(const PLevel3& c);
    ~PLevel3();
    PLevel3& operator=(const PLevel3& e);


    void init();
    keyPressedOnce();
    int getType()const{return PLEVEL3;}
};

#endif // PLEVEL3_H
