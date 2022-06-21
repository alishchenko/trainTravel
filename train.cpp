#include "header.h"


int Train::dateToSec(string date) {
	return ((date[0] - '0') * 10 + (date[1] - '0')) * 3600 +
		((date[3] - '0') * 10 + (date[4] - '0')) * 60 +
		((date[6] - '0') * 10 + (date[7] - '0'));
}
int Train::setTravelTime(string from, string to) {
	int departure = dateToSec(from);
	int arrival = dateToSec(to);
	return arrival - departure < 0 ? arrival - departure + 24 * 3600 : arrival - departure;
}
Train::Train(const int number, const int departureStation, const int arrivalStation, const double cost, const string departureTime, const string arrivalTime) {
	this->number = number;
	this->departureStation = departureStation;
	this->arrivalStation = arrivalStation;
	this->cost = cost;
	this->departureTime = departureTime;
	this->arrivalTime = arrivalTime;
	this->timeTravel = setTravelTime(departureTime, arrivalTime);
}
bool ByCost( Train a, Train b)
{
	return a.getCost() < b.getCost();
}
bool ByTime(Train a, Train b)
{
	return a.getTravelTime() < b.getTravelTime();
}

