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

	friend ostream& operator<<(ostream& os, const VideoGames& vg);

	//Default Constructor
	VideoGames();

	VideoGames(int game_ID, string gameName, string genre,
		int releaseYear, double userRating, bool isMultiplayer);
	
	int getGameID() const;
	string getGameName() const;
	string getGenre() const;
	int getReleaseYear() const;
	double getUserRating() const;
	bool getIsMultiplayer() const;

	// Setter functions
	void setGameID(int id);
	void setGameName(const string& name);
	void setGenre(const string& genre);
	void setReleaseYear(int year);
	void setUserRating(double rating);
	void setIsMultiplayer(bool multiplayer);

};