#include "item.h"

/**
 * @brief Item::Item classe qui permet de créer des objets items
 * @param size taille de l'item
 * @param pos position de l'item
 * @param filename chemin d'accès de la texture de l'item
 */
Item::Item(sf::Vector2f size,sf::Vector2f pos, string filename){
    item.setSize(size);
    //coin.setFillColor(sf::Color::Yellow);
    item.setPosition(pos);
    sf::Texture *texture = new sf::Texture;

    if(!texture->loadFromFile(filename))
        qDebug()<<"Fichier n'existe pas";


    item.setTexture(texture);
     this->filename = filename;
}
/*Item::Item(const Item& c)
{
  item.setSize(sf::Vector2f(c.getGlobalBounds().width,c.getGlobalBounds().height));

   item.setPosition(c.GetPosition());
    sf::Texture *texture = new sf::Texture;
    if(!texture->loadFromFile("images/sword1.png"))
        qDebug()<<"Fichier n'existe pas";

    item.setTexture(c.texture);
}*/

Item::~Item(){}

/*Méthode qui permet d'afficher l'item*/
void Item::Draw(sf::RenderWindow &window){
    window.draw(item);
}

/**
 * @brief Item::getGlobalBounds méthode permettant de savoir les bors de l'item
 * @return  les bords de l'item en sf::FloatRect
 */
sf::FloatRect Item::getGlobalBounds(){
    return item.getGlobalBounds();
}


void Item::setPos(sf::Vector2f newPos){
    item.setPosition(newPos);
}
