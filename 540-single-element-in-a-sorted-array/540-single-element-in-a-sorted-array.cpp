class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        for (const auto& element : freq) {
            if (element.second == 1) return element.first;
        }
        
        return -1;
    }
};