#include "pmenus.h"

/**
 * @brief PMenus::PMenus superclasse des panels psettings pwelcome et pabout
 * @param window
 */
PMenus::PMenus(sf::RenderWindow* window) : Panel(window)
{
    this->viewMenu = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_MENU,VIEW_MENU));
     arial.loadFromFile("styles/arial.ttf");

}

PMenus::PMenus(const PMenus& b){

    this->viewMenu=b.viewMenu;
    this->arial=b.arial;

}

PMenus& PMenus::operator=(const PMenus& b){
    if(!(&b==this)){

        this->viewMenu=b.viewMenu;
        this->arial=b.arial;
    }
    return *this;
}

/**
 * @brief PMenus::ResizeView Méthode permettant de changer la vue en fonction de la grandeur de la fenêtre
 */
void PMenus::ResizeView()
{
    float aspectRatio = float(mainWindow->getSize().x)/ float(mainWindow->getSize().y);
    viewMenu.setSize(VIEW_MENU * aspectRatio,VIEW_MENU);
    rBackground.setOrigin(mainWindow->getSize().x/2,mainWindow->getSize().y/2);
    rBackground.setSize(sf::Vector2f(mainWindow->getSize()));
}
