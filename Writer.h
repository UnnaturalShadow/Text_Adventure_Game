#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Wait.h"

using namespace std;

class Writer {
public:
    static bool testing;
    static int speed;

    static void println(const std::string& sentence) {
        setSpeed();
        for (size_t i = 0; i < sentence.length() - 1; ++i) {
            Wait::stall(speed);
            std::cout << sentence[i] << std::flush; // Flush after each character
        }
        std::cout << sentence[sentence.length() - 1] << std::endl;
    }

    static void print(const std::string& sentence) {
        setSpeed();
        for (char ch : sentence) {
            Wait::stall(speed);
            std::cout << ch << std::flush; // Flush after each character
        }
    }

    static void printSlow(const std::string& sentence) {
        for (char ch : sentence) {
            Wait::stall(150);
            std::cout << ch << std::flush; // Flush after each character
        }
    }

    static void printFast(const std::string& sentence) {
        for (char ch : sentence) {
            Wait::stall(10);
            std::cout << ch << std::flush; // Flush after each character
        }
    }

    static void printlnFast(const std::string& sentence) {
        for (size_t i = 0; i < sentence.length() - 1; ++i) {
            Wait::stall(10);
            std::cout << sentence[i] << std::flush; // Flush after each character
        }
        std::cout << sentence[sentence.length() - 1] << std::endl;
    }

    static void wipeScreen() {
#ifdef _WIN32
        system("cls"); // Clear screen for Windows
#else
        system("clear"); // Clear screen for Unix/Linux/MacOS
#endif
    }

private:
    static void setSpeed() {
        speed = testing ? 1 : 60;
    }
};

// Initialize static members
bool Writer::testing = false;
int Writer::speed = 0;

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