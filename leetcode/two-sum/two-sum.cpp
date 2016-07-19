//
// 1. Two Sum
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		auto len = nums.size();

		if (len < 2)
			return {};

		int min = nums[0], max = min;

		for (auto n : nums)
		{
			if (n < min)
				min = n;
			else if (n > max)
				max = n;
		}

		int mmin = (target - max > min) ? target - max : min;
		int mmax = (target - min < max) ? target - min : max;
		int nmap[mmax - mmin + 1];
		
		memset(nmap, 0, sizeof(nmap));

		for (auto i = 0; i < len; ++i)
		{
			auto n = nums[i];

			if (n < mmin || n > mmax)
				continue;

			auto j = nmap[target - n - mmin];
			if (j == 0)
				nmap[n - mmin] = i + 1;
			else
				return {j-1, i};
		}

		return {};
	}
};

