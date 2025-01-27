/**
 * Generates the player, stores pertanent information such as name, class/type, attack information, etc. 
 * The player class is in fact the oldest of all classes in this project, and has changed very little since
 * it's initial creation.
 * 
 * IMPENDING MODIFICATIONS: ARMOR STUFF SIMMILAR TO WHAT YOU DID FOR HAVING AN EQUIPPED WEAPON. GOOD LUCK
 *
 * @author Joshua Decker
 * @version 0.07.23
 */

#pragma once
#include "Levels.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Player : public Levels
{
    //Variables
private:
    string playerName;
    string specialAttackName;
    

    bool isWizard = false;
    bool isSoldier = false;
    bool isAdventurer = false;
    int weaponPower;
    int playerLevel;
    int playerHealth;
    int fullHealth;
    int basicAttackPower;
    int gold;
    int experience;
    int specialDamage;
    
    
public:
    //Constructors:

    //Empty
    Player()
    {
        
    }

    //Name only
    Player(string name)
    {
        playerName = name;
        playerLevel = 1;
        // playerHealth = level * 100;

    }
    
    //Full constructor
    Player(string name, string type, int level, int wealth)
    {
        playerName = name;
        setPlayerClass(type);
        playerLevel = level;
        gold = wealth;
        
    }

    void setPlayerClass(string playerType)
    {
        isAdventurer = false;
        if(playerType == "Wizard")
        {isAdventurer = false;isAdventurer = false;isAdventurer = false;
            isWizard = true;
        }
        else if(playerType == "wizard")
        {
            isWizard = true;
        }
        else if(playerType == "Soldier")
        {
            isSoldier = true;
        }
        else if(playerType == "soldier")
        {
            isSoldier = true;
        }
        else
        {
            isAdventurer = true;
        }
    }

    /**
     * Sets the player's basic attack power. The end value is dependent on player level, 
     * and whether or not a weapon is equipped. 
     * 
     */
    void setBasicAttackPower()
    {
        checkForWep();
        if(playerLevel <= 5)
        {
            basicAttackPower = playerLevel;
        }
        else if(playerLevel > 5 && playerLevel <= 10)
        {
            basicAttackPower = (int)((double)playerLevel * 1.5);
        }
        else if(playerLevel > 10 && playerLevel <= 20)
        {
            basicAttackPower = (int)((double)playerLevel * 2.5);
        }
        else if(playerLevel > 20)
        {
            basicAttackPower = (int)((double)playerLevel * 3);
        }
        
        if(isWeaponEquipped == true)
        {
            basicAttackPower += weaponPower;
        }
    }

    /**
     * Updates the player's total healthbar, just to ensure that we are operating with the correct health measurements.
     * 
     * 
     * */
    void updatePlayerHealth()
    {
        bool resetFull = false;
        if(playerHealth == fullHealth)
        {
            resetFull = true;
        }

        if(playerLevel <= 5)
        {
            fullHealth = (100) + (playerLevel * 10);
        }
        else if(playerLevel > 5 && playerLevel <= 10)
        {
            fullHealth = (250) + (playerLevel * 25);
        }
        else if(playerLevel > 10 && playerLevel <= 20)
        {
            fullHealth = (500) + (playerLevel * 50);
        }
        else if(playerLevel > 20)
        {
            fullHealth = (10000) + (playerLevel * 100);
        }

        if(resetFull == true)
        {
            playerHealth = fullHealth;
        }
        
    }

    //Sets the players max health to a given value
    void setHealthBar(int hp)
    {
        fullHealth = hp;
    }

    //Sets the player's name
    void setName(string name)
    {
        playerName = name;
    }
    
    //Sets the player's level
    void setLevel(int level)
    {
        playerLevel = level;
        setBasicAttackPower();
    }

    //Technically not a setter, but it works like setLevel, except it just adds one level instead of needing a definite value
    void levelUp()
    {
        playerLevel++;
    }

    //Sets the player's quantity of gold
    void setWealth(int wealth)
    {
        gold = wealth;
    }

    //Adds the specifity qunatity of gold to the player's total quantity
    void addWealth(int wealth)
    {
        gold += wealth;
    }

    /**
     * Adds experience towards your levelup. Still missing a method that I'll implement later, which will actually
     * control the level up.
     * @param xp
     */
    void addExperience(int xp)
    {
        experience += xp;
    }


    //Getter Methods
    
    //Returns the player's attack strength as an integer
    int getBasicAttack()
    {
        return basicAttackPower;
    }

    //Returns just the player's type as a string
    string getType()
    {
        if(isWizard == true)
        {
            return "Wizard";
        }
        else if(isSoldier == true)
        {
            return "Soldier";
        }
        else if(isAdventurer == true)
        {
            return "Adventurer";
        }
        else
        {
            return "Adventurer";
        }
    }
    
    //Returns the player's health as an int
    int getHealth()
    {
        return playerHealth;
    }

    int getMaxHealth()
    {
        return fullHealth;
    }
    
    //Returns the player's name as a string
    string getName()
    {
        return playerName;
    }
    
    //Returns the player's level as an integer
    int getLevel()
    {
        return playerLevel;
    }
    
    /**
     * @return (int) Player's quanity of experience points
     */
    int getExperience()
    {
        return experience;
    }

    /**
     * @return (int) Player's quanity of gold
     */
    int getWealth()
    {
        return gold;
    }
    
    //Checks to see if a weapon is equiped. If so, it sets the weaponEquipped flag to true, and sets weaponPower to that of the 
    //equiped weapon. It's kinda messy but whatever. 
    void checkForWep()
    {
        // isWeaponEquipped = wepInv.isWepOn();
        if(isWeaponEquipped == true)
        {
            // Weapon swordInHand = wepInv.getWepInUse();
            // weaponPower = swordInHand.getPower();
        }
    }
    
    //I know this will baloon eventually, but it works great for now
    void specialAttack()
    {
        if(isWizard == true)
        {
            
        }
        else if(isSoldier == true)
        {
            
        }
        else
        {
            
        }
    }

    /**
     * Subtracts the value of damage from the player's health. Does not end the game if health is less than 0.
     * A seperate method/control structure should be implemented to meter player death. 
     * @param damage
     */
    void takeDamage(int damage)
    {
        playerHealth -= damage;
    }
    
    //Let's the player heal
    void heal(int amount)
    {
        playerHealth += amount;
        if(playerHealth >= fullHealth)
        {
            playerHealth = fullHealth;
        }
    }

    //Sets player health to a given integer value
    void setHealth(int hp)
    {
        playerHealth = hp;
    }
    
    /**
     * Provides the player and most pertinent information about the player, inlcuding: name, type, level, and health information.
     * 
     */
    string toString()
    {
        string wgr = "You, " + playerName + " are a level " +  to_string(playerLevel) + " " + playerType + ". You have " + to_string(playerHealth) + " health out of " + to_string(fullHealth) + " remaining.";
        return wgr;
        // if(isWizard == true)
        // {
        //     return "You, " + playerName + " are a level " +
        // }
        // else if(isSoldier == true)
        // {
        //     return "You, " + playerName + " are a level " + playerLevel + " Soldier. You have " + playerHealth + " health out of " + fullHealth + " remaining.";
        // }
        // else
        // {
        //     return "You, " + playerName + " are a level " + playerLevel + " Adventurer. You have " + playerHealth + " health out of " + fullHealth + " remaining.";
        // }
    }
};
/*
                       \jjjjjj|     jjj|                                              /dddddddddd|      
                        \jjjjj|     jjj|                                             dddddddddddd|
                         jjjjj|     jjj|                            _               ddddd/
                         jjjjj|     jjj|                           &&&             ddddd/
                         jjjjj|     jjj|                          }} {{           ddddd/
                         jjjjj|     jjj|                         ]]   [[         ddddd/
       \\\\             jjjjj/      jjj|                        <|     |>       ddddd|
        \\\\           jjjjj/       jjj|                         ]]   [[       dddddd|
         \\\\         jjjjj/        jjj|                          }} {{       ddddddd|
          \\\\       jjjjj/         jjj|                           &&&        ddddddd|
           ----     jjjjj/          jjj|                            !         ddddddd|
                   jjjjj/           jjj|                            @          ddddddd\
                  jjjjj/            jjj|                            #           ddddddd\
                 jjjjj/             jjj|                            $            ddddddd|
                jjjjj/              jjj|                            %            ddddddd/
               jjjjj/               jjj|                                        ddddddd/
              jjjjj/                                      ____                 ddddddd/
             jjjjj/                 /\\\                  dddd\              /ddddddd/
 __________/jjjjj/                 //M\\\                 ddddd\____________/ddddddd/
 \jjjjjjjjjjjjjj/                  \\V///                  dddddddddddddddddddddddd/
  \jjjjjjjjjjjj/                    \///                    dddddddddddddddddddddd/
                        


*/
