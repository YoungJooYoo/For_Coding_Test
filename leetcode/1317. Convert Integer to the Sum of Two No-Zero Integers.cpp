class Solution {
public:
    bool is_non_zero(int n) 
    {
        while (n > 0) {
            if  (n % 10 == 0) {
                return false;
            }
            n /= 10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) 
    {
        vector<int> result;
        int left = 1;
        int right = n - left;

        while (left <= right) {
            if (is_non_zero(left) == true && is_non_zero(right) == true) {
                result.push_back(left);
                result.push_back(right);
                return result;
            }
           ++left;
           --right;            
        }

        return result;
    }
};

https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/
