#include "functions.h"
#include <iostream>

using namespace std;


/** Cette méthode permet de lire dans un fichier txt les informations sur les plateformes**/
void readPlatform(vector<Platform>& platforms,string filepath){
    string a,b,c,d,e,f,g;
    float c1,d1,e1,f1;

    std::ifstream infile(filepath);

    getline(infile,a,',');
    getline(infile,b,',');
    getline(infile,c,',');
    getline(infile,d,',');
    getline(infile,e,',');
    getline(infile,f,';');
    getline(infile,g,'\n');

     while (a!=""){

        //std::cout<<a<<"|"<<b<<"|"<<c<<"|"<<d<<"|"<<e<<"|"<<f<<endl;

        c1 = std::stof(c);
        d1 = std::stof(d);
        e1 = std::stof(e);
        f1 = std::stof(f);
        platforms.push_back(Platform(a,b,sf::Vector2f(c1,d1),sf::Vector2f(e1,f1)));

        getline(infile,a,',');
        getline(infile,b,',');
        getline(infile,c,',');
        getline(infile,d,',');
        getline(infile,e,',');
        getline(infile,f,';');
        getline(infile,g,'\n');
     }
}


void readennemy(vector<Enemy*>& enemies,string filepath)
{
    std::cout<<"test1"<<endl;
    string a,b,c,d,e,f,g,h,i,j,k,l;
    int c1,d1,k1;
    float e1,f1,g1,h1,i1,j1;

    std::ifstream infile(filepath);

    getline(infile,a,',');
    getline(infile,b,',');
    getline(infile,c,',');
    getline(infile,d,',');
    getline(infile,e,',');
    getline(infile,f,',');
    getline(infile,g,',');
    getline(infile,h,',');
    getline(infile,i,',');
    getline(infile,j,',');
    getline(infile,k,';');
    getline(infile,l,'\n');
  std::cout<<"test2"<<filepath<<endl;

     while (a!=""){

         std::cout<<"test3"<<endl;

        //std::cout<<a<<"|"<<b<<"|"<<c<<"|"<<d<<"|"<<e<<"|"<<f<<"|"<<g<<"|"<<h<<"|"<<i<<"|"<<j<<"|"<<k<<"|"<<l<<endl;

        c1 = std::stoi(c);
        d1 = std::stoi(d);
        e1 = std::stof(e);
        f1 = std::stof(f);
        g1 = std::stof(g);
        h1  = std::stof(h);
        i1  = std::stof(i);
        j1  = std::stof(j);
        k1 = std::stoi(k);

        std::cout<<"methode"<<a<<"|"<<b<<"|"<<c<<"|"<<d<<"|"<<e<<"|"<<f<<"|"<<g<<"|"<<h<<"|"<<i<<"|"<<j<<"|"<<k<<"|"<<l<<endl;
        enemies.push_back(new Enemy(a,b,sf::Vector2u(c1,d1),sf::Vector2f(e1,f1),sf::Vector2f(g1,h1),i1,j1,k1));

        getline(infile,a,',');
        getline(infile,b,',');
        getline(infile,c,',');
        getline(infile,d,',');
        getline(infile,e,',');
        getline(infile,f,',');
        getline(infile,g,',');
        getline(infile,h,',');
        getline(infile,i,',');
        getline(infile,j,',');
        getline(infile,k,';');
        getline(infile,l,'\n');
     }
}


/** Cette méthode permet d'écrire des plateformes dans un fichier txt**/
ostream& operator<<(ostream& os, const Platform& p)
{
    os <<p.name<<","<<p.filename<<","<<p.body.getSize().x <<","<<  p.body.getSize().y <<","<<p.body.getPosition().x<<","<<p.body.getPosition().y<<";"<<endl;
    return os;
}


