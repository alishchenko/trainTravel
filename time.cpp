#include <string>

std::string secToData(double sec) {
	int time = sec;
	std::string res = std::to_string(time / (24 * 3600)) + " day";
	(time / (24 * 3600)) == 1 ? res += " " : res += "s ";

	time %= (24 * 3600);
	(time / 3600) >= 10 ? res += std::to_string(time / 3600) : res += "0" + std::to_string(time / 3600);
	res += ":";

	time %= 3600;
	(time / 60) >= 10 ? res += std::to_string(time / 60) : res += "0" + std::to_string(time / 60);
	res += ":";

	time %= 60;
	time >= 10 ? res += std::to_string(time) : res += "0" + std::to_string(time);
	return res;
}

