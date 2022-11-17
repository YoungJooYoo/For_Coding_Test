class Solution {
public:
    int xorOperation(int n, int start) 
    {
        int result = 0;
        int num = 0;
        
        for (int i = 0; i < n; i++) {
            num = start + (2 * i);
            result = result ^ num;
        }
        
        return result;
    }
};