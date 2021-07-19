#pragma once
#include <string>

using namespace std;
namespace game {
    // Represents moods
    enum class Mood {
        Happy,
        Hungry,
        Bored,
        Sick,
        Sad
    };

    // Represents dragon
    class Dragon {
        private:
            const static int MINOR_CHANGE = 5;
            const static int MAJOR_CHANGE = 10;
            
            const static int MAX_HUNGER = 200;
            const static int MIN_HUNGER = 0;
            const static int MAX_BOREDOM = 200;
            const static int MIN_BOREDOM = 0;
            const static int MAX_HEALTH = 200;
            const static int MIN_HEALTH = 0;
            const static int MAX_HAPPINESS = 200;
            const static int MIN_HAPPINESS  = 0;

            // all range 0-200
            int hunger;
            int boredom;
            int health;
            int happiness;

            string name;
            Mood mood;
            /**
             * changeState() advances one action of play on the dragon
             */
            
            virtual int calculateHappiness() const;
            virtual int calculateHealth() const;
        public:
            Dragon(string name);
            /**
             * feed() feeds the dragon, decreasing hunger
             */
            virtual void feed();
            /**
             * play() plays with the dragon, decreasing boredom
             */
            virtual void play();
            /**
             * heal() heals dragon, increasing health
             */
            virtual void heal();
            virtual int getHunger() const;
            virtual int getBoredom() const;
            virtual int getHealth() const;
            virtual int getHappiness() const;
            /**
             * getMood() gets the current mood of the dragon
             * @return Mood A mood representing the current mood of the dragon
             */
            virtual Mood getMood() const;
            virtual string getName() const;
            virtual void changeState();
    };
}