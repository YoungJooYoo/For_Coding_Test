class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int sum = accumulate(arr.begin(), arr.end(), 0); 
        int part = 0;
        int count = 0;
        
        if (sum % 3 != 0) { // 3분할이니, 3으로 안나누어 떨어지면 안된다.
            return false;
        }
        
        for (const int& elem : arr) {
            part += elem;
                
            if (part == (sum / 3)) {
                count++;
                part = 0;
            }
        }
        
        return (count >= 3) ? true : false;
    }
};