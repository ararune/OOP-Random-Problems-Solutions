#include <iostream>
#include <string>
using std::string;
using std::cout;

// given a string where vowels are replaced by stars, replace stars with original vowels contained in a string
void replaceStar(string& str1, string& vowels) {
	int i = 0;
	size_t pos = 0;
	while ((pos = str1.find('*')) != string::npos) {
		str1.replace(pos, 1, 1, vowels[i]);
		++i;
	}
}

int main()
{
	string str1 = "h*ll* w*rld";
	string vowels = "eoo";

	replaceStar(str1, vowels);
	cout << "New string : " << str1;

}