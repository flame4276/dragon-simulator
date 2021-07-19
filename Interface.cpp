#include "Interface.h"

using namespace game;
using namespace std;

void Interface::initializeGame() {
    cout << "Welcome to the dragon game!" << endl;
    cout << "Please choose a name for your dragon:" << endl;
    string name;
    cin >> name;
    dragon = make_unique<Dragon>(name);
    cout << endl << endl;
    cout << "Your goal is to raise your dragon " << dragon->getName() << " and enable it to be as happy as possible" << endl;
    cout << "Good luck!" << endl << endl << endl;
}

bool Interface::presentOptions() {
    int option;

    printDragonInfo();
    cout << "What would you like to do? (Enter a number)" << endl;
    cout << "1 - Play with you dragon" << endl;
    cout << "2 - Feed your dragon" << endl;
    cout << "3 - Heal your dragon" << endl;
    cout << "4 - Quit Game" << endl;

    cin >> option;

    switch (option) {
        case 4:
            return false;
            break;
        case 1:
            dragon->play();
            break;
        case 2:
            dragon->feed();
            break;
        case 3:
            dragon->heal();
            break;
    }

    dragon->changeState();

    cout << endl << endl;

    return true;
}

void Interface::printDragonInfo() const {
    string mood = "";

    switch (dragon->getMood()) {
        case Mood::Happy:
            mood = "happy";
            break;
        case Mood::Sad:
            mood = "sad";
            break;
        case Mood::Bored:
            mood = "bored";
            break;
        case Mood::Hungry:
            mood = "hungry";
            break;
        case Mood::Sick:
            mood = "sick";
            break;
    }

    cout << dragon->getName() << " is " << mood << endl;
}