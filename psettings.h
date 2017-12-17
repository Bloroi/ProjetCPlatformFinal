#ifndef PSETTINGS_H
#define PSETTINGS_H
#include <SFML/Graphics.hpp>
#include <panel.h>
#include <iostream>
#include <sstream>

using namespace std;

class PSettings : public Panel
{
private:
    int activeP=0;
    vector<button*>buttonsS;
    sf::Font arial;
    ostringstream ssAbout;
    sf::Text lblAbout;
public:
    /*FORME CANONIQUE*/
    PSettings(){}
    PSettings(sf::RenderWindow* window);
    PSettings(const PSettings& c);
    ~PSettings();
    PSettings& operator=(const PSettings& e);
    void init();

    //Listeners
    int keyPressedOnce();
    void modifySound(button *btn);

    //Getters
    int getType()const{return 1;}
    //sf::RenderWindow* getWindow() const{return mainWindow;}

};

#endif // PSETTINGS_H
