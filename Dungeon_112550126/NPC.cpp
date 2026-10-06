#include "NPC.h"
NPC::NPC() {}
NPC::NPC(string name, string script, vector<Item*> items) : GameCharacter(name, 0, 0, 0, 0), script(script), commodity(items) {}

void NPC::listCommodity()
{
    for (auto i : this->commodity)
    {
        cout << i->getName() << ": health: " << i->getHealth() << ", attack: " << i->getAttack() << ", defense: " << i->getDefense() <<",hunger: "<<i->gethunger()<<",thurst: "<<i->getthurst()<<",poison "<<i->getpoison() << endl;
    }
}
bool NPC::triggerEvent(Object* obj)
{

    Player* player = dynamic_cast<Player*>(obj);
    cout << this->getName()<<": " << this->script << endl;
    cout << "Waht do you want? You can only choose one thing.(Type [nothing] to get nothing.)" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    this->listCommodity();
    cout << "----------------------------------------------------------------------------------" << endl;
    std::string thing;
    cin>>thing;
    if (thing == "nothing")
        return true;
    else
    {
        for (auto i : commodity)
        {
            if (i->getName() == thing)
            {
                i->triggerEvent(player);
                return true;
            }
        }
    }
    return false;
}
void NPC::setScript(string script)
{
    this->script = script;
}
void NPC::setCommodity(vector<Item*> commodity)
{
    this->commodity = commodity;
}
string NPC::getScript()
{
    return this->script;
}
vector<Item*> NPC::getCommodity()
{
    return this->commodity;
}
/*bool NPC::triggerEvent(Object* obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    cout << this->getScript() << endl;
}*/