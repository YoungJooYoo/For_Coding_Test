class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) 
    {
        int i = 0;
        int j = nums.size() - 1;
        int mid = (i + j) / 2;
        long long result = 0;

        while (i < j) {
            string temp = to_string(nums[i]) + to_string(nums[j]);
            result += stoi(temp);
            ++i;
            --j;
        }

        // 주어진 배열이 홀수 길이 중앙에 남는 인덱스의 nums 값을 누적.
        if (nums.size() % 2 == 1) result += nums[mid];

        return result;
    }
};

// https://leetcode.com/problems/find-the-array-concatenation-value/
