#include <string>
#include <iostream>
/*"the-stealth-warrior" gets converted to "theStealthWarrior"*/

std::string to_camel_case(std::string text) {
	if (text.empty()) return "";
	std::string result;
	bool flag = false;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == '-' || text[i] == '_') {
			flag = true;
			continue;
		}
		result +=  flag ? std::toupper(text[i]) : text[i];
		flag = false;
	}
	return result;
}
int main() {
	std::cout << to_camel_case("the-stealth-warrior");
}
