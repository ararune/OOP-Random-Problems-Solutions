#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// take a vector of strings, reverse all the strings within the vector and then sort it by reversed strings lexicographically

void reverseAndSort(std::vector<std::string>& myStrings)
{
    std::string temp;
    std::cout << "Enter strings, Ctrl+z to end input : " << std::endl;
    while (std::getline(std::cin, temp))
        myStrings.push_back(temp);

    for (auto& s : myStrings)
        reverse(begin(s), end(s));

    sort(myStrings.begin(), myStrings.end());
}
const void printVector(const std::vector<std::string>& myStrings)
{
    for (auto& i : myStrings)
        std::cout << i << ' ' << std::endl;
}

int main()
{
    std::vector<std::string> myStrings;
    reverseAndSort(myStrings);
    printVector(myStrings);
}

