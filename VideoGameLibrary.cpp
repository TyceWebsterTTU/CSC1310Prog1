#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "text.h"

void VideoGameLibrary::resizeVideoGamesArray()
{
    maxGames=maxGames*2;
    VideoGame** newArry= new VideoGame*[maxGames];
    for(int i=0; i<maxGames; i++)
    {
    *newArry[i]=*videoGamesArray[i];
    delete videoGamesArray[i];
    }
    
    delete [] *videoGamesArray;

}

VideoGameLibrary::VideoGameLibrary(int max)
{
    videoGamesArray = new VideoGame*[max];
    this->numGames = 0;
}

VideoGameLibrary::~VideoGameLibrary()
{
    for(int i = 0; i < numGames; i++)
    {
        delete videoGamesArray[i];
    }
    delete [] *videoGamesArray;

    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << endl;
}

void VideoGameLibrary::addVideoGameToArray()
{
    const char *ti, *de, *pu;
    string t, d, p;
    int y;

    //Recieve user input
    cout<<"\nVideo Game TITLE:  ";
    getline(cin,t);
    cout<<"\nVideo Game DEVELOPER:  ";
    getline(cin,d);
    cout<<"\nVideo Game PUBLISHER:  ";
    getline(cin, p);
    cout<<"\nVideo Game YEAR:  ";
    cin>>y;
    cin.ignore();
    
    //Convert to char arrays
    ti=t.c_str();
    de=d.c_str();
    pu=p.c_str();

    //create Text obj
    Text* title= new Text(ti);
    Text* dev=new Text(de);
    Text* pub=new Text(pu);

    //create VideoGame
    VideoGame* game=new VideoGame(title,dev,pub,y);

    //add to library
    *videoGamesArray[numGames]=*game;

    //check array size
    if(numGames==maxGames){
        resizeVideoGamesArray();
    }

    numGames++;
}

void VideoGameLibrary::displayVideoGames() const
{
    for(int i=0;i<numGames;i++)
    {
        cout<<setw(34)<<"\n--------Video Game "<<i+1<<"--------";
        videoGamesArray[i]->printVideoGameDetails();
    }
}

void VideoGameLibrary::displayVideoGameTitles() const
{
    for(int i=0;i<numGames;i++) 
    {
        cout<<"\nVideo Game "<<i+1<<": ";
        videoGamesArray[i]->getVideoGameTitle()->displayText();
    }
}

void VideoGameLibrary::loadVideoGamesFromFile(const char* fileName) 
{
    string s=fileName;
    ifstream inFile;
    string t,d,p;
    const char *ti,*de,*pu;
    int y;

    inFile.open(fileName);
    if(!inFile.is_open()){
        cout<<"Failed to locate file.";
        return;
    }

    do
    {
        getline(inFile,t);
        ti=t.c_str();

        getline(inFile,d);
        de=d.c_str();

        getline(inFile,p);
        pu=p.c_str();

    } while (!inFile.eof());
}