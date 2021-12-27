#include <iostream>

using namespace std;

void printName(const std::string& name) {	// takes only objects that have storage if we don't use const
	std::cout << "[lvalue]" << name << std::endl;
}
void printName(std::string&& name) {		// takes only temporary objects
	std::cout << "[rvalue]" << name << std::endl;
}
int main()
{
	std::string firstName = "Joe";
	std::string lastName = "Cock";

	std::string fullName = firstName + " " + lastName;

	printName(fullName);
	printName(firstName + " " + lastName);
}