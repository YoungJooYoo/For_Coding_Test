class Solution {
public:
    int arrangeCoins(int n) 
    {
        int i = 1;
        
        while(true) {
            n -= i;
            if (n < 0) return i - 1;
            i++;
        }
        
        return 0;
    }
};