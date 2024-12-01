#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio> 
#include "BinaryTree.h"
#include "TreeMap.h"

using namespace std;

class VideoGames {
private:
	int game_ID;
	string gameName;
	string genre;
	int releaseYear;
	double userRating;
	bool isMultiplayer;

public:
	//Default Constructor
	VideoGames();

	VideoGames(int game_ID, string gameName, string genre,
		int releaseYear, double userRating, bool isMultiplayer);
	

};