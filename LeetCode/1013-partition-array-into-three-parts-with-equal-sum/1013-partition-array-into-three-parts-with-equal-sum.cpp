class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int sum = accumulate(arr.begin(), arr.end(), 0); 
        int part_sum = 0;
        int count = 0;
        
        if (sum % 3 != 0) { // 3분할이니, 3으로 안나누어 떨어지면 안된다.
            return false;
        }
        
        for (const int& elem : arr) {
            part_sum += elem;
                
            if (part_sum == (sum / 3)) { // 합이 3으로 나누면 몫이 0이 되는 시점에,
                count++;
                part_sum = 0;
            }
        }
        
        return (count >= 3) ? true : false; // >= 3 이유는 0 0 0 0과 같이 어떻게 3분할 해도되는 숫자 때문
    }
};