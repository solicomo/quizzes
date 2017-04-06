// compile:
//   g++ -std=c++11 -o test main.cpp
// 
// usage:
//   ./test T c1 c2 c3 ...
//
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#include "combination-sum.cpp"

int main(int argc, char* argv[])
{
	int t = atoi(argv[1]);
	vector<int> nums;

	for (int i = 2; i < argc; ++i) {
		nums.push_back(atoi(argv[i]));
	}

	Solution sol;

	auto sets = sol.combinationSum(nums, t);

	for (auto& s : sets) {
		for (auto n : s) {
			cout << n << ", ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}

