#include "Interface.h"

using namespace game;

int main() {
    Interface interface;
    interface.initializeGame();
    bool continueGame = true;
    while (continueGame) {
        continueGame = interface.presentOptions();
    }
    return 0;
}