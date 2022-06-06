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
        
        for (size_t i = 1, j = ARR_SIZE - 2; i < ARR_SIZE; i++) {
            left_side[i] = left_side[i - 1] * nums[i - 1];
            right_side[j] = right_side[j + 1] * nums[j + 1];
            j--;
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
좌우로 누적 곱의 배열을 만들면서 이 미리 만들어진
배열을  참조해서, 답을 구하는 방식이다.
좌우에서 곱해서 오면서, 해당 인덱스만 빼고 곱한 값이 최종으로 나오게 진행된다.

*/