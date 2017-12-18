#include "psettings.h"

/**
 * @brief PSettings::PSettings Classe Panel permettant d'afficher les options du jeu
 * @param window
 */
PSettings::PSettings(sf::RenderWindow* window) : PMenus(window)
{
    arial.loadFromFile("styles/arial.ttf");
    buttonsS.push_back(new button("buttonBack",Panel::PWELCOME,2,sf::Vector2i(-240,-210),"images/BoutonRetourR.png","images/BoutonRetourV.png"));
    buttonsS.push_back(new button("buttonsSound",Panel::PSETTINGS,2,sf::Vector2i(-50,-100),"images/BoutonMusic.png","images/BoutonMusic.png"));
    ssAbout<<"ON";
    lblAbout.setCharacterSize(30);
    lblAbout.setFont(arial);
    lblAbout.setString(ssAbout.str());
   // lblAbout.setOrigin(lblAbout.getGlobalBounds().width-(mainWindow->getSize().x/4),lblAbout.getGlobalBounds().height);
    lblAbout.setPosition(sf::Vector2f(75,-120));

    if(!backgroundTexture.loadFromFile("images/fond-Option.jpg")){
        qDebug()<<"Fichier n'existe pas";
        }else{
            rBackground.setTexture(&backgroundTexture);


            rBackground.setSize(sf::Vector2f(mainWindow->getSize().x,mainWindow->getSize().y));
            rBackground.setOrigin(sf::Vector2f(mainWindow->getSize().x/2,mainWindow->getSize().y/2));

            rBackground.setPosition(0,0);
        }


}

PSettings::PSettings(const PSettings& b){

}

PSettings& PSettings::operator=(const PSettings& b){

}


PSettings::~PSettings()
{}
/*Méthode qui est appelée tout le temps dans le jeu.
 * Sorte de main pour une classe*/
void PSettings::init()
{

    aspectRatio = float(mainWindow->getSize().x)/float(mainWindow->getSize().y);
    mainWindow->setView(viewMenu);

    mainWindow->draw(rBackground);

    // récupération de la position de la souris dans la fenêtre
   pixelPos = sf::Mouse::getPosition(*mainWindow);

    // conversion en coordonnées "monde"
   worldPos = mainWindow->mapPixelToCoords(pixelPos);

    for(int i =0;i<buttonsS.size();i++)
    {
        mouseClicked(buttonsS[i]);
        if(i=1){
             modifySound(buttonsS[i]);
        }
    }



    keyPressedOnce();



    for(int i =0;i<buttonsS.size();i++)
        mainWindow->draw(buttonsS.at(i)->getSprite());

    mainWindow->draw(lblAbout);
}
/**
 * @brief PSettings::keyPressedOnce Méthode permettant de vérifier si une touche précise est appuyée pour un événement
 */
PSettings::keyPressedOnce(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        setActiveP(Panel::PWELCOME);
    }
}
/**
 * @brief PSettings::modifySound méthode permettant de changer le volume du jeu
 * @param btn le bouton envoyé en paramètre
 */
void PSettings::modifySound(button *btn){
    if(btn->isSelected(worldPos.x,worldPos.y))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            if(lblAbout.getString()=="ON"){
                se->setVolume(0);
                lblAbout.setString("OFF");

            }
            else
            {
                std::cout<<"ps";
                se->setVolume(100);
                lblAbout.setString("ON");
            }

        }
    }
}

