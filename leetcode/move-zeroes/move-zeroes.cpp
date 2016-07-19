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
		auto head = nums.data();
		auto tail = head + nums.size();

		for ( ; head < tail && *head != 0; ++head)
			; // do nothing

		auto numt = head;

		while(numt < tail)
		{
			auto numh = numt + 1;

			for ( ; numh < tail && *numh == 0; ++numh)
				; // do nothing

			if (numh == tail)
				break;

			numt = numh + 1;

			for ( ; numt < tail && *numt != 0; ++numt)
				; // do nothing

			memmove(head, numh, sizeof(int) * (numt - numh));

			head += numt - numh;
		}

		if (head < tail)
			memset(head, 0, sizeof(int) * (tail - head));
	}
};

