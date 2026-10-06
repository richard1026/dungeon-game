#include "Item.h"

Item::Item() {}
Item::Item(string name, int health, int attack, int defense,int hunger,int thurst, int poison) : Object(name, "Item"), health(health), attack(attack), defense(defense),hunger(hunger),thurst(thurst),poison(poison) {}
bool Item::triggerEvent(Object* obj)
{
    Player* player = dynamic_cast<Player*>(obj);
    player->addItem(*this);
    cout << "You've picked up " << this->getName() << endl;
    return true;
}
int Item::getHealth()
{
    return this->health;
}
int Item::getDefense()
{
    return this->defense;
}
int Item::getAttack()
{
    return this->attack;
}
void Item::setHealth(int health)
{
    this->health = health;
}
void Item::setAttack(int attack)
{
    this->attack = attack;
}
void Item::setDefense(int defense)
{
    this->defense = defense;
}
int Item::gethunger() {
    return hunger;
}
int Item::getthurst() {
    return thurst;
}
int Item::getpoison() {
    return poison;
}