#include <iostream>
#include <vector>


// transform a vector until all the elements are power of 2 

bool isPower(int n)
{
	return n&(n - 1) != 0;
}

void transformVector(std::vector<int>& numbers) {
	while (find_if(numbers.begin(), numbers.end(), isPower) != numbers.end())
		for (int& n : numbers)
			(n % 2 == 0) ? n /= 2 : n = (n * 3) + 1;
}
int main()
{
	std::vector<int> numbers{ 16, 10, 3, 4, 2, 6, 16};
	transformVector(numbers);
	for (auto& n : numbers)
		std::cout << n << " ";
}
