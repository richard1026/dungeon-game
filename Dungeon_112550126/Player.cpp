#include "Player.h"

Player::Player() {}
Player::Player(string name, int maxhealth, int attack, int defense,int hunger,int thurst,int poison) : GameCharacter(name, maxhealth, maxhealth, attack, defense),hunger(hunger),thurst(thurst),poison(poison) {}
void Player::addItem(Item item)
{
	inventory.push_back(item);
	increaseStates(item.getHealth(), item.getAttack(), item.getDefense(),item.gethunger(),item.getthurst(), item.getpoison());
}

void Player::increaseStates(int health, int attack, int defense,int Hunger,int Thurst,int Poison)
{
	setAttack(getAttack() + attack);
	setDefense(getDefense() + defense);
	setCurrentHealth(getCurrentHealth() + health);
	sethunger(gethunger() + Hunger);
	setthurst(getthurst() + Thurst);
	setpoison(getpoison() + Poison);
}
void Player::changeRoom(Room* newroom)
{
	previousRoom = currentRoom;
	currentRoom = newroom;
	cout << "The environment of this room is " << currentRoom->getenvironment() << endl;
}
bool Player::triggerEvent(Object* obj)
{
	cout << getName() << "'s current health is: " << getCurrentHealth() << ", attack is: " << getAttack() << ", defense is: " << getDefense() << endl;
	return true;
}
void Player::setCurrentRoom(Room* currentroom)
{
	this->currentRoom = currentroom;
}
void Player::setPreviousRoom(Room* previousroom)
{
	this->previousRoom = previousroom;
}
void Player::setInventory(vector<Item> items)
{
	this->inventory = items;
}
Room* Player::getCurrentRoom()
{
	return this->currentRoom;
}
Room* Player::getPreviousRoom()
{
	return this->previousRoom;
}
void Player::printinfo()
{
	cout << getName() << "'s current health is: " << getCurrentHealth() << ", attack is: " << getAttack() << ", defense is: " << getDefense() << endl;
}
bool Player::isdead()
{
	return this->getCurrentHealth() <= 0;
}
void Player::sethunger(int Hunger) {
	if (Hunger < 0)
		this->hunger = 0;
	else
		this->hunger = Hunger;
}
void Player::setthurst(int Thurst) {
	if (Thurst < 0)
		this->thurst = 0;
	else
		this->thurst = Thurst;
}
void Player::setpoison(int Poison) {
	if (Poison < 0)
		this->poison = 0;
	else
		this->poison = Poison;

}
int Player::gethunger() {
	return this->hunger;
}
int Player::getthurst() {
	return this->thurst;
}
int Player::getpoison() {
	return this->poison;
}
vector<Item> Player::getInventory() {
	return this->inventory;
}
void Player::listinventory() {
	if (inventory.size() == 0)
		cout << "There is nothing in your backpack."<<endl;
	else
	{
		cout << "Items in your bag: ";
		for (auto i : inventory) {
			cout << i.getName() << "/";
		}
		cout << endl;
	}
	
}
void Player::settype(string type) {
	this->type = type;
}
string Player::gettype() {
	return this->type;
}