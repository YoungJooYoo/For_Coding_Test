class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int neg = 0;
        int ans = 0;
        int last_zero_idx = -1;
        int first_neg_idx = -1;
        bool flag = false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) { // 0인 경우 카운트 하던 모든것을 초기화로 세팅한다.
                flag = false;
                last_zero_idx = i;
                first_neg_idx = i;
                neg = 0;
            }
            else {
                if (nums[i] < 0) {
                    neg++;
                    if (flag == false) {
                        flag = true;
                        first_neg_idx = i;
                    }
                }
                if (neg % 2 == 0) {
                    ans = max(ans, i - last_zero_idx);
                }
                else {
                    ans = max(ans, i - first_neg_idx);
                }
            }
        }
        
        return ans;
    }
};