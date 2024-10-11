class Solution {
public:
    int smallestCommonElement(const vector<vector<int>>& mat) 
    {
        const int COMMMON_LENGTH = mat.size();
        map<int, int> freq;

        
        for (const auto& row : mat)
        {
            for (const auto& num : row)
            {
                ++freq[num];
            }
        }

        for (const auto& elem : freq)
        {
            if (elem.second == COMMMON_LENGTH)
            {
                return elem.first;
            }
        }
        
        return NO_COMMON_ELEMENT;
    }

private:
    enum { NO_COMMON_ELEMENT = -1 };
};

// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
