class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const size_t nums_length = nums.size();
        int ones = 0;
        int prev_ones = 0; 
        int max_ones = 0;
        
        for (size_t i = 0; i < nums_length; ++i) {
            if (nums[i] == 0) {
                max_ones = max(max_ones, prev_ones + ones); 
                prev_ones = ones; 
                ones = 0;
            }
            else {
                ++ones;
            }    
        }
        
        return max(max_ones, prev_ones + ones) + (ones == nums_length ? 0 : 1);
    }
};



/****************************************
풀이법 :
1의 현재 및 이전 수와 그 합계의 최대값을 추적하세요. 
0이 두 개 이상 있으면 이전의 1 수가 0이 됩니다. 
배열에 1번째만 있는 경우가 아니면 결국 플립의 최대값에 1을 추가합니다.
*****************************************/