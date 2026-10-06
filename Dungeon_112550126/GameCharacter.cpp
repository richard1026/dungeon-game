#include "GameCharacter.h"
GameCharacter::GameCharacter() {}
GameCharacter::GameCharacter(string name, int maxhealth, int currenthealth, int attack, int defense) :Object(name, "GameCharacter"), maxHealth(maxhealth), currentHealth(currenthealth), attack(attack), defense(defense) {}
bool GameCharacter::checkIsDead() {
    return (currentHealth > 0);
}
int GameCharacter::takeDamage(int damage) {
    currentHealth -= damage;
    return currentHealth;
}
void GameCharacter::setMaxHealth(int health) {
    this->maxHealth = health;
}
void GameCharacter::setCurrentHealth(int health) {
    this->currentHealth = health;
}
void GameCharacter::setAttack(int attack) {
    this->attack = attack;
}
void GameCharacter::setDefense(int defense) {
    this->defense = defense;
}
int GameCharacter::getMaxHealth() {
    return maxHealth;
}
int GameCharacter::getCurrentHealth() {
    return currentHealth;
}
int GameCharacter::getAttack() {
    return attack;
}
int GameCharacter::getDefense() {
    return defense;
}