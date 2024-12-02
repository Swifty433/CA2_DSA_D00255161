#pragma once
#include <vector>
#include <string>
#include "..\CA2_DSA_D00255161\VideoGames.h"

using namespace std;

class DataOrganiser
{
public:
	//static method that creates an index based on field. Used to quick access data for that field
	static void createIndex(const vector<VideoGames>& data, const string& field);
	//static method to view the subset of videogames data filtered
	//displays all the video games that match the given field
	static void viewSubset(const vector<VideoGames>& data, const string& field, const string& value);
};