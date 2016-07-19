// g++ -std=c++11 -o test main.cpp
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#include "move-zeroes.cpp"

int main(int argc, char* argv[])
{
	vector<int> nums;

	for (int i = 1; i < argc; ++i)
	{
		nums.push_back(atoi(argv[i]));
	}

	for (auto n : nums)
		cout << n << ", ";

	cout << endl;

	Solution sol;

	sol.moveZeroes(nums);

	for (auto n : nums)
		cout << n << ", ";

	cout << endl;

	return 0;
}
