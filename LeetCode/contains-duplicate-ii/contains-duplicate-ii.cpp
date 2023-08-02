class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        const size_t nums_length = nums.size();
        unordered_map<int, int> map;
        
        if ((nums_length <= 1) || (k == 0)) { // 문제의 예외처리
            return false;
        }
        
        for (size_t i = 0; i < nums_length; i++) {
           if (map.find(nums[i]) != map.end()) { // nums[i]가 존재 한다면,
               if (i - map[nums[i]] <= k) { // 문제의 조건
                   return true;
               }
           }
            map[nums[i]] = i; // map -> key : value 생성
        }
        
        return false;
    }
};