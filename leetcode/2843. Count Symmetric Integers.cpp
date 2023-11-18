class Solution {
public:
    bool is_same_sum(const string& nums) 
    {
        // 문제조건, 홀수 길이 숫자는 제외하기
        if (nums.size() % 2 == 1) {
            return false;
        }

        int left_sum = 0;
        int right_sum = 0;
        int i = 0;
        int j = nums.size() - 1;

        // 앞뒤자리 숫자 더하고 비교하기
        while (i < j) {
            left_sum += nums[i];
            right_sum += nums[j];
            ++i;
            --j;
        }
        
        return left_sum == right_sum ? true : false;
    }

    int countSymmetricIntegers(int low, int high) 
    {
        int count = 0;
        
        for (int i = low; i <= high; ++i) {
            const string nums = to_string(i);
            if(is_same_sum(nums) == true) ++count;
        }
        
        return count;
    }    
};

// https://leetcode.com/problems/count-symmetric-integers/description/
