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

void VideoGame::printVideoGameDetails()
{
    cout<<"\n\n"<<right<<setw(23)<<"Game Title:"<<left<<"   ";
    title->displayText();
    cout<<"\n\n"<<right<<setw(23)<<"Developer:"<<left<<"   ";
    developer->displayText();
    cout<<"\n\n"<<right<<setw(23)<<"Publisher:"<<left<<"   ";
    publisher->displayText();
    cout<<"\n\n"<<right<<setw(23)<<"Year Released:"<<left<<"   ";
    cout<<year<<endl;
}

void VideoGame::printVideoGameDetailsToFile(ofstream &outFile)
{
    char temp[100];

    strncpy(temp, title->getText(), 100);
    outFile << temp << endl;
    strncpy(temp, developer->getText(), 100);
    outFile << temp << endl;
    strncpy(temp, publisher->getText(), 100);
    outFile << temp << endl;
    outFile << year;
}

Text* VideoGame::getVideoGameTitle() const
{
    return title;
}