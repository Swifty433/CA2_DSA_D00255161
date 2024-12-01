#include "..\CA2_DSA_D00255161\FileReader.h"
#include "..\CA2_DSA_D00255161\VideoGames.h"
#include <sstream>

using namespace std;

void FileReader::printData(const vector<VideoGames>& data)
{
	for (const auto& game : data)
	{
		cout << game << endl;
	}
}

vector<VideoGames> FileReader::readCSV(const string& filePath) {
	vector<VideoGames> videoGames;
	ifstream file(filePath);

	if (!file.is_open())
	{
		cerr << "Error cant open file" << filePath << endl;
		return videoGames;
	}

	string line, cell;
	getline(file, line);

	while (getline(file, line))
	{
		stringstream lineStream(line);
		vector<string> row;
		string cell;
		while (getline(lineStream, cell, ','))
		{
			row.push_back(cell);
		}

		if (row.size() < 6) {
			cerr << "Error" << line << endl;
			continue;
		}

		try
		{
			int id = stoi(row[0]);
			string name = row[1];
			string genre = row[2];
			int year = stoi(row[3]);
			double rating = stod(row[4]);
			bool multiplayer = (row[5] == "true");

			videoGames.emplace_back(id, name, genre, year, rating, multiplayer);
		}
		catch (const exception& e)
		{
			cerr << "Error" << line << endl;
		}
	}

	file.close();
	return videoGames;
}

