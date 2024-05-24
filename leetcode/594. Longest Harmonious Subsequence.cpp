class Solution 
{
public:
    int findLHS(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        map<int, int> st;
        int maxLength = 0;

        for (const int num : nums)
        {
            ++st[num];
        }

        auto itr = st.begin();
        auto itrNext = st.begin();
        ++itrNext;
        while (itrNext != st.end()) 
        {
            if (itrNext->first - itr->first == 1)
            {
                maxLength = max(maxLength, itr->second + itrNext->second);
            }
            ++itr;
            ++itrNext;
        }

        return maxLength;
    }
};

//  https://leetcode.com/problems/longest-harmonious-subsequence/description/
