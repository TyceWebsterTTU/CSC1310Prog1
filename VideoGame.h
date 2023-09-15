#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "text.h"
using namespace std;

class VideoGame
{
    private:
        Text* title;
        Text* developer;
        Text* publisher;
        int year;
    public:
        VideoGame(Text* title, Text* developer, Text* publisher, int year = 0);
        ~VideoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream &outFile);
        Text* getVideoGameTitle() const;
};

#endif