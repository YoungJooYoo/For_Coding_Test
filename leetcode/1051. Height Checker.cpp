class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
        int result = 0;
        auto array = heights;
        
        sort(array.begin(), array.end());

        for (size_t i = 0; i < array.size(); ++i)
        {
            if (array[i] != heights[i]) ++result;
        }

        return result;
    }
};

// https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
