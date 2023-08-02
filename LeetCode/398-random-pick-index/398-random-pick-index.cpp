class Solution 
{
public:
    Solution(vector<int>& nums)
    {
        for (size_t i = 0;i < nums.size(); i++)
        {
            freq[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) 
    {
        size_t freq_size = freq[target].size();
        int pos = rand() % freq_size;
        return freq[target][pos];
    }
    
private:
    unordered_map<int, vector<int>> freq;
};