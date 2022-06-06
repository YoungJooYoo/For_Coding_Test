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

ex 
{1 2 3 4}
Left   1  1 2 6
Right 24 24 4 1
=> 예를 들면 숫자 3이 오는 인덱스 자리는 2*4 = 8이  답이 된다.
right에서 4는  4*1, 이고  left에서 오는 2는 1*2 이다 따라서 3을 제외한 1*2*4를 곱해 해당 인덱스에 있는 3을 뺀 값을
구할 수 있는 것이다.
즉 

*/