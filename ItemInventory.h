/**
 * Write a description of class ItemInventory here.
 *
 * @author Joshua Decker
 * @version 0.01.04
 */

#pragma once
#include "Levels.h"
#include "Item.h"
#include <vector>
using namespace std;


class ItemInventory : public Levels
{
private:
    int inventoryCapacity = 20;
    int inventoryHas = 0;
    vector<Item> inv;
    Item empty = Item();

public:
    ItemInventory()
    {
        for(int i = 0; i < inventoryCapacity; i++)
        {
            inv[i] = empty;
        }
    }

    void addItem(Item newWep)
    {
        if(inventoryHas < inventoryCapacity)
        {
            inv[inventoryHas] = newWep;
            inventoryHas ++;
        }
        else
        {
            Writer::println("Your item inventory is full.");
        }
    }
    
    vector<Item> getInventory()
    {
        return inv;
    }
    
    int getCapacity()
    {
        return inventoryCapacity;
    }
    
    int getHowFull()
    {
        return inventoryHas;
    }
};
