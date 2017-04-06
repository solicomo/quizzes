//
// 39. Combination Sum
// 
// Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
//
// Note:
//
//   - All numbers (including target) will be positive integers.
//   - The solution set must not contain duplicate combinations.
//
// For example, given candidate set [2, 3, 6, 7] and target 7, 
//
// A solution set is: 
//
//     [
//         [7],
//         [2, 2, 3]
//     ]
// 

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		return doCombinationSum(candidates, candidates.size(), target);
	}

	inline vector<vector<int>> doCombinationSum(vector<int>& candidates, size_t end, int target)
	{
		vector<vector<int>> results;

		for (size_t i = end; i > 0; --i) {
			auto c = candidates[i-1];

			if (c > target) continue;

			if (c == target) {
				vector<int> result;
				result.push_back(c);
				results.push_back(result);
				continue;
			}
			
			auto t = target - c;

			auto rs = doCombinationSum(candidates, i, t);

			for (auto& r : rs) {
				r.push_back(c);
				results.push_back(r);
			}
		}

		return results;
	}
};

