#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string>
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
        VideoGame(Text* title, Text* developer, Text* publisher, int year);
        ~VideoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream &outFile);
        string getVideoGameTitle();
};

#endif