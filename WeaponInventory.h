/**
 * Write a description of class WeaponInventory here.
 *
 * @author Joshua Decker
 * @version 0.01.02
 */
#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"
#include "Writer.h"
#include "Levels.h"

using namespace std;

class WeaponInventory{
private:
    vector<Weapon*> wepInt; // Dynamic inventory using a vector
    int inventoryCapacity;
    int inventoryHas;
    bool wepOn;
    Weapon* inUseWeapon;

public:
    // Constructor
    WeaponInventory() 
        : inventoryCapacity(5), inventoryHas(0), wepOn(false), inUseWeapon(nullptr) {
        wepInt.resize(inventoryCapacity, nullptr);
    }

    // Add a weapon to the inventory
    void addWeapon(Weapon* newWep) {
        if (inventoryHas < inventoryCapacity) {
            wepInt[inventoryHas] = newWep;
            inventoryHas++;
            Writer::println(newWep->getName() + " has been added to your inventory.");
        } else {
            Writer::println("Your weapon inventory is full.");
        }
    }

    // Get inventory array (returns a vector)
    vector<Weapon*> getInventoryArray() const {
        return wepInt;
    }

    // Get the capacity of the inventory
    int getCapacity() const {
        return inventoryCapacity;
    }

    // Get the number of weapons currently in the inventory
    int getHowFull() const {
        return inventoryHas;
    }

    // String representation of how full the inventory is
    string howFull() const {
        return "Your weapon inventory has " + to_string(getHowFull()) + " out of " + to_string(getCapacity()) + " max weapons.";
    }

    // String representation of the inventory
    string toString() const {
        return howFull();
    }

    // Equip a weapon
    void equipWeapon(Weapon* wep) {
        wepOn = true;
        inUseWeapon = wep;
        Writer::println("You have equipped " + wep->getName() + ".");
    }

    // Check if a weapon is equipped
    bool isWepOn() const {
        return wepOn;
    }

    // Get the weapon currently in use
    Weapon* getWepInUse() const {
        return inUseWeapon;
    }
};