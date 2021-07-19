#include "Dragon.h"

using namespace game;

void Dragon::changeState() {
    hunger += MINOR_CHANGE;
    if (hunger > MAX_HUNGER) hunger = MAX_HUNGER;

    boredom += MINOR_CHANGE;
    if (boredom > MAX_BOREDOM) boredom = MAX_BOREDOM;

    health = calculateHealth();
    if (health > MAX_HEALTH) health = MAX_HEALTH;
    if (health < MIN_HEALTH) health = MIN_HEALTH;

    happiness = calculateHappiness();
    if (happiness > MAX_HAPPINESS) happiness = MAX_HAPPINESS;
    if (happiness < MIN_HAPPINESS) happiness = MIN_HAPPINESS;

    mood = getMood();
}
int Dragon::calculateHealth() const {
    if (hunger > 150 || hunger < 50) return health-MINOR_CHANGE;
    return health;
}
int Dragon::calculateHappiness() const {
    int newHappiness = happiness;

    if (hunger < 75 || hunger > 125) newHappiness -= MINOR_CHANGE; else newHappiness += MINOR_CHANGE;
    if (boredom > 150) newHappiness -= MINOR_CHANGE; else newHappiness += MINOR_CHANGE;
    if (health < 75) newHappiness -= MINOR_CHANGE; else newHappiness += MINOR_CHANGE;

    return newHappiness;
}

Dragon::Dragon(string name) {
    this->name = name;
    hunger = 75;
    boredom = 100;
    health = 100;
    happiness = 100;
    mood = getMood();
}

void Dragon::feed() {
    hunger -= 20;
    if (hunger < MIN_HUNGER) hunger = MIN_HUNGER;
}
void Dragon::play() {
    boredom -= 20;
    if (boredom < MIN_BOREDOM) boredom = MIN_BOREDOM;
}
void Dragon::heal() {
    health += 20;
    if (health > MAX_HEALTH) health = MAX_HEALTH;
}

int Dragon::getHunger() const {
    return hunger;
}
int Dragon::getBoredom() const {
    return boredom;
}
int Dragon::getHealth() const {
    return health;
}
int Dragon::getHappiness() const {
    return happiness;
}
Mood Dragon::getMood() const {
    if (happiness >= 150) return Mood::Happy;
    if (health < 50) return Mood::Sick;
    if (happiness < 50) return Mood::Sad;
    if (hunger > 125) return Mood::Hungry;
    if (boredom > 125) return Mood::Bored;
    return Mood::Happy;
}
string Dragon::getName() const {
    return name;
}