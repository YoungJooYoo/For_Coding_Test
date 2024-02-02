class Solution 
{
public:
    void sequentialDigitsHelperRecursive(const int i, const int& low, const int& high, const int num)
    {
        if (low <= num && num <= high) {
            mResult.push_back(num);
        }
        
        if (num > high || i >= 9) {
            return;
        }
       
        sequentialDigitsHelperRecursive(i + 1, low, high, (num * 10) + i + 1);
    }
    
    vector<int> sequentialDigits(const int low, const int high) 
    {
        for (int i = 1; i <= 9; ++i) {
            sequentialDigitsHelperRecursive(i, low, high, i);
        }
        
        sort(mResult.begin(), mResult.end());
        
        return mResult;
    }
    
private:
    vector<int> mResult;
};

// https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02
