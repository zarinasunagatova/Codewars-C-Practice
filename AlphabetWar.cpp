#include <string>
#include <iostream>
#include <unordered_map>
/*
The left side letters and their power:

 w - 4
 p - 3
 b - 2
 s - 1
The right side letters and their power:

 m - 4
 q - 3
 d - 2
 z - 1
*/


std::string alphabetWar(const std::string& fight) {
	std::unordered_map<char, std::pair<std::string, int>> power;
	power['w'] = { "left", 4 };
	power['p'] = { "left", 3 };
	power['b'] = { "left", 2 };
	power['s'] = { "left", 1 };
	power['m'] = { "right", 4 };
	power['q'] = { "right", 3 };
	power['d'] = { "right", 2 };
	power['z'] = { "right", 1 };

	int left = 0;
	int right = 0;
	std::string::iterator it;
	std::string f = fight;
	for (it = f.begin(); it != f.end(); it++) {
		if (*it == '*') {
			if (it != f.begin() && *(it - 1) != '*') {
				*(it - 1) = '_';
			}
			if (it + 1 != f.end() && *(it + 1) != '*') {
				*(it + 1) = '_';
			}
		}
	}
	for (char c : f) {
		if (c == '_') continue;
		auto it = power.find(c);
		if (it != power.end()) {
			if (it->second.first == "left") {
				left += it->second.second;
			}
			else {
				right += it->second.second;;
			}
		}
	}
	if (left > right) return "Left side wins!";
	if (right > left) return "Right side wins!";
	return "Let's fight again!";
}

int main() {
}












