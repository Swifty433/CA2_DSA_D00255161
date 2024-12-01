#include "VideoGames.h"

using namespace std;

///default constructor
VideoGames::VideoGames()
	:game_ID(0), gameName("name"), genre("genre"), releaseYear(0), userRating(0.0), isMultiplayer(false) {}

//Paramaterized Constructor
VideoGames::VideoGames(int game_ID, string gameName, string genre, int releaseYear, double userRating, bool isMultiplayer)
	:game_ID(game_ID), gameName(gameName), genre(genre), releaseYear(releaseYear), userRating(userRating), isMultiplayer(isMultiplayer) {}

int VideoGames::getGameID() const
{
    return game_ID;
}

string VideoGames::getGameName() const
{
    return gameName;
}

string VideoGames::getGenre() const
{
    return genre;
}

int VideoGames::getReleaseYear() const
{
    return releaseYear;
}

double VideoGames::getUserRating() const
{
    return userRating;
}

bool VideoGames::getIsMultiplayer() const
{
    return isMultiplayer;
}

void VideoGames::setGameID(int id)
{
    game_ID = id;
}

void VideoGames::setGameName(const string& name)
{
    gameName = name;
}

void VideoGames::setGenre(const string& genreValue)
{
    genre = genreValue;
}

void VideoGames::setReleaseYear(int year)
{
    releaseYear = year;
}

void VideoGames::setUserRating(double rating)
{
    userRating = rating;
}

void VideoGames::setIsMultiplayer(bool multiplayer)
{
    isMultiplayer = multiplayer;
}

ostream& operator<<(ostream& os, const VideoGames& vg) {
    os << "ID: " << vg.getGameID()
        << ", Name: " << vg.getGameName()
        << ", Genre: " << vg.getGenre()
        << ", Year: " << vg.getReleaseYear()
        << ", Rating: " << vg.getUserRating()
        << ", Multiplayer: " << (vg.getIsMultiplayer() ? "Yes" : "No");
    return os;
}