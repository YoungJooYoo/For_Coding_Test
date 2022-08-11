class Solution 
{
  
public:
    void permute(vector<int> nums, int i) 
    {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j == i || nums[j] != nums[i]) {
            swap(nums[i], nums[j]);
            permute(nums, i + 1);
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        permute(nums, 0);
        
        return result;
    }
    
private:
    vector<vector<int>> result;
};