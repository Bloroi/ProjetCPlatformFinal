#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H
#include <string>
#include <iostream>
#include <QDebug>
#include <QFileInfo>
#include <SFML/Audio.hpp>

using namespace std;


class SoundEngine
{
private:
    SoundEngine();
    static SoundEngine* instance;
    sf::Music music;
    string currentMusic;
    sf::SoundBuffer SBpickItem;
    sf::SoundBuffer SBclick;
    sf::SoundBuffer SBjump;
    sf::SoundBuffer SBcongrats;
    sf::SoundBuffer SBouch;
    sf::Sound SpickItem;
    sf::Sound Sclick;
    sf::Sound Sjump;
    sf::Sound Scongrats;
    sf::Sound Souch;

public:
    SoundEngine(const SoundEngine &s);
    ~SoundEngine();
    static SoundEngine* getInstance();
    goMusic(string filepath);
    goMusic();
    pauseMusic();
    stopMusic();
    setVolume(int vol);
    playClick();
    playPickItem();
    playJump();
    playCongrats();
    playOuch();


};

#endif // SOUNDENGINE_H
