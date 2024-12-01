#include "VideoGames.h"

using namespace std;

//int game_ID;
//string gameName;
//string genre;
//int releaseYear;
//double userRating;
//bool isMultiplayer;

///default constructor
VideoGames::VideoGames()
	:game_ID(0), gameName("name"), genre("genre"), releaseYear(0), userRating(0.0), isMultiplayer(false) {}

//Paramaterized Constructor
VideoGames::VideoGames(int game_ID, string gameName, string genre, int releaseYear, double userRating, bool isMultiplayer)
	:game_ID(game_ID), gameName(gameName), genre(genre), releaseYear(releaseYear), userRating(userRating), isMultiplayer(isMultiplayer) {}