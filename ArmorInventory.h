
/**
 * Alright, I already know this one is going to be a mess. So basically, you can have up to three(3) of each type of armor piece:
 * Helmet, Chestpiece, Gauntlets, Pants, Boots. So the inventory has fifteen(15) spots(0-14), the first three(3) are for helmet,
 * the next three(3) for chestpiece, so on and so forth. So there's gonna have to be some sorting, and lots of gibberish. And, 
 * part of me even wants to make my life difficult by making several arrays within the array?(turns out this is just 
 * what 2d arrays are, so that was actually a great idea) But that might not be necessary.
 *
 * @author Joshua Decker  
 * @version 0.02.00
 */

#pragma once
#include <string>
#include "Armor.h"
#include <vector>
#include "Writer.h"
class ArmorInventory
{
private:
    int bootsHas;
    int numTypes = 5;
    int maxOfType = 3;
    int maxTotal = 15;
    int inventoryHas;
    Armor nType = Armor("Empty", "Null", -1);
    vector<Armor> helmets = {nType, nType, nType};
    int helmetHas;
    vector<Armor> guantlets = {nType, nType, nType};
    int glovesHas;
    vector<Armor> chestpiece = {nType, nType, nType};
    int chestHas;
    vector<Armor> pants = {nType, nType, nType};
    int pantsHas;
    vector<Armor> boots = {nType, nType, nType};
    int bootsHas;
    vector<vector<Armor>> armorInt = 
    {helmets, guantlets,
    chestpiece, pants, boots};

public:
    ArmorInventory()
    {
        
        inventoryHas = 0;
        helmetHas = 0;
        glovesHas = 0;
        chestHas = 0;
        pantsHas = 0;
        bootsHas = 0;

    }
    
    /*
    public void setCapacity(int size)
    {
        int oldCapacity = inventoryCapacity;
        inventoryCapacity = size;
        Item[] oldInventory = armorInt;
        for(int i = 0; i < oldCapacity; i++)
        {
            oldInventory[i] = armorInt[i]; 
        }
        armorInt= new Item[inventoryCapacity];
        for(int i = 0; i < inventoryCapacity; i++)
        {
            armorInt[i] = oldInventory[i]; 
        }
    }*/
    
    /**
     * Adds a given piece of armor to the armor inventory. Each armor type (Helmet, Guantlets, Chestpiece, Pants and Boots) 
     * only has three (3) available slots. If the type in question is full, it does not add the armor and prints that the inventory
     * is full. 
     * @param newArmor
     */
    void addItem(Armor newArmor)
    {
        if(newArmor.getType() == ("helmet"))
        {
            if(helmetHas < maxOfType) 
            {
                helmets[helmetHas] = newArmor;
                helmetHas++;
                inventoryHas++;

            }
            else
            {
                Writer::println("Your " + newArmor.getType() + " inventory is full.");
            }
        }
        if(newArmor.getType() == ("guantlets"))
        {
            if(glovesHas < maxOfType)
            {
                helmets[glovesHas] = newArmor;
                glovesHas++;
                inventoryHas++;
            }
            else
            {
                Writer::println("Your " + newArmor.getType() + " inventory is full.");
            }
        }
        if(newArmor.getType() == ("chestPiece"))
        {
            if(chestHas < maxOfType)
            {
                helmets[chestHas] = newArmor;
                chestHas++;
                inventoryHas++;
            }
            else
            {
                Writer::println("Your " + newArmor.getType() + " inventory is full.");
            }
        }
        if(newArmor.getType() == ("pants"))
        {
            if(pantsHas < maxOfType)
            {
                helmets[pantsHas] = newArmor;
                pantsHas++;
                inventoryHas++;
            }
            else
            {
                Writer::println("Your " + newArmor.getType() + " inventory is full.");
            }
        }
        if(newArmor.getType() == ("boots"))
        {
            if(bootsHas < maxOfType)
            {
                helmets[bootsHas] = newArmor;
                bootsHas++;
                inventoryHas++;
            }
            else
            {
                Writer::println("Your " + newArmor.getType() + " inventory is full.");
            }
        }
        
    }

    
    
    vector<vector<Armor>> getInventory()
    {
        return armorInt;
    }
    
    int getCapacity()
    {
        return maxOfType;
    }
    
    int getHowFull()
    {
        return inventoryHas;
    }

    string toString()
    {
        string wgr = "Your armor inventory has " + to_string(inventoryHas) + " out of " + to_string(maxTotal) + " max pieces of armor.";
        wgr += " \n   -" + to_string(helmetHas) + " out of " + to_string(maxOfType) + " helmets. \n   -" + to_string(chestHas) + " out of " + to_string(maxOfType);
        wgr += " chestpieces. \n   -" + to_string(glovesHas) + " out of " + to_string(maxOfType) + " gloves. \n   -" + to_string(pantsHas) + " out of " + to_string(maxOfType);
        wgr += " pants. \n   -" + to_string(bootsHas) + " out of " + to_string(maxOfType) + " boots.";
        return wgr; 
    }
};
