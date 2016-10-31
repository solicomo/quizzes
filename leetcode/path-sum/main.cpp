// g++ -std=c++11 -o test main.cpp
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

#include "bin_tree.cpp"
#include "path-sum.cpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "usage: " << argv[0] << " SUM tree-nodes " << endl;
		cout << "       dot -Tsvg -o test.svg test.dot" << endl;
		return 1;
	}

	int sum = atoi(argv[1]);

	vector<int> nums;
	for (int i = 2; i < argc; ++i)
	{
		if (string(argv[i]) == "null")
			nums.push_back(INT_MAX);
		else
			nums.push_back(atoi(argv[i]));
	}

	TreeNode* root = NULL;

	create_tree(root, nums);
	tree2dot(root, "test.dot");

	Solution sol;

	auto ret = sol.hasPathSum(root, sum);

	tree2dot(root, "result.dot");

	cout << (ret ? "true" : "false") << endl;

	return 0;
}
