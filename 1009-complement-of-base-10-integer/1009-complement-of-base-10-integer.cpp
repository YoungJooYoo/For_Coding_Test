class Solution {
public:
    int bitwiseComplement(int n) 
    {
        
        if(n==0)
            return 1;
        
        int mask = 0;
        int m = n;
        while(m)
        {
           mask = (mask<<1) | 1;
           m = m>>1;
        }
        
        return ~n & mask;
    }
};