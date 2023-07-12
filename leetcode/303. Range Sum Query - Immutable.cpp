class NumArray {
public:
    NumArray(vector<int>& nums) 
    {
        p_nums = nums;
    }
    
    int sumRange(int left, int right) 
    {
        int sum = 0;

        for (int i = left; i <= right; ++i) {
            sum += p_nums[i];
        }

        return sum;
    }

private:
    vector<int> p_nums;
};


// https://leetcode.com/problems/range-sum-query-immutable/description/
