/**
 * OKAY, SO I JUST RANTED ABOUT THIS IN THE ARMOR CLASS, BUT ESSENTIALLY, IN ORDER TO CREATE DIVERSE AND INTERESTING WEAPONS I AM
 * GOING TO HAVE TO CREATE A LOT OF CRAP THAT I DON'T WANT TO. NOW IN REALITY, AS I MAKE WEAPONS, I THINK I COME BACK AND ADD THEM
 * ONE AT A TIME. WHICH ISN'T SO BAD. 
 *
 * @author Joshua Decker
 * @version 0.01.10
 */

#include <iostream>
#include <string>
using namespace std;

class Weapon {
private:
    int level;
    string name;
    int power;
    string type;

    void setWepPower() {
        power = level * 10;
        if (name == "The Sword of the South") {
            if (level >= 42) {
                power = 1000000;
            }
        }
    }

public:
    // Constructor
    Weapon(string name, string type, int level) : name(name), type(type), level(level) {
        setWepPower();
    }

    // Getter methods
    int getLevel() const {
        return level;
    }

    string getName() const {
        return name;
    }

    string getType() const {
        return type;
    }

    int getPower() const {
        return power;
    }

    // Methods to modify the weapon
    void addLevels(int addLevel) {
        level += addLevel;
        setWepPower();
    }

    void setLevel(int newLevel) {
        level = newLevel;
        setWepPower();
    }

    void levelUp() {
        level++;
        setWepPower();
    }

    // ToString equivalent
    string toString() const {
        return "Weapon " + name + " is a level " + to_string(level) + " " + type + " with an attack power of " + to_string(power) + ".";
    }
};