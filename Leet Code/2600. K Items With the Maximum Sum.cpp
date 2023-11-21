class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) 
    {
        int sum = 0;

        while(k != 0 && numOnes != 0) {
            ++sum;
            --numOnes;
            --k;
        }
        while(k != 0 && numZeros != 0) {
            --numZeros;
            --k;
        }
        while(k != 0 && numNegOnes != 0) {
            --sum;
            --numOnes;
            --k;
        }

        return sum;    
    }
};

// https://leetcode.com/problems/k-items-with-the-maximum-sum/description/
