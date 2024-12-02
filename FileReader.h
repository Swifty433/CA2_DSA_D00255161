#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "..\CA2_DSA_D00255161\TreeMap.h"
#include "..\CA2_DSA_D00255161\VideoGames.h"

using namespace std;

class FileReader { //reads and procceses file

public:
	//reads the data in from a csv file and stroes it in a vector of videogames
	vector<VideoGames> readCSV(const string& filePath);
	//prints the data contained in a vector of video games to the console
	void printData(const vector<VideoGames>& data);
};