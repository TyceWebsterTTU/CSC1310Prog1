#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "VideoGame.h"
using namespace std;

class VideoGameLibrary
{
    private:
        VideoGame** videoGamesArray;
        int maxGames;
        int numGames;
    public:
        void resizeVideoGamesArray();
        VideoGameLibrary(int max);
        ~VideoGameLibrary();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char* fileName);
        void removeVideoGameFromArray();
        void saveToFile(char* fileName);
};

#endif