#include "soundengine.h"

SoundEngine* SoundEngine::instance = 0;

/**
 * @brief SoundEngine::SoundEngine Classe permettant de gérer le son du jeu (singleton)
 */
SoundEngine::SoundEngine()
{

    if(!SBclick.loadFromFile("music/click.wav")){

       }
       Sclick.setBuffer(SBclick);

    if(!SBpickItem.loadFromFile("music/coin.wav")){
       }
       SpickItem.setBuffer(SBpickItem);


     if(!SBjump.loadFromFile("music/jump.wav")){
       }
      Sjump.setBuffer(SBjump);

      if(!SBcongrats.loadFromFile("music/congrats.wav")){
        }
       Scongrats.setBuffer(SBcongrats);

       if(!SBouch.loadFromFile("music/ouch.wav")){
         }
        Souch.setBuffer(SBouch);



}

SoundEngine::SoundEngine(const SoundEngine &s)
{

}

SoundEngine::~SoundEngine()
{

}

/**
 * @brief SoundEngine::getInstance Méthode envoyant l'instance si demandé , permettant de créer qu'un seul objet
 * de ce type
 * @return instance de l'objet SoundEngine
 */
SoundEngine* SoundEngine::getInstance()
{
    if(instance==0)
    {
        instance = new SoundEngine;
    }
    return instance;
}

/**
 * @brief SoundEngine::goMusic Cette méthode permet de lancer une seule et unique musique à la fois
 * @param filepath
 */
SoundEngine::goMusic(string filepath)
{
    if(filepath!=currentMusic || music.getStatus()==sf::Music::Paused){

    if(music.getStatus()==sf::Music::Playing)
    {
        music.stop();

    }


    if(!music.openFromFile(filepath)){

        }
        music.play();
        music.setLoop(true);
        currentMusic = filepath;

    }
}

/**
 * @brief SoundEngine::goMusic Méthode permettant de relancer la musique
 */
SoundEngine::goMusic()
{
    music.play();
}

/**
 * @brief SoundEngine::pauseMusic Méthode mettant en pause la musique
 */
SoundEngine::pauseMusic()
{
    music.pause();
}

/**
 * @brief SoundEngine::stopMusic méthode permettant d'arrêter la musique
 */
SoundEngine::stopMusic()
{
    music.stop();
}

/**
 * @brief SoundEngine::setVolume Méthode permettant de gérer le volume
 * @param vol
 */
SoundEngine::setVolume(int vol)
{
    music.setVolume(vol);
}

//Les méthodes suivantes permettent de jouer les différents sons du jeu

SoundEngine::playClick()
{
    Sclick.play();
}
SoundEngine::playPickItem()
{
    SpickItem.play();
}
SoundEngine::playJump()
{
    Sjump.play();
}

SoundEngine::playCongrats()
{
    Scongrats.play();
}
SoundEngine::playOuch()
{
    Souch.play();
}


