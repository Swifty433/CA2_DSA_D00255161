#pragma once
#include <vector>
#include <string>
#include "..\CA2_DSA_D00255161\VideoGames.h"

using namespace std;

class DataOrganiser
{
public:
	static void createIndex(const vector<VideoGames>& data, const string& field);
	static void viewSubset(const vector<VideoGames>& data, const string& field, const string& value);
};