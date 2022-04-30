class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int res = 0;
        int num = x^y; // 비트가 다른 부분만 1로 남긴다.
        
        while (num != 0) { // 남겨진 1의 갯수를 카운트한다.
            res = res + (num % 2);
            num = num >> 1; // 우측으로 비트 하나씩 밀어낸다. 나누기 2 효과
        }
        
        return res;
    }
};