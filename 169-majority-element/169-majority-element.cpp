class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        const size_t n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;
        
        /* 자료 중복이 없는 해시맵에 숫자-카운트 묶어서 계산 */
        for (size_t i= 0 ; i < n; i++) {
            mp[nums[i]]++;
        }
        
        // 숫자-카운팅갯수  묶여있어서, 카운팅 갯수가 n/2인 것을 찾으면 숫자를 반환
        for (auto num : mp) {
            if (num.second > n / 2) {
                count = num.first;
            }
        }
        
        return count;
    }
};