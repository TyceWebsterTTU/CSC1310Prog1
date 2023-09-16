/*
	Title:  VideoGame.h
	Author:  Tyce Webster & Isaac Essex
	Date:  9/16/2023
	Purpose:  Create a video game library that creates, stores, and displays user data
*/
//Header libraries
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

//User libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//Header file
#include "text.h"
using namespace std;

//VideoGame class
class VideoGame
{
    private: //Private member variables
        Text* title; //Pointer that holds title of video game
        Text* developer; //Pointer that holds developer of video game
        Text* publisher; //Pointer that holds publisher of video game
        int year;
    public: //Public member functions
        VideoGame(Text* title, Text* developer, Text* publisher, int year = 0); //Constructor 
        ~VideoGame(); //Deconstructor
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream &outFile);
        Text* getVideoGameTitle() const; //Accessor function
};

#endif