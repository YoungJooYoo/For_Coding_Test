class Solution {
public:
    int pivotInteger(int n) 
    {
        if (n == 1) {
            return 1 ;
        }

        vector<int> pre_sum(n + 1) ;
        int sum = 0;

        for (int i = 1;  i <= n; ++i) {
            sum += i;
            pre_sum[i] = sum;
        }

        sum = 0;

        for (int i = n ; i > 0; --i) {
            sum += i;
            if (pre_sum[i] == sum) { // 뒤에서부터 가장 큰 값이므로, 차근차근 presum의 뒷의 인덱스 값부터 탐색하며 sum가 일치하는지 비교
                return i;
            }
        }

        return NO_EXIST;    
    }

private:
    enum { NO_EXIST = -1 };
};

// https://leetcode.com/problems/find-the-pivot-integer/description/
