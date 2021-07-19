#pragma once
#include <iostream>
#include <memory>
#include "Dragon.h"

using namespace std;
namespace game {
    class Interface {
        private:
            unique_ptr<Dragon> dragon;
        public:
            void initializeGame();
            bool presentOptions();
            void printDragonInfo() const;
    };
}