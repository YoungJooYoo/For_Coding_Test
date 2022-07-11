class Solution 
{
public:
    void sequentialDigitsHelperRecursive(const size_t i, const int& low, const int& high, const int num)
    {
        if (num >= low and num <= high) {
            mResult.push_back(num);
        }
        if (num > high or i >= 9) {
            return;
        }
       
        sequentialDigitsHelperRecursive(i + 1, low, high, (num * 10) + i + 1);
    }
    
    vector<int> sequentialDigits(int low, int high) 
    {
        for (size_t i = 1; i <= 9; i++) {
            sequentialDigitsHelperRecursive(i, low, high, i);
        }
        
        sort(mResult.begin(), mResult.end());
        
        return mResult;
    }
    
private:
    vector<int> mResult;
};