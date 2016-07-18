//
// 5. Longest Palindromic Substring
//
// Given a string S, find the longest palindromic substring in S. 
// You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
//

class Solution
{
public:
    string longestPalindrome(string s)
	{
		if (s.empty())
			return s;

		preProccess(s);

		size_t mlen = 0;
		size_t mpos = 0;

		size_t max = 0;
		size_t pos = 0;
		size_t len = s.size();
		vector<size_t> rl(len, 0);

		for (size_t i = 0; i < len; ++i)
		{
			size_t j = 0;

			if (i < max)
			{
				j = rl[2*pos -i];
				j = j < max - i ? j : max - i;
			}

			for (j += i; j < len && s[2*i-j] == s[j]; ++j)
			{
				// do nothing
			}

			if (j - 1 > max)
			{
				pos = i;
				max = j - 1;
			}

			j -= i;
			rl[i] = j;

			if (mlen < j)
			{
				mlen = j;
				mpos = i + 1 - j;
			}
		}

		return postProccess(s.substr(mpos, (mlen -1 ) *2 + 1));
    }

	void preProccess(string& s, string::value_type c = '\0')
	{
		for (auto i = 0; i < s.size(); i += 2)
			s.insert(i, 1, c);

		s.append(1, c);
	}

	string postProccess(string s)
	{
		string c;

		for (auto i = 1; i < s.size(); i += 2)
			c += s[i];

		return c;
	}
};
