#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// in a given vector, if a is found erase it,if b is found insert 0 after it

void vectorModify(std::vector<int>& v, int a, int b) {
    v.erase(remove_if(v.begin(), v.end(), [a](int el) {return el == a; }), v.end());

	auto it = v.begin();
	while (it != v.end())
	{
		auto rit = find(it, v.end(), b);
		if (rit != v.end())
			it = v.insert(rit + 1, 0);
		else
			break;
	}

}
int main()
{
    std::vector<int> v{ 16, 2, 3, 4, 2, 3 };
    int a = 2;
    int b = 3;
    vectorModify(v, a, b);

    for (auto& i : v)
        std::cout << i << " ";
}

