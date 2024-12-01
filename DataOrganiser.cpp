#include "..\CA2_DSA_D00255161\DataOrganiser.h"
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

void DataOrganiser::createIndex(const vector<VideoGames>& data,
	const string& field)
{
	map<string, int> index;
	for (const auto& game : data)
	{
		string key;
		if (field == "name")
		{
			key = game.getGameName();
		}
		else if(field == "genre")
		{
			key = game.getGenre();
		}
		else if (field == "year")
		{
			key = to_string(game.getReleaseYear());
		}
		else if (field == "rating")
		{
			key = to_string(game.getUserRating());
		}
		else if (field == "multiplayer")
		{
			key = game.getIsMultiplayer() ? "true" : "false";
		}
		else
		{
			cout << "Invalid Field\n";
			return;
		}
		index[key]++;
	}

	/*cout << "Index for field: " << field << endl;
	for (const auto& [key, count] : index) {
		cout << key << ": " << count << " entries\n";
	}*/

	cout << "Index for field: " << field << endl;
	for (const auto& entry : index) { // Use `entry` to avoid key ambiguity
		cout << entry.first << ": " << entry.second << " entries\n";
	}
}

void DataOrganiser::viewSubset(const vector<VideoGames>& data, const string& field, const string& value)
{
	cout << "Filtered Data for " << field << " = " << value << ":\n";
	bool found = false;

	for (const auto& game : data) {
		if ((field == "name" && game.getGameName() == value) ||
			(field == "genre" && game.getGenre() == value) ||
			(field == "year" && to_string(game.getReleaseYear()) == value) ||
			(field == "rating" && to_string(game.getUserRating()) == value) ||
			(field == "multiplayer" && (game.getIsMultiplayer() ? "true" : "false") == value)) {
			cout << game << endl;
			found = true;
		}
	}

	if (!found) cout << "No matching records found.\n";
}
