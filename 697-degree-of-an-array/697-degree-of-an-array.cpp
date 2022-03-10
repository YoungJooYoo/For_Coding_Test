class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, vector<int>> mp;
        size_t size = 0; // 출현 빈도수
        int pos = -1;  // 최대 빈도 숫자
        
        for (size_t i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() > size) {
                size = mp[nums[i]].size();
                pos = nums[i];
            }
        }
        
        int ans = INT_MAX;
        
        for (const auto& ele : mp) {
            if (ele.second.size() == size) {
                ans = min(ans, (ele.second[ele.second.size() - 1] - ele.second[0] + 1)); // ele.scond의 마지막 원소에 접근해서, 길이를 구한다. 그 길이 중 가장 작은 것을 찾고 반환
            }
        }
        
        return ans;
    }
};