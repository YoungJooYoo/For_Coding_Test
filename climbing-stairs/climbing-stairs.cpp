class Solution {
public:
    int climbStairs(int n) {
        /**************** 
            n = 1 -> 1가지
            n = 2 -> 2가지
            n = 3 -> 3가지
            n = 4 -> 5가지
            n = 5 -> 8가지
         피보나치 수열 패턴을 따른다.
         해법 1) DP 2) 재귀
        *****************/
        
        // DP 시작
        int answer[45 + 1];
        answer[1] = 1;
        answer[2] = 2;
        size_t i;
        
        if (n <= 2) {
            return n;
        }
        
        for (i = 3; i <= n; i++) {
            answer[i] = answer[i - 2] + answer[i - 1]; 
        }
        
        // for문 마지막에서 i + 1이 되고 for문 나오므로 인덱스에 -1한다
        return answer[i - 1];
    }
};