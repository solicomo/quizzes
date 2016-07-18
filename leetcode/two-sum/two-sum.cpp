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
		vector<pair<int, int> > nm;
		
		auto len = nums.size();

		if (len < 2)
			return ret;

		for (auto i = 0; i < len; ++i)
		{
			nm.push_back(make_pair(nums[i], i));
		}

		sort(nm.begin(), nm.end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool {
				return a.first < b.first;
		});

		for (auto b = nm.begin(), e = --nm.end(); b != e; )
		{
			auto sum = b->first + e->first;

			if (sum < target)
				b++;
			else if (sum > target)
				e--;
			else
			{
				ret.push_back(b->second);
				ret.push_back(e->second);

				return ret;
			}
		}

		return ret;
	}
};
