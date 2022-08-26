class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        string number = sortedDigits(n);

        // 정렬된 숫자가, 앞에서부터 
        for (int i = 0; i < INT_RANGE_MAX; ++i) {
            string powerOfTwo = sortedDigits(1 << i);
            if (number == powerOfTwo) {
                cout << "지금" << endl;
                return true;
            }
        }

        return false;
    }
    
    string sortedDigits(int n) // 문자 -> 문자열 -> 정렬 -> 0이 맨 앞
    {
        string digits = to_string(n);
        sort(digits.begin(), digits.end());
        
        return digits;
    }

private:
    enum { INT_RANGE_MAX = 30 };
};