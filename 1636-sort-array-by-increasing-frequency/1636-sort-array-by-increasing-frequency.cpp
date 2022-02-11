class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b) 
    {
        return  (a.second == b.second) ? a.first>b.first : a.second<b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        vector<pair<int, int>> nums_freq;
        vector<int> result;
        
        if (nums.size() == 1) { 
            return nums;
        }
        
        for (const int& num : nums) {
            mp[num]++;
        }
        
        for (const auto& elem : mp)  {
            nums_freq.push_back(elem);
        }
        
        sort(nums_freq.begin(), nums_freq.end(), cmp);

        for (auto num : nums_freq) {
            for (int i = 0; i < num.second; i++) {
                result.push_back(num.first);
            }
        }
        
        return result;
    }
};