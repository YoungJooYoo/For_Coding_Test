class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        string number = sortedDigits(n);

        for (int i = 0; i < INT_RANGE_MAX; ++i) {
            string powerOfTwo = sortedDigits(1 << i);
            if (number == powerOfTwo) {
                return true;
            }
        }

        return false;
    }
    
    string sortedDigits(int n) 
    {
        string digits = to_string(n);
        sort(digits.begin(), digits.end());
        
        return digits;
    }

private:
    enum { INT_RANGE_MAX = 30 };
};