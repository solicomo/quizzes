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

		auto len = nums.size();

		if (len < 2)
			return ret;

		vector<int> nv = nums;

		sort(nv.begin(), nv.end());

		for (auto b = nv.begin(), e = --nv.end(); b != e; )
		{
			auto sum = *b + *e;

			if (sum < target)
				b++;
			else if (sum > target)
				e--;
			else
			{
				int another;
				size_t i = 0;

				for ( ; i < nums.size(); ++i)
				{
					if (nums[i] == *b)
					{
						ret.push_back(i);
						another = *e;
						break;
					}
					else if (nums[i] == *e)
					{
						ret.push_back(i);
						another = *b;
						break;
					}
				}

				for (i++ ; i < nums.size(); ++i)
				{
					if (nums[i] == another)
					{
						ret.push_back(i);
						return ret;
					}
				}
			}
		}

		return ret;
	}
};

