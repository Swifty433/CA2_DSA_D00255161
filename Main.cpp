#include <iostream>
#include "TreeMap.h"
#include "..\CA2_DSA_D00255161\DataOrganiser.h"
#include "..\CA2_DSA_D00255161\FileReader.h"

using namespace std;

void displayMenu() {
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
	FileReader fileReader;
    DataOrganiser dataOrganiser;
	string filePath = "C:\\Users\\josep\\Downloads\\VideoGames.csv";
	vector<VideoGames> videoGames = fileReader.readCSV(filePath);


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

        switch (choice){
        case 1:
            cout << "Showing all video game data: " << endl;
            fileReader.printData(videoGames);
            break;
        case 2: 
        {
            cout << "Please enter the field to sort by (Name, Genre, Year, Rating, Multiplayer)";
            string field;
            cin >> field;
            dataOrganiser.createIndex(videoGames, field);
            break;
        }
        case 3: 
        {
            cout << "Please enter a field to search by (Name, Genre, Year, Rating, Multiplayer)";
            string field;
            cin >> field;

            cout << "Please enter a value to search for: ";
            string value;
            cin.ignore();
            getline(cin, value);
            dataOrganiser.viewSubset(videoGames, field, value);

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

	return 0;
}