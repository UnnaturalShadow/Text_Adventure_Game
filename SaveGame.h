
/**
 * Write a description of class SaveGame here.
 *
 * @author Joshua Decker; Translated from Java to c++ by ChatGPT v4
 * @version 0.01.09
 */
#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Levels.h"
#include "Player.h"

using namespace std;

class SaveGame : public Levels {
private:
    int atLevel = 0;
    int atPlace = 0;
    int timesSaved = 0;

public:
    int playerWealth = 0;
    std::string playerName = "";
    std::string playerGold = "";
    std::string playerType = "";
    std::string levelPlayer = "";
    int realLevelPlayer = 0;
    Player * player;

    SaveGame(Player* p):player(p){}

    void newSave(int level, int place, int numSaves) {
        int saves = numSaves + 1;
        std::string filePath = "\\Saves\\TAG_Save_" + std::to_string(saves) + ".txt";

        // Create the file
        std::ofstream file(filePath);
        if (!file) {
            std::cerr << "An error occurred while creating the save file." << std::endl;
            return;
        }

        // Write save data
        file << level << " " << place << " " << saves << " "
             << player->getName() << " " << player->getType() << " "
             << player->getLevel() << " " << player->getWealth();
        file.close();

        std::cout << "Successfully saved!" << std::endl;
    }

    //modify this to simply pull the highest number?
    std::string findSave() {
        std::string highestSave;
        std::cout << "What is the most recent save name? ";
        std::cin >> highestSave;

        highestSave = highestSave + ".txt";

        std::ifstream file(highestSave);
        if (!file) {
            std::cerr << "You have no saved games. Please start from the beginning." << std::endl;
            return "";
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();  // Read the entire file into a string
        file.close();

        std::cout << "Save found!" << std::endl;
        return buffer.str();
    }

    int getLevel() const { return atLevel; }
    int getPlace() const { return atPlace; }
    int getNumSaves() const { return timesSaved; }
    std::string getPlayerName() const { return playerName; }
    std::string getPlayerType() const { return playerType; }
    int getPlayerLevel() const { return realLevelPlayer; }
    int getPlayerGold() const { return playerWealth; }

    void pullInfo(const std::string& messyData) {
        std::istringstream stream(messyData);
        std::string level, place, saves, levelPlayerStr, playerGoldStr;

        stream >> level >> place >> saves >> playerName >> playerType >> levelPlayerStr >> playerGoldStr;

        atLevel = std::stoi(level);
        atPlace = std::stoi(place);
        timesSaved = std::stoi(saves);
        realLevelPlayer = std::stoi(levelPlayerStr);
        playerWealth = std::stoi(playerGoldStr);
    }
};