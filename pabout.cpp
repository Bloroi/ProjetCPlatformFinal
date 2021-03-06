#include "pabout.h"

/**
 * @brief PAbout::PAbout Panel affichant les "a propos" du jeu
 * @param window
 */
PAbout::PAbout(sf::RenderWindow* window) : PMenus(window)
{

    buttons.push_back(new button("buttonBack",Panel::PWELCOME,2,sf::Vector2i(-240,-210),"images/BoutonRetourR.png","images/BoutonRetourV.png"));

    //About
    ssAbout<<"MERCI D'AVOIR JOUE A NOTRE JEU !!\n\n"
            <<"Jeu realise par ADRIAENS Alexandre,\n"
          <<"CARLIER Logan, SCIOT Celine.\n"
          <<"Etudiants de la HELHa Campus Mons,\n"
         <<"dans le cadre du cours de Mr. V. Altares.";
    lblAbout.setCharacterSize(30);
    lblAbout.setFont(arial);
    lblAbout.setString(ssAbout.str());
    lblAbout.setPosition(sf::Vector2f(-270,-150));

    if(!backgroundTexture.loadFromFile("images/fond-book.png")){
        qDebug()<<"Fichier n'existe pas";
        }else{
            rBackground.setTexture(&backgroundTexture);


            rBackground.setSize(sf::Vector2f(mainWindow->getSize().x,mainWindow->getSize().y));
            rBackground.setOrigin(sf::Vector2f(mainWindow->getSize().x/2,mainWindow->getSize().y/2));

            rBackground.setPosition(0,0);
        }




}

PAbout::PAbout(const PAbout& b){


    this->buttons=b.buttons;

    //about
    this->lblAbout=b.lblAbout;
}

PAbout& PAbout::operator=(const PAbout& b){
    if(!(&b==this)){

        this->buttons=b.buttons;

        //about
        this->lblAbout=b.lblAbout;

    }
    return *this;
}

PAbout::~PAbout(){

}

/*Méthode qui est appelée tout le temps dans le jeu.
 * Sorte de main pour une classe*/
void PAbout::init()
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

   for(int i =0;i<buttons.size();i++)
       mainWindow->draw(buttons.at(i)->getSprite());

   mainWindow->draw(lblAbout);
}

/*Méthode pour permettre de revenir au panel précédent*/
PAbout::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }
}
