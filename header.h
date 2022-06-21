#ifndef PATH
#define PATH

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;


class Train {
private:
	int number, arrivalStation, departureStation, timeTravel;
	string departureTime, arrivalTime;
	double cost;
	//convert string time (12:34:56) to seconds
	int dateToSec(string date);
	//count travel time
	int setTravelTime(string from, string to);
public:
	Train(const int number, const int departureStation, const int arrivalStation, 
		const double cost, const string departureTime, const string arrivalTime);

	//getters
	int const getNumber() {return number;}
	int const getDepartureStation() {return departureStation;}
	int const getArrivalStation() {return arrivalStation;}
	int const getTravelTime() {return timeTravel;}
	double const getCost() {return cost;}
	string const getDepartureTime() {return departureTime;}
	string const getArrivalTime() {return arrivalTime;}
};

//sortung methods
bool ByCost(Train a, Train b);
bool ByTime(Train a, Train b);

//convert seconds to string time (12:34:56)
string secToData(double sec);

//parse CSV
vector<vector<string>> readFile(string fname);
map<int, vector<int>> parseString(vector<vector<string>> content, vector<Train>* trains, vector<int>* stationsNames, map<int, int>* stationsNamesIndexes);

//Hamilton ways (nit cycles)
void hamiltonWays(int key, map<int, vector<int>>* stations, vector<int> way, vector <vector<int>>* ways);

//for main algorithm
void theShortestPaths(vector<vector<vector<Train>>> trainMatrix, vector <vector<int>>* ways, int i, vector<Train> path, map<int, int>* stationsNamesIndexes,
	double sum, vector<vector<Train>>* shortestPath, vector <double>* PathSum, double* minPathSum, bool byCost);

vector<vector<vector<Train>>> getTrainMatrix(vector<Train>* trains, bool byCost, vector<int>* stationsNames);

//print result
void printResult(double minPathSum, vector<vector<Train>> shortestPath, vector<double> PathSum, bool byCost);

#endif