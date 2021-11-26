class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        
        for (size_t i = 2; i < 6; i++) {
            while ((n % i) == 0) {
                n = n / i;
            }
	    }
        if (n == 1) {
            return true;
        }
        
        return false;
    }
};