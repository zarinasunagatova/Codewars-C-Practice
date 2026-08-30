#include <iostream>
#include <string>
#include <typeinfo>
#include <regex>

/*createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"*/

std::string createPhoneNumber1(const int arr[10]) {
	std::string answer;
	if (arr == nullptr) return "";
	std::regex pattern(R"([0-9])");
	answer.append("(");
	for (int i = 0; i < 3; i++) {
		if (!std::regex_match(std::to_string(arr[i]), pattern)) return "";
		answer += '0' + arr[i];
	}
	answer.append(") ");
	for (int i = 3; i < 6; i++) {
		if (!std::regex_match(std::to_string(arr[i]), pattern)) return "";
		answer += '0' + arr[i];
	}
	answer.append("-");
	for (int i = 6; i < 10; i++) {
		if (!std::regex_match(std::to_string(arr[i]), pattern)) return "";
		answer += '0' + arr[i];
	}
	return answer;
}

std::string createPhoneNumber2(const int arr[10]) {
	char buf[15];
	snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
}

int main() {
	int m[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	std::cout << createPhoneNumber1(m);
}
