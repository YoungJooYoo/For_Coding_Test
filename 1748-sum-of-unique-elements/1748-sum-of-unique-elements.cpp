class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        int ans = 0;
        
        for (const int& num : nums) {
            mp[num]++; 
        }
        
        for (const auto& ele : mp) {
            if (ele.second == 1) {
                ans += ele.first;
            }    
        }
        
        return ans;
    }
};
