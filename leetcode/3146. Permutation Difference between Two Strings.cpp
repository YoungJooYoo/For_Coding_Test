class Solution {
public:
    int findPermutationDifference(const string& s, const string& t) 
    {
        map<char, int> st1;
        map<char, int> st2;
        
        for (size_t i = 0; i < s.size(); ++i) 
        {
            st1[s[i]] = i;
            st2[t[i]] = i;
        }

        auto itr1 = st1.begin();
        auto itr2 = st2.begin();
        int result = 0;

        while (itr1 != st1.end()) 
        {
            result += abs(itr1->second - itr2->second);
            ++itr1;
            ++itr2;
        }

        return result;
    }
};

// https://leetcode.com/problems/permutation-difference-between-two-strings/
