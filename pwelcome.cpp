#include "pwelcome.h"

PWelcome::PWelcome(sf::RenderWindow* window) : PMenus(window)
{


  /*  rect.setPosition(sf::Vector2f(50,200));
    rect.setSize(sf::Vector2f(30,30));
    rect.setFillColor(sf::Color(33,42,231,255));*/


    buttons.push_back(new button("buttonPlay",Panel::PLEVEL1,2,sf::Vector2i(0,-150),"images/BoutonPlayR1.png","images/BoutonPlayV1.png"));
    buttons.push_back(new button("buttonOptions",Panel::PSETTINGS,2,sf::Vector2i(0,0),"images/BoutonOptionR.png","images/BoutonOptionV.png"));
    buttons.push_back(new button("buttonAbout",Panel::PABOUT,2,sf::Vector2i(0,150),"images/BoutonAPR.png","images/BoutonAPV.png"));
    //buttons.push_back(new button("buttonSettings",Panel::PMENU,2,sf::Vector2i(0,150),"images/bouton1.png","images/bouton2.png"));
    background.loadFromFile("images/fond-Menu.jpg");
    image.setTexture(background);
}
PWelcome::PWelcome(const PWelcome& b){

    this->rect=b.rect;
    this->buttons=b.buttons;

}

PWelcome& PWelcome::operator=(const PWelcome& b){
    if(!(&b==this)){

    this->rect=b.rect;
    this->buttons=b.buttons;

    }
    return *this;
}

PWelcome::~PWelcome()
{}

void PWelcome::init()
{

    aspectRatio = float(mainWindow->getSize().x)/float(mainWindow->getSize().y);
    mainWindow->setView(viewMenu);


    // récupération de la position de la souris dans la fenêtre
   pixelPos = sf::Mouse::getPosition(*mainWindow);

    // conversion en coordonnées "monde"
   worldPos = mainWindow->mapPixelToCoords(pixelPos);

    for(int i =0;i<buttons.size();i++)
        mouseClicked(buttons[i]);

    keyPressedOnce();
    //mainWindow->draw(image);
    for(int i =0;i<buttons.size();i++)
        mainWindow->draw(buttons.at(i)->getSprite());
}

PWelcome::keyPressedOnce(){

}

