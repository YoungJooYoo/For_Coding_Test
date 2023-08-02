class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        
        // 지수가 0인 경우 무조건 1
        if (n == 0) {
            return 1;
        }
        
        if (n % 2 == 0) { // 지수가 짝수면, 제곱 양은 절반으로 줄이고
            return pow(x * x, n/2);
        }
        
        // 지수가 홀혹수이면 n - 1번의 절반만큼 곱하고 x를 다시 곱한다.
        return  x * pow(x * x, (n-1) / 2);
    }
};