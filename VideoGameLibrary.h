/*
	Title:  VideoGameLibrary.h
	Author:  Tyce Webster & Isaac Essex
	Date:  9/16/2023
	Purpose:  Create a video game library that creates, stores, and displays user data
*/
//Header libraries
#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

//Libraries used
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//Header file
#include "VideoGame.h"
using namespace std;

//VideoGameLibrary class
class VideoGameLibrary
{
    private: //Private member variables
        VideoGame** videoGamesArray; //Pointer to a array of pointers that points to individual VideoGame objects
        int maxGames;
        int numGames;
    public: //Public member functions
        VideoGameLibrary(int max); //Constructor
        ~VideoGameLibrary(); //Deconstructor
        void resizeVideoGamesArray();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char* fileName);
        void removeVideoGameFromArray();
        void saveToFile(char* fileName);
};

#endif