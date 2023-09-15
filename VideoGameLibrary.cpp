#include "VideoGameLibrary.h"
#include "VideoGame.h"

VideoGameLibrary::VideoGameLibrary(int max)
{
    maxGames = max;
    numGames = 0;
    videoGamesArray = new VideoGame*[maxGames];
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

void VideoGameLibrary::resizeVideoGamesArray()
{
    int max = maxGames * 2;
    cout << "\nResizing videoGamesArray from " << maxGames << " to " << max << ".";
    VideoGame** newArry= new VideoGame*[max];
    for(int i=0; i< numGames; i++)
    {
        newArry[i]=videoGamesArray[i];
    }
    
    delete [] videoGamesArray;
    videoGamesArray = newArry;
    maxGames = max;
}

void VideoGameLibrary::addVideoGameToArray()
{
    if(numGames==maxGames)
    {
        resizeVideoGamesArray();
    }

    char temp[100];
    Text* title;
    Text* dev;
    Text* pub;
    int y;

    //Recieve user input
    cout << "\nVideo Game TITLE:  ";
    cin.ignore();
    cin.getline(temp, 100);
    title = new Text(temp);

    cout << "\nVideo Game DEVELOPER:  ";
    cin.getline(temp, 100);
    dev = new Text(temp);

    cout << "\nVideo Game PUBLISHER:  ";
    cin.getline(temp, 100);
    pub = new Text(temp);

    cout << "\nVideo Game YEAR:  ";
    cin >> y;

    //create VideoGame
    VideoGame* game = new VideoGame(title, dev, pub, y);

    //add to library
    videoGamesArray[numGames] = game;

    //check array size
    if(numGames==maxGames){
        resizeVideoGamesArray();
    }

    numGames++;
}

void VideoGameLibrary::displayVideoGames()
{
    for(int i = 0; i < numGames; i++)
    {
        cout<<"\n\n"<<right<<setw(25)<<" "<<"--------Video Game "<<i+1<<"--------";
        videoGamesArray[i]->printVideoGameDetails();
    }
}

void VideoGameLibrary::displayVideoGameTitles()
{
    Text* gameTitle;

    for(int i = 0; i < numGames; i++) 
    {
        cout<<"\nVideo Game "<<i+1<<": ";
        gameTitle = videoGamesArray[i]->getVideoGameTitle();
        gameTitle->displayText();
    }
}

void VideoGameLibrary::loadVideoGamesFromFile(char* fileName) 
{
    ifstream inFile;
    char temp[100];
    int numGamesFromFile = 0, y;
    Text* title;
    Text* dev;
    Text* pub;
    VideoGame* constructObj;

    inFile.open(fileName);
    
    if(inFile.good())
    {
        inFile.getline(temp, 100);
        while(!inFile.eof())
        {
            title = new Text(temp);
            inFile.getline(temp, 100);
            dev = new Text(temp);
            inFile.getline(temp, 100);
            pub = new Text(temp);
            inFile >> y;
            inFile.ignore();

            constructObj = new VideoGame(title, dev, pub, y);

            if(numGames == maxGames)
            {
                resizeVideoGamesArray();
            }

            videoGamesArray[numGames] = constructObj;

            numGames++;

            cout << endl;
            title->displayText();
            cout << " was added successfully.";

            inFile.getline(temp, 100);
            numGamesFromFile++;
        }

        cout << "\n\n" << numGamesFromFile << " video games were read from the file and added to your VideoGame library.\n";
    }
    else
    {
        cout << "\nSorry, I was unable to open the file.\n";
    }
    
}

void VideoGameLibrary::removeVideoGameFromArray()
{
    int choice, indexRemoved, elementChange;
    Text* gameTitle;

    if(numGames <= 1)
    {
        cout << "There must at least be one game in your library.\n";
    }

    cout << "\n\nChoose from the following video games to remove:\n";
    displayVideoGameTitles();
    cout << "\nChoose a video game to remove between 1 & " << numGames << ":  ";
    cin >> choice;

    while(choice < 1 || choice > numGames)
    {
        cout << "\nInvalid choice, please choose between 1 & " << numGames << ":  ";
        cin >> choice;
    }

    indexRemoved = choice - 1;
    gameTitle = videoGamesArray[indexRemoved]->getVideoGameTitle();

    cout << "\n\nThe video game \"";
    gameTitle->displayText();
    cout << "\" has been successfully deleted.\n\n";

    delete videoGamesArray[indexRemoved];

    elementChange = numGames - 1;

    for(int i = indexRemoved; i < elementChange; i++)
    {
        videoGamesArray[i] = videoGamesArray[i + 1];
    }

    videoGamesArray[elementChange] = NULL;

    numGames--;
}

void VideoGameLibrary::saveToFile(char* fileName)
{
    ofstream outFile;

    outFile.open(fileName);

    for(int i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->printVideoGameDetailsToFile(outFile);
    }

    outFile.close();

    cout << "\nAll video games in your library have been printed to " << fileName << endl;
}