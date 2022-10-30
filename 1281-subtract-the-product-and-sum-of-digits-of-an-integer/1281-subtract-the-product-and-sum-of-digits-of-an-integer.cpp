class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        int product = 1;
        int digits = 0;
        
        while (n != 0) {
            product *= n % 10;
            digits += n % 10;
            n = n / 10;
        }
        
        return product - digits;
    }
};