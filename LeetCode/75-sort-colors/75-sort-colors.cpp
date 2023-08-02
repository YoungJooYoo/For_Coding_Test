class Solution {
public:
    void sortColors(vector<int>& nums) 
	{
        // sort(nums.begin(), nums.end());  // Anotehr Solution
        
		for (size_t i = 0; i < nums.size() - 1; i++) {
			for (size_t j = i + 1; j < nums.size(); j++) {
				if (nums[i] > nums[j]) {
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
			}		
		}
    }
};