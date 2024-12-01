#include "..\CA2_DSA_D00255161\FileReader.h"
#include "..\CA2_DSA_D00255161\VideoGames.h"
#include <sstream>

using namespace std;

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
		while (getline(lineStream, cell, ','))
		{

		}
	}
}

