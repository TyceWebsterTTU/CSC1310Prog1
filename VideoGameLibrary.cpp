#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "text.h"

void VideoGameLibrary::resizeVideoGamesArray()
{

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
    delete [] videoGamesArray;

    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << endl;
}