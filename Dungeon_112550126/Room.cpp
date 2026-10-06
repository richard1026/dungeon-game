#include "Room.h"
Room::Room() {}
Room::Room(bool isexit, int index,string environment, vector<Object*> objects) : isExit(isexit), index(index),environment(environment), objects(objects) {}
bool Room::popObject(Object* obj)
{
    for (auto i = objects.begin(); i != objects.end(); i++)
    {
        if (*i == obj)
        {
            objects.erase(i);
            return true;
        }
    }
    return false;
}
string Room::getenvironment() {
    return this->environment;
}
void Room::setUpRoom(Room* uproom)
{
    this->upRoom = uproom;
}
void Room::setDownRoom(Room* downroom)
{
    this->downRoom = downroom;
}
void Room::setLeftRoom(Room* leftroom)
{
    this->leftRoom = leftroom;
}
void Room::setRightRoom(Room* rightroom)
{
    this->rightRoom = rightroom;
}
void Room::setIsExit(bool isexit)
{
    this->isExit = isexit;
}
void Room::setIndex(int index)
{
    this->index = index;
}
void Room::setObjects(vector<Object*> objects)
{
    this->objects = objects;
}
bool Room::getIsExit()
{
    return this->isExit;
}
int Room::getIndex()
{
    return this->index;
}
vector<Object*> Room::getObjects()
{
    return objects;
}
Room* Room::getDownRoom()
{
    return this->downRoom;
}
Room* Room::getUpRoom()
{
    return this->upRoom;
}
Room* Room::getLeftRoom()
{
    return this->leftRoom;
}
Room* Room::getRightRoom()
{
    return this->rightRoom;
}