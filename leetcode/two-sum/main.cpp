// g++ -std=c++11 -o test main.cpp
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

#include "two-sum.cpp"

int main(int argc, char* argv[])
{
	vector<int> nums;
	int target = atoi(argv[1]);

	for (int i = 2; i < argc; ++i)
	{
		nums.push_back(atoi(argv[i]));
	}

	Solution sol;

	auto ret = sol.twoSum(nums, target);

	if (ret.empty())
	{
		cerr << "got nothing." << endl;
		return 1;
	}

	cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;

	return 0;
}
