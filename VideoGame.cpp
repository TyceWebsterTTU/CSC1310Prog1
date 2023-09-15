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
    cout<<setw(34)<<right<<"\nGame Title:"<<left<<"\t";
    title->displayText();
    cout<<setw(34)<<right<<"\nDeveloper:"<<left<<"\t";
    developer->displayText();
    cout<<setw(34)<<right<<"\nPublisher:"<<left<<"\t";
    publisher->displayText();
    cout<<setw(34)<<right<<"\nYear Released:"<<left<<"\t";
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
    outFile << year << endl;
    /*string name;
    cout<<"\nWhat do you want to name this file?";
    getline(cin,name);

    outFile.open(name);
    if(!outFile.is_open())
    {
        cout<<"How did you manage this?";
        return;
    }
    outFile<<title->getText()<<"\n"<<developer->getText()<<"\n"<<publisher->getText()<<"\n"<<year<<endl;
    outFile.close();*/
}

Text* VideoGame::getVideoGameTitle() const
{
    return title;
}