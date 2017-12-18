#include <QApplication>
#include <SFML/Graphics.hpp>
#include <QFileInfo>
#include <QDebug>
#include <sstream>
#include <SFML/Audio.hpp>
#include <vector>
#include "animation.h"
#include "player.h"
#include "platform.h"
#include "functions.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <string>
#include "enemy.h"
#include "projectile.h"
#include "panel.h"
#include "pwelcome.h"
#include "psettings.h"
#include "plevel.h"
#include "plevel2.h"
#include "plevel3.h"
#include "pabout.h"
#include "soundengine.h"


using namespace std;



int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"The Legend of HELHa",sf::Style::Close | sf::Style::Resize);
    SoundEngine *se = SoundEngine::getInstance();

    se->goMusic("music/mainTheme.ogg");

    //Ajout des différents panels avec une RenderWindow par référence (obligatoire car pas copiable)
    int activePanel=0;
    vector<Panel*> panels;
    panels.push_back(new PWelcome(&window));
    panels.push_back(new PSettings(&window));
    panels.push_back(new PAbout(&window));
    panels.push_back(new PLevel(&window));
    panels.push_back(new PLevel2(&window));
    panels.push_back(new PLevel3(&window));


    for(int i = 0;i<panels.size();i++)
    {
        panels[i]->ResizeView();
    }

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type){
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                for(int i = 0;i<panels.size();i++)
                {
                    panels[i]->ResizeView();
                }
                break;
            case sf::Event::LostFocus:
                panels[activePanel]->setActiveP(0);
                break;
            }

        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
            panels[activePanel]->setActiveP(Panel::PLEVEL1);
             se->goMusic("music/level1.ogg");
             panels[activePanel]->setActiveLevel(3);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F2)){
            panels[activePanel]->setActiveP(Panel::PLEVEL2);
             se->goMusic("music/level2.ogg");
             panels[activePanel]->setActiveLevel(4);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F3)){
            panels[activePanel]->setActiveP(Panel::PLEVEL3);
             se->goMusic("music/level3.ogg");
             panels[activePanel]->setActiveLevel(5);
        }

        activePanel=panels[activePanel]->getActiveP();
        window.clear(sf::Color::Black);
        panels[activePanel]->init();
       // window.clear(sf::Color(150,150,150));
        window.display();
    }
    return 0;
}
