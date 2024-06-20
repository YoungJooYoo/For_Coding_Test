class Solution {
public:
    int binaryGap(int n) 
    {
        int last = -1;
        int maxGap = 0;
        int currentPosition = 0;
        
        while (n > 0) {
            if (n & 1) { // 현재 비트가 1인 경우
                if (last != -1) {
                    maxGap = std::max(maxGap, currentPosition - last);
                }
                last = currentPosition;
            }
            n >>= 1; // 다음 비트로 이동
            ++currentPosition;
        }
        
        return maxGap;
    }
};

// https://leetcode.com/problems/binary-gap/
