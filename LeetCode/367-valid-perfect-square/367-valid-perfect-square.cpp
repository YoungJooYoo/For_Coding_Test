class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        long long left = 0;
        long long right = num;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2; 
            long long t = mid * mid;
            if (t == num) {
                return true;
            }
            else if (t < num) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};