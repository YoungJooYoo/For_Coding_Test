class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const size_t nums_length = nums.size();
        vector<vector<int>> result;
        int i;
        int j;  // j, k are use for two-point
        int k;  // nums's end index
        
        sort(nums.begin(), nums.end()); // 답은 정렬된 배열, 처음부터 정렬 시켜두기.
        if (nums_length < 3 || nums[0] > 0 || nums[nums_length - 1] < 0) { // 정렬된 배열이 전부 양수거나, 음수거나, 길이가 짧아서 조건에 안맞으면 종료
            return result;
        }
        
        for (i = 0; i < nums_length - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) { // 2nd conditionin, to skip the duplicate triplets
                continue;
            }
            
            j = i + 1;
            k = nums_length - 1;
            
            while (j < k && k >= 0) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else {
                    j++;
                }
                while((j != i + 1) && (j < k) && (nums[j] == nums[j - 1])) { // 2nd conditionin, to skip the duplicate triplets
                    j++;
                }
                 while((k != nums_length - 1) && (j < k) && (nums[k] == nums[k + 1])) { // 2nd conditionin, to skip the duplicate triplets
                    k--;
                }
            }    
        }
        
        return result;
    }
};
