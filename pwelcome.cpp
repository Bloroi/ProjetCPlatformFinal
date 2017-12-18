#include "pwelcome.h"

PWelcome::PWelcome(sf::RenderWindow* window) : PMenus(window)
{

    buttons.push_back(new button("buttonPlay",Panel::PLEVEL1,2,sf::Vector2i(0,-150),"images/BoutonPlayR1.png","images/BoutonPlayV1.png"));
    buttons.push_back(new button("buttonOptions",Panel::PSETTINGS,2,sf::Vector2i(0,0),"images/BoutonOptionR.png","images/BoutonOptionV.png"));
    buttons.push_back(new button("buttonAbout",Panel::PABOUT,2,sf::Vector2i(0,150),"images/BoutonAPR.png","images/BoutonAPV.png"));
    //buttons.push_back(new button("buttonSettings",Panel::PMENU,2,sf::Vector2i(0,150),"images/bouton1.png","images/bouton2.png"));
    //background.loadFromFile("images/fond-Menu.jpg");
    //image.setTexture(background);

    if(!backgroundTexture.loadFromFile("images/fond-Menu.jpg")){
        qDebug()<<"Fichier n'existe pas";
        }else{
            rBackground.setTexture(&backgroundTexture);


            rBackground.setSize(sf::Vector2f(mainWindow->getSize().x,mainWindow->getSize().y));
            rBackground.setOrigin(sf::Vector2f(mainWindow->getSize().x/2,mainWindow->getSize().y/2));

            rBackground.setPosition(0,0);
        }

}
PWelcome::PWelcome(const PWelcome& b){

    this->buttons=b.buttons;

}

PWelcome& PWelcome::operator=(const PWelcome& b){
    if(!(&b==this)){

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

    mainWindow->draw(rBackground);


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

