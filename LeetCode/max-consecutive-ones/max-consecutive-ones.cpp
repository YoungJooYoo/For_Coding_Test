class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int cnt_temp = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            cnt_temp++;
            cnt = max(cnt_temp, cnt);
        }
        else {
            cnt_temp = 0;
        }
    }
        return cnt;
    }
};