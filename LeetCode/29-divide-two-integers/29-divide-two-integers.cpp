class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        // support variables
        int bits = 1;
        long d1 = dividend;
        long d2 = divisor;
        long res = 0;
        bool isMinus = false;
        
        // setting the sign
        if (d1 < 0) {
            isMinus = !isMinus;
            d1 = -d1;
        }
        if (d2 < 0) {
            isMinus = !isMinus;
            d2 = -d2;
        }
        
        // adjusting d2
        while (d2 <= d1) {
            d2 <<= 1;
            bits++;
        }
        // composing res
        while (bits--) {
            res = res * 2 + (d1 >= d2);
            if (d1 >= d2) {
                d1 -= d2;
            }
            d2 >>= 1;
        }
        
        // handling overflows
        if (res > 2147483647l + isMinus) {
            res = 2147483647;
        }
        
        return isMinus ? -res : res;
    }
};