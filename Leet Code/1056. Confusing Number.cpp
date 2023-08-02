class Solution {
public:
    bool confusingNumber(int N) 
    {
        int n = 0;
        int origin = N;

        while (N != 0) {
            int tmp = N % 10;
            if (tmp == 0 || tmp == 8 || tmp == 1) ;  // 뒤집어도 같은 숫자는 재사용, 아무것도 안함
            else if (tmp == 6) tmp = 9; // 9 6반전
            else if (tmp == 9) tmp = 6; // 9 6반전
            else return false; // 그외 숫자는 false
            n = (n * 10) + tmp;
            N /= 10;
        }

        return origin != n; // 최종 만들어진 숫자가 원본과 같지 않으면 true
    }
};

// https://leetcode.com/problems/confusing-number/description/
