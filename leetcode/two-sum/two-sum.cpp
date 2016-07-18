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
		vector<int> ret;
		unordered_map<int, int> nm;

		for (auto i = 0; i < nums.size(); ++i)
		{
			auto it = nm.find(target - nums[i]);

			if (it == nm.end())
			{
				nm[nums[i]] = i;
				continue;
			}

			ret.push_back(it->second);
			ret.push_back(i);
		}

		return ret;
	}
};
