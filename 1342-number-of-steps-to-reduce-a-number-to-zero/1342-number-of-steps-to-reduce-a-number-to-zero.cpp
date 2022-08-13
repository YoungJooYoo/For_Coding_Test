class Solution 
{
public:
    int numberOfSteps(int num) 
    {
        int count = 0;
        
        while (num != 0) {
            if (num % 2 == 0) {
                num = num / 2;
            }
            else { // 홀수인경우
                num--;
            }
            count++;
        }
        
        return count;
    }
};