#include "panel.h"

int Panel::activeP =0;
int Panel::activeLevel=3;

Panel::Panel(sf::RenderWindow* window)
{
    mainWindow = window;
}

Panel::Panel(const Panel& b){

    this->mainWindow = b.mainWindow;

}

Panel& Panel::operator=(const Panel& b){
    if(!(&b==this)){

        this->mainWindow = b.mainWindow;
    }
    return *this;
}


Panel::~Panel()
{

}

/*Méthode qui gère les boutons lorsque ceux-ci sont activés*/
Panel::mouseClicked(button *btn){
    if(btn->isSelected(worldPos.x,worldPos.y))
    {

        btn->changeTexture(true);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            se->playClick();
            if(btn->getName()!="buttonPlay")
            {
                setActiveP(btn->getTodo());
            }else{
                setActiveP(getActiveLevel());

                if(getActiveLevel()==PLEVEL1)
                {
                    se->goMusic("music/level1.ogg");
                }
                 else if(getActiveLevel()==PLEVEL2)
                {
                     se->goMusic("music/level2.ogg");
                }
                else if(getActiveLevel()==PLEVEL2)
                {
                     se->goMusic("music/level3.ogg");
                }
            }



    }else{
        btn->changeTexture(false);
    }
}
}


