/**
 * Write a description of class Enemy here.
 *
 * @author Joshua Decker
 * @version 0.02.10
 */
#pragma once

#include <string>
using namespace std;
class Enemy
{
public:
    string name;
    string type; // Valid types will likely baloon over time. For now we have monster, human opponent, and boss.
    int level;
    int power;
    int health;
    int maxHealth;


    /**
     * Constructor for objects of class Enemy
     */
    Enemy(const string& name, const string& type, int level)
        : name(name), type(type), level(level)
        {
            determineHealth();
            determinePower();
        }


    //Constructor determinants
    void determinePower() 
    {
        if (type == "monster" || type == "Monster") 
        {
            power = level * 20;
        } 
        else if (type == "human opponent" || type == "Human Opponent" || type == "Human opponent")
        {
            if (level <= 5) 
            {
                power = level;
            } 
            else if (level > 5 && level <= 10) 
            {
                power = (int) ((double) level * 1.5);
            } 
            else if (level > 10 && level <= 20) 
            {
                power = (int) ((double) level * 2.5);
            } 
            else if (level > 20) 
            {
                power = (int) ((double) level * 3);
            }
        }
        if (type == "boss" || type == "Boss") 
        {
            power = level * 50;
        }
    }

    void determineHealth()
    {
        if (type == "monster" || type == "Monster") 
        {
            maxHealth = level * 25;
        } 
        else if (type == "human opponent" || type == "Human Opponent" || type == "Human opponent") 
        {
            if (level <= 5) 
            {
                maxHealth = level * 2;
            } 
            else if (level > 5 && level <= 10) 
            {
                maxHealth = (int) ((double) level * 3);
            } 
            else if (level > 10 && level <= 20) 
            {
                maxHealth = (int) ((double) level * 5);
            } 
            else if (level > 20) 
            {
                maxHealth = (int) ((double) level * 6);
            }
        }
        if (type == "boss" || type == "Boss") 
        {
        maxHealth = level * 1000;
        }

        health = maxHealth;
    }

    //Setters / modifiers

    void setHealth(int health)
    {
        this->health = health;
    }

    void setPower(int power)
    {
        this->power = power;
    }

    void setLevel(int level)
    {
        this->level = level;
    }

    void takeDamage(int damage)
    {
        health -= damage;
    }

    //Getter methods
    int getPower()
     {
        return power;
     }

    int getLevel()
     {
        return level;
     }

    string getType()
     {
        return type;
     }
    
    string getName()
     {
        return name;
     }

    int getHealth()
     {
        return health;
     }

    int getMaxHealth()
     {
        return maxHealth;
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