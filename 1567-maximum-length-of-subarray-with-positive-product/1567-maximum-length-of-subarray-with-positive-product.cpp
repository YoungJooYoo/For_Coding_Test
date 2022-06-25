class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int neg = 0;
        int last0idx = -1;
        int firstnegidx = -1;
        int ans = 0;
        bool flag = false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                flag = false;
                last0idx = i;
                firstnegidx = i;
                neg = 0;
            }
            else {
                if (nums[i] < 0) {
                    neg++;
                    if(flag == false) {
                        flag = true;
                        firstnegidx = i;
                    }
                }
                if (neg % 2== 0) {
                    ans = max(ans,i - last0idx);
                }
                else {
                    ans = max(ans, i - firstnegidx);
                }
            }
        }
        
        return ans;
    }
};