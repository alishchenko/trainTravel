#include <iostream>
#include "header.h"

int main()
{
	string fname = "test_task_data.csv";
	vector<Train> trains;	// all Trains
	vector<int> way;
	vector <vector<int>> ways;
	vector<int> stationsNames;
	map<int, int> stationsNamesIndexes;

	map<int, vector<int>> stations = parseString(readFile(fname), &trains, &stationsNames, &stationsNamesIndexes);

	for (auto station = stations.begin(); station != stations.end(); station++)
		hamiltonWays(station->first, &stations, way, &ways);

	if (ways.size() == 0) {
		std::cout << "There aren't any paths :(";
		return 0;
	}

	vector<vector<vector<Train>>> trainMatrix = getTrainMatrix(&trains, true, &stationsNames);
	vector<Train> path;
	vector<vector<Train>> shortestPath;
	vector<double> PathSum;
	double minPathSum = INT_MAX;
	for (int i = 0; i < ways.size(); i++)
		theShortestPaths(trainMatrix, &ways, i, path, &stationsNamesIndexes, 0, &shortestPath, &PathSum, &minPathSum, true);
	printResult(minPathSum, shortestPath, PathSum, true);
	std::cout << "===================================" << std::endl;

	trainMatrix = getTrainMatrix(&trains, false, &stationsNames);
	path.clear();
	shortestPath.clear();
	PathSum.clear();
	minPathSum = INT_MAX;
	for (int i = 0; i < ways.size(); i++)
		theShortestPaths(trainMatrix, &ways, i, path, &stationsNamesIndexes, 0, &shortestPath, &PathSum, &minPathSum, false);

	printResult(minPathSum, shortestPath, PathSum, false);
	system("pause");
	return 0;
}