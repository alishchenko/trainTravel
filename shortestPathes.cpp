#include <algorithm>
#include <iostream>
#include "header.h"

void hamiltonWays(int key, map<int, vector<int>>* stations, vector<int> way, vector <vector<int>>* ways) {
	way.push_back(key);
	if (way.size() == stations->size()) {
		(*ways).push_back(way);
		return;
	}
	for (int i = 0; i < (*stations)[key].size(); i++) {
		if (find(way.begin(), way.end(), (*stations)[key][i]) == end(way)) {
			hamiltonWays((*stations)[key][i], stations, way, ways);
		}
	}
}

void theShortestPaths(vector<vector<vector<Train>>> trainMatrix, vector <vector<int>>* ways, int i, vector<Train> path, map<int, int>* stationsNamesIndexes,
	double sum, vector<vector<Train>>* shortestPath, vector <double>* PathSum, double* minPathSum, bool byCost) {
	// if we don't use stationsNamesIndexes we need to code this:
	//vector<Train> cell = trainMatrix[find(stationsNames.begin(), stationsNames.end(), ways[i][path.size()]) - stationsNames.begin()]
	//								[find(stationsNames.begin(), stationsNames.end(), ways[i][path.size() + 1]) - stationsNames.begin()]; 
	vector<Train> cell = trainMatrix[(*stationsNamesIndexes)[(*ways)[i][path.size()]]][(*stationsNamesIndexes)[(*ways)[i][path.size() + 1]]];
	for (auto train = cell.begin(); train != cell.end(); train++) {

		if (byCost) sum += train->getCost();
		else sum += train->getTravelTime();

		if (sum <= *minPathSum) {
			path.push_back(*train);
			if (path.size() < stationsNamesIndexes->size() - 1) {
				theShortestPaths(trainMatrix, ways, i, path, stationsNamesIndexes, sum, shortestPath, PathSum, minPathSum, byCost);
			}
			else {
				if (sum <= *minPathSum) {
					(*shortestPath).push_back(path);
					(*PathSum).push_back(sum);
					*minPathSum = sum;
				}
			}
			path.pop_back();
		}

		if (byCost) sum -= train->getCost();
		else sum -= train->getTravelTime();
	}
}

vector<vector<vector<Train>>> getTrainMatrix(vector<Train>* trains, bool byCost, vector<int>* stationsNames) {
	vector<vector<vector<Train>>> trainMatrix;
	for (int i = 0; i < stationsNames->size(); i++) {
		vector<vector<Train>> row;
		for (int j = 0; j < stationsNames->size(); j++) {
			vector<Train> allWays, cell;
			copy_if((*trains).begin(), (*trains).end(), 
				back_inserter(allWays), [a = (*stationsNames)[i], b = (*stationsNames)[j]](Train tr) {return tr.getArrivalStation() == a && tr.getDepartureStation() == b; });
			if (allWays.size() > 0) {
				double min;
				if (byCost) {
					min = min_element(allWays.begin(), allWays.end(), ByCost)->getCost();
					copy_if(allWays.begin(), allWays.end(), back_inserter(cell), [min](Train tr) {return tr.getCost() == min; });
				}
				else {
					min = min_element(allWays.begin(), allWays.end(), ByTime)->getTravelTime();
					copy_if(allWays.begin(), allWays.end(), back_inserter(cell), [min](Train tr) {return tr.getTravelTime() == min; });
				}
				row.push_back(cell);
			}
			else
				row.push_back(allWays);
		}
		trainMatrix.push_back(row);
	}
	return trainMatrix;
}