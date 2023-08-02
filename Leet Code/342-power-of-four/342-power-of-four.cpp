class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if (n < 1) {
            return 0;
        }

         while(n % 4 == 0) {
            n /= 4;
         }
        
        return n == 1 ? true : false;  
    }
};