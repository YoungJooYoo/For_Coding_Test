class Solution {
public:
    int brokenCalc(int startValue, int target) 
    {
        int result = 0;
        
        while (target > startValue) {
            if (target % 2 == 0) { // 짝수인 경우
                target /= 2;
            }
            else { // 홀인 경우
                target++;
            }
            result++;
        }
        
        return result + (startValue - target);
    }
};