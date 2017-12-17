#ifndef PLEVEL2_H
#define PLEVEL2_H
#include "pgame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"
#include <vector>
#include "functions.h"
#include "item.h"
#include "projectile.h"
#include <SFML/Audio.hpp>

using namespace std;

class PLevel2 : public PGame
{
public:
    /*FORME CANONIQUE*/
    PLevel2(){}
    PLevel2(sf::RenderWindow* window);
    PLevel2(const PLevel2& c);
    ~PLevel2();
    PLevel2& operator=(const PLevel2& e);


    void init();
    keyPressedOnce();
    int getType()const{return PLEVEL2;}
};

#endif // PLEVEL2_H
