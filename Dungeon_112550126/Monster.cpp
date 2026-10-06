#include "Monster.h"
Monster::Monster() : GameCharacter("Monster", 100, 100, 50, 50) {}
Monster::Monster(string name, int maxhealth, int attack, int defense,string type) : GameCharacter(name, maxhealth, maxhealth, attack, defense),type(type) {}
void Monster::printinfo()
{
    cout << getName()<<"'s type is: "<<type << ", current health is: " << getCurrentHealth() << ", attack is: " << getAttack() << ", defense is: " << getDefense() << endl;
}
bool Monster::isdead()
{
    return this->getCurrentHealth() <= 0;
}
bool Monster::triggerEvent(Object* obj)
{
    Player* player = dynamic_cast<Player*>(obj);
    cout << "You've encountered a monster, " << getName() << "." << endl;
    printinfo();
    player->triggerEvent(player);
    cout << "what do you want to do? Attack or retreat?" << endl;
    std::string choice;
    cin >> choice;
    if (choice == "attack")
    {
        cout << "Fight!!!" << endl;
        while (this->getCurrentHealth() > 0 && player->getCurrentHealth() > 0)
        {
            float p = 1, m = 1;
            if (player->gettype() == "grass") {
                if (type == "fire")
                {
                    p = 0.8;
                    cout << "You are countered." << endl;
                }
                else if (type == "grass")
                    p = 1;
                else if (type == "water")
                {
                    p = 1.2;
                    cout << "You counter the monster." << endl;
                }
            }
            else if (player->gettype() == "fire") {
                if (type == "fire")
                    p = 1;
                else if (type == "grass")
                {
                    p = 1.2;
                    cout << "You counter the monster." << endl;
                }
                else if (type == "water")
                {
                    p = 0.8;
                    cout << "You are countered." << endl;
                }
            }
            else if (player->gettype() == "water") {
                if (type == "fire")
                {
                    p = 1.2;
                    cout << "You counter the monster." << endl;
                }
                else if (type == "grass")
                {
                    p = 0.8;
                    cout << "You are countered." << endl;
                }
                else if (type == "water")
                {
                    p = 1;
                }
            }
            if (type == "grass") {
                if (player->gettype() == "fire")
                    m = 0.8;
                else if (player->gettype() == "grass")
                    m = 1;
                else if (player->gettype() == "water")
                    m = 1.2;
            }
            else if (type == "fire") {
                if (player->gettype() == "fire")
                    m = 1;
                else if (player->gettype() == "grass")
                    m = 1.2;
                else if (player->gettype() == "water")
                    m = 0.8;
            }
            else if (type == "water") {
                if (player->gettype() == "fire")
                    m = 1.2;
                else if (player->gettype() == "grass")
                    m = 0.8;
                else if (player->gettype() == "water")
                    m = 1;
            }
            
            int dmg = p*((rand() % 4) + 1) * (player->getAttack() * player->getAttack() / this->getDefense()) / 5;
            cout << "You attacked monster, causing " << dmg << "damages" << endl;
            if (dmg <= getCurrentHealth())
                this->setCurrentHealth(takeDamage(dmg));
            else
                this->setCurrentHealth(0);
            this->printinfo();
            
            if (this->isdead())
            {
                cout << "You killed " << this->getName() << ". You got recovery." << endl;
                player->setAttack(player->getAttack() * 1.05);
                if (player->getCurrentHealth() * 1.05 <= player->getMaxHealth())
                {
                    player->setCurrentHealth(player->getCurrentHealth() * 1.05);
                }
                else
                    player->setCurrentHealth(player->getMaxHealth());
                player->setDefense(player->getDefense() * 1.05);
                player->triggerEvent(player);
                system("pause");
                return true;
            }
            else
            {
                dmg = m*((rand() % 4) + 1) * (this->getAttack() * this->getAttack() / player->getDefense())/5;
                cout << "You was attacked by monster, causing " << dmg << " damages" << endl;
                if (rand() % 5 == 0) {
                    cout << this->getName() << " spits venom. You are poisoned." << endl;
                    cout << "state increases: poison + 1" << endl;
                    player->setpoison(player->getpoison() + 1);
                }
                if (dmg <= player->getCurrentHealth())
                    player->setCurrentHealth(player->takeDamage(dmg));
                else
                    player->setCurrentHealth(0);
                player->triggerEvent(player);
            }
        }
        if (player->isdead())
        {
            cout << "You are dead. Game over......" << endl;
            exit(0);
            return false;
        }
        return false;
    }
    else if (choice == "retreat")
    {
        player->changeRoom(player->getPreviousRoom());
        cout << " You are such a loser! You got debuffed!" << endl;
        player->setAttack(player->getAttack() * 0.8);
        player->setCurrentHealth(player->getCurrentHealth() * 0.8);
        player->setDefense(player->getDefense() * 0.8);
        player->triggerEvent(player);
        return true;
    }
    return false;
}
string Monster::gettype() {
    return this->type;
}