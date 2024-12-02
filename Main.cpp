#include <iostream>
#include "TreeMap.h"
#include "..\CA2_DSA_D00255161\DataOrganiser.h"
#include "..\CA2_DSA_D00255161\FileReader.h"

using namespace std;

void displayMenu() {//main display menu for stage 4
    cout << "=== Video Games List ===" << endl;
    cout << "1. Show all data!" << endl;
    cout << "2. Search by field!" << endl;
    cout << "3. Search by specific!" << endl;
    cout << "4. CLose Application!" << endl;
    cout << "=================" << endl;
    cout << "Enter your choice: ";
}

int main()
{
	FileReader fileReader; //creates an instance of fileread and dataorganiser
    DataOrganiser dataOrganiser;

    //hardcoding filePath(wouldn't work for some reason when i wouldnt)
	string filePath = "C:\\Users\\josep\\Downloads\\VideoGames.csv";
    //read the data from csv file
	vector<VideoGames> videoGames = fileReader.readCSV(filePath);

    //menu for picking which stage
    cout << "=== Main Menu ===" << endl;
    cout << "1. Stage 2 (Doesn't Work)" << endl;
    cout << "2. Stage 4 (Does Work)" << endl;
    cout << "===================" << endl;
    cout << "Enter your choice: ";

    int stageSelect;
    cin >> stageSelect;

    //swtich case to pick what stage you wanted to do
    switch (stageSelect)
    {
    case 1: {
        cout << "This Stage is incomplete!" << endl;
        break;
    }
    case 2:{
        if (videoGames.empty())
        {
            cout << "Cant Load Data." << endl;
            return 1;
        }

        bool isRunning = true;

        while (isRunning)
        {
            displayMenu();
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Showing all video game data: " << endl;
                fileReader.printData(videoGames);
                break;
            case 2:
            {
                    //sort by specific field
                cout << "Please enter the field to sort by (Name, Genre, Year, Rating, Multiplayer)";
                string field;
                cin >> field;
                dataOrganiser.createIndex(videoGames, field);
                break;
            }
            case 3:
            {
                //allow to sort by specific field and value
                cout << "Please enter a field to search by (Name, Genre, Year, Rating, Multiplayer)";
                string field;
                cin >> field;

                cout << "Please enter a value to search for: ";
                string value;
                cin.ignore(); //clears buffer before reading a line of input
                getline(cin, value);//read the full value input with spaces
                dataOrganiser.viewSubset(videoGames, field, value);//view subset matching field and value

                break;
            }
            case 4:
                cout << "Thank you! Goodbye!" << endl;
                isRunning = false;

                break;

            default:
                cout << "Invalid choice, Please input a valid choice" << endl;
                break;
            }
        }
        break;
    }
    default:
        cout << "Invalid choice. Please input a valid choice." << endl;
        break;
    }

	return 0;
}