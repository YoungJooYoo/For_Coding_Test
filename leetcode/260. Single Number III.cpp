class Solution 
{
public:
    vector<int> singleNumber(const vector<int>& nums) 
    {
        vector<int> result;
        unordered_map<int ,int> freq;

        for (const int& num : nums)
        {
            ++freq[num];
        }

        for (const auto& elem : freq)
        {
            if (elem.second == 1) 
            {
                result.push_back(elem.first);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31
