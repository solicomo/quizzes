//
// 283. Move Zeroes
// 
// Given an array nums, write a function to move all 0's to the end of it 
// while maintaining the relative order of the non-zero elements.
//
// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
// 
// Note:
//   1. You must do this in-place without making a copy of the array.
//   2. Minimize the total number of operations.
// 

class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		size_t i = 0;

		for ( ; i < nums.size() && nums[i] != 0; ++i)
			; // do nothing

		for (auto j = i + 1; j < nums.size(); ++j)
		{
			if (nums[j] != 0)
			{
				nums[i] = nums[j];
				nums[j] = 0;
				i++;
			}
		}
	}
};

