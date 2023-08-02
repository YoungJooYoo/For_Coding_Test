class Solution {
public:
    int countTriples(int n) 
    {
        int res = 0;
        
        for (size_t i = 1; i <= n; i++) {
            for (size_t j = i + 1; j <= n; j++) {
                double tmp = sqrt(i*i + j*j);
                if (int(tmp) == tmp && tmp <= n) {
                    res += 2;
                }
            }
        }
        
        return res;
    }
};