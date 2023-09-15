#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "text.h"

int main()
{
    int input, num;
    char filename[100];

    cout << "How many video games can your library hold?\n";
    cin >> num;
    while(num <= 0)
    {
        cout << "Your library should at least hold one game :/\n";
        cout << "How many video games can your library hold?\n";
        cin >> num;
    }

    VideoGameLibrary* videoGameLibrary = new VideoGameLibrary(num);

    do
    {
        cout << "\nWhat would you like to do?\n";
        cout << "1.  Load video games from file.\n";
        cout << "2.  Save video games to a file.\n";
        cout << "3.  Add a video game.\n";
        cout << "4.  Remove a video game.\n";
        cout << "5.  Display all video games.\n";
        cout << "6.  Remove ALL video games from this Library and end program.\n";
        cout << "CHOOSE 1-6:  ";
        cin >> input;
        while(input < 1 || input > 6)
        {
            cout << "\nThat is not a valid choice.\n";
            cout << "CHOOSE 1-6:  ";
            cin.ignore();
            cin >> input;
        }

        switch(input)
        {
            case 1:
                    cout << "\n\nWhat is the name of the file? (example.txt):  ";
                    cin >> filename;
                    videoGameLibrary->loadVideoGamesFromFile(filename);
                    break;
            case 2:
                    cout << "\n\nWhat do you want to name the file? (example.txt):  ";
                    videoGameLibrary->saveToFile(filename);
                    break;
            case 3:
                    videoGameLibrary->addVideoGameToArray();
                    break;
            case 4:
                    videoGameLibrary->removeVideoGameFromArray();
                    break;
            case 5:
                    videoGameLibrary->displayVideoGames();
                    break;
        }
    } while (input != 6);

    delete videoGameLibrary;

    cout << "\n\nGOODBYE!";
    
    return 0;
}