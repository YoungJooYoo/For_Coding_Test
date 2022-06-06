class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        const size_t ARR_SIZE = nums.size();
        vector<int> left_side(ARR_SIZE, 0);
        vector<int> right_side(ARR_SIZE, 0);
        vector<int> ans(ARR_SIZE, 0);
        
        left_side[0] = 1;
        right_side[ARR_SIZE - 1] = 1;
        size_t j = ARR_SIZE - 2;
        
        for (int i = 1; i < ARR_SIZE; i++) {
            left_side[i] = left_side[i - 1] * nums[i - 1];
            right_side[j] = right_side[j + 1] * nums[j + 1];
            j--;
        }
        for (int j = ARR_SIZE - 2; j >= 0; j--) {
            //right_side[j] = right_side[j + 1] * nums[j + 1];
        }
         
        for (size_t i = 0; i < ARR_SIZE; i++) {
            ans[i] = left_side[i] * right_side[i];
        }
    
        return ans;
    }
};

/*
풀이법 : 
문제의 조건은 o(n)이며, 32bit 정수이다.


*/








