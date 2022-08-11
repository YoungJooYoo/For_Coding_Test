class Solution 
{
  
public:
    void permute(vector<int> nums, int index) 
    {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++) {
            if (j == index || nums[j] != nums[index]) {
                swap(nums[index], nums[j]);
                permute(nums, index + 1);
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