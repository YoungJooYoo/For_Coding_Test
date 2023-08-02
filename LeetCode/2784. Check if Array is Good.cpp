class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        const size_t SIZE = nums.size();
        int hash[LENGTH] = { 0, };
        
        sort (nums.begin(), nums.end());

        for (const int& num : nums) {
            ++hash[num];
        }

        // 마지막 원소끼리만 중복 허용, 나머지는 허용 안함을 체크
        for (size_t i = 1; i < SIZE - 1; ++i) {
            if (hash[i] > 1) return false;
        }

       // 배열의 길이는 마지막원소 + 1과 동일 하므로, 체크하는 것  or  가장 큰 원소가 2개 안나오면 false
        if (SIZE != nums[SIZE - 1] + 1 || hash[SIZE - 1] != 2) {
            return false;
        }

        return true;
    }

private:
    enum { LENGTH = 200 + 1 };
};


// https://leetcode.com/problems/check-if-array-is-good/description/
