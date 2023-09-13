#include "VideoGame.h"
#include "text.h"

VideoGame::VideoGame(Text* title, Text* developer, Text* publisher, int year)
{
    this->title = title;
    this->developer = developer;
    this->publisher = publisher;
    this->year = year;
}

VideoGame::~VideoGame()
{
    delete title;
    delete developer;
    delete publisher;

    cout << "VideoGame destructor: Released memory for VideoGame object." << endl;
}