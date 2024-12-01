#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "..\CA2_DSA_D00255161\TreeMap.h"
#include "..\CA2_DSA_D00255161\VideoGames.h"

using namespace std;

class FileReader {

public:
	vector<VideoGames> readCSV(const string& filePath);
	void printData(const vector<VideoGames>& data);
};