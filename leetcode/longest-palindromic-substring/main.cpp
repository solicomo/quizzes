// g++ -std=c++11 -o test main.cpp
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "longest-palindromic-substring.cpp"

int main(int argc, char* argv[])
{
	string s(argv[1]);

	Solution sol;

	cout << sol.longestPalindrome(s) << endl;

	return 0;
}
