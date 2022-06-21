#include "header.h"
#include <iostream>
using std::cout;
using std::endl;

void printResult(double minPathSum, vector<vector<Train>> shortestPath, vector<double> PathSum, bool byCost) {
	if (byCost)
		cout << "Minimal cost: " << minPathSum << endl;
	else
		cout << "Minimal time: " << secToData(minPathSum) << endl;
	for (int i = 0, j = 1; i < shortestPath.size(); i++) {
		if (PathSum[i] > minPathSum) continue;
		cout << j++ << ". " << shortestPath[i][0].getArrivalStation() << " -> " << shortestPath[i][shortestPath[i].size() - 1].getDepartureStation() << endl;
		for (int j = 0; j < shortestPath[i].size(); j++) {
			cout << shortestPath[i][j].getNumber() << "\t" << shortestPath[i][j].getDepartureStation() << "\t" << shortestPath[i][j].getArrivalStation() << "\t"
				<< shortestPath[i][j].getCost() << "\t" << shortestPath[i][j].getDepartureTime() << "\t" << shortestPath[i][j].getArrivalTime() << endl;
		}
	}
}
