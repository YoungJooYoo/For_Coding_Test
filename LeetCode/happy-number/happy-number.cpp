class Solution {
public:
    bool isHappy(int n) {
        long long sum;
        int digit;
        
        while (true) {
            sum = 0;
            while(n != 0) {
                digit = n % 10; // 숫자의 뒷자리부터 하나씩 분해
                sum = sum + (digit * digit); // 분해된 숫자를 더함
                n = n / 10; // 뒷자리 하나씩 제거
            } // end of while.
            if (1 <= sum && sum <= 9) {
                if (sum == 1 || sum == 7) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                n = sum;
            }

        } // end of while.
        
        return true;
    }
};
