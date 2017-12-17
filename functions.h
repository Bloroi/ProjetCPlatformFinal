#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "platform.h"
#include "enemy.h"
#include <istream>
#include <ostream>
#include <fstream>
#include <SFML/Audio.hpp>
#include <QFileInfo>
#include <QDebug>

using namespace std;

ostream& operator<<(ostream& os, const Platform& p);
//istream& operator>>(istream& is, Platform& p);
void readPlatform(vector<Platform>& platforms,string filepath);
void readennemy(vector<Enemy*>& enemies,string filepath);


#endif // FUNCTIONS_H
