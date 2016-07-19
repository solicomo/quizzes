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

		vector<int> nv = nums;

		sort(nv.begin(), nv.end());

		for (auto b = nv.begin(), e = --nv.end(); b != e; )
		{
			auto m = *b;
			auto n = *e;
			auto sum = m + n;

			if (sum < target)
				b++;
			else if (sum > target)
				e--;
			else
			{
				int another;
				int i = 0;

				for ( ; i < len; ++i)
				{
					if (nums[i] == m)
					{
						another = n;
						break;
					}
					else if (nums[i] == n)
					{
						another = m;
						break;
					}
				}

				int j = i + 1;

				for ( ; j < len; ++j)
				{
					if (nums[j] == another)
					{
						return {i,j};
					}
				}
			}
		}

		return {};
	}
};

