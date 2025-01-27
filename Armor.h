/**
 * AAAAAHAHAHAHAHAHAHHHHHHH THIS IS FRUSTRATING. THIS IS GOING TO BE SUCH A MESS IN THE END. BECUASE, LIKE,
 * SOME ARMOR IS BETTER THAN OTHER ARMOR, AND THERES SPECIAL POWERS AND STUFF, AND ALL OF THAT HAS TO BE PROGRAMMED?
 * NO THANK YOU, THIS IS GONNA SUCK. UGGGHHH. I'M GOING TO DO THIS FOR THE WEAPONS FIRST CAUSE THAT'S MORE FUN. 
 *
 * @author Joshua Decker
 * @version 0.00.10
 */
#pragma once
#include <string>

using namespace std;

class Armor
{
private:
    int level;
    string name;
    int defense;
    string type;

public:

    Armor() : name("Empty"), type("Null"), level(-1) {}

    Armor(const string& name, const string& type, int level)
    : name(name), type(type), level(level)
    {
    
    }


    int getDefense()
    {
        return defense;
    }

    int getLevel()
    {
        return level;
    }
    
    string getName()
    {
        return name;
    }
    
    string getType()
    {
        return type;
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