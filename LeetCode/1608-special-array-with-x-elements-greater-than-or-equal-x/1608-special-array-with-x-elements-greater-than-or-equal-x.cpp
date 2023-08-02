class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums.size() - i;
            cout << x << endl;
            if ((nums[i] >= x) && (i == 0 || nums[i - 1] < x)) {
                return x;
            }             
         }
        
        return -1;
    }
};