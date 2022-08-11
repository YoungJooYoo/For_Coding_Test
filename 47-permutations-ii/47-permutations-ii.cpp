class Solution {
public:
    void recursive_backtracking(int index, int arr_size, vector<int> nums)
    {
        if (index == arr_size) {
            result.push_back(nums);
            return;
        }
        
        for (size_t i = index; i < arr_size; i++) {
            if (index == i || nums[index] != nums[i]) {
                //swap(nums[i], nums[index]);
                swap(nums[index], nums[i]);
                recursive_backtracking(index + 1, arr_size, nums);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        recursive_backtracking(0, nums.size(), nums);
        return result;
    }
    
private:
    vector<vector<int>> result;
};