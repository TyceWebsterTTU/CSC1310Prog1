#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
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
        void displayVideoGames() const;
        void displayVideoGameTitles() const;
        void loadVideoGamesFromFile(const char* fileName);
        void removeVideoGameFromArray();
        void saveToFile(const char* file);
};

#endif