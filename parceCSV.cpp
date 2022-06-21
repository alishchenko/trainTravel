#include <iostream>
#include <fstream>
#include <sstream>
#include "header.h"

vector<vector<string>> readFile(string fname) {
	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	std::fstream file(fname, std::ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			std::stringstream str(line);

			while (std::getline(str, word, ';'))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		std::cout << "Could not open the file\n";
	return content;
}


map<int, vector<int>> parseString(vector<vector<string>> content, vector<Train>* trains, vector<int>* stationsNames, map<int, int>* stationsNamesIndexes) {
	map<int, vector<int>> stations;
	for (int i = 0; i < content.size(); i++)
	{
		vector<double> row;
		for (int j = 0; j < content[i].size() - 2; j++)
		{
			row.push_back(stod(content[i][j]));
			if (j == 1 || j == 2) {
				if (stations.find(stoi(content[i][j])) == stations.end()) {
					vector<int> arrives;
					stations.insert({ stoi(content[i][j]), arrives });
					(*stationsNames).push_back(stoi(content[i][j]));
					(*stationsNamesIndexes).insert({ stoi(content[i][j]),  stationsNames->size() - 1 });
				}
				if (j == 2 && find(stations[stoi(content[i][1])].begin(), stations[stoi(content[i][1])].end(), stoi(content[i][j])) == stations[stoi(content[i][1])].end()) {
					stations[stoi(content[i][1])].push_back(stoi(content[i][j]));
				}
			}
		}
		Train train(stoi(content[i][0]), stoi(content[i][1]), stoi(content[i][2]), stod(content[i][3]), content[i][4], content[i][5]);
		(*trains).push_back(train);
	}
	return stations;
}
