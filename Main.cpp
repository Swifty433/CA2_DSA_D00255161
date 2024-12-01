#include "TreeMap.h"
#include <iostream>
#include "..\CA2_DSA_D00255161\FileReader.h"


int main()
{
	FileReader fileReader;
	string filePath = "C:\\Users\\josep\\Downloads\\VideoGames.csv";
	vector<VideoGames> videoGames = fileReader.readCSV(filePath);

	fileReader.printData(videoGames);
	return 0;
}