class Solution {
public:
    int numSteps(string& s) 
    {
        int steps = 0;

        while (s != "1") 
        {
            const int n = s.size();
            if (s[n - 1] == '0') // 짝수이면
            { 
                s.pop_back(); // 마지막 '0'을 제거 (2로 나누는 것과 동일)
            } 
            else // 홀수이면
            { 
                int i = n - 1;
                while (i >= 0 && s[i] == '1') 
                {
                    s[i] = '0'; // 1을 0으로 바꿔가며 올림을 처리
                    --i;
                }
                if (i >= 0) 
                {
                    s[i] = '1'; // 마지막 올림 처리
                }
                 else 
                {
                    s = '1' + s; // 가장 앞에 '1' 추가
                }
            }
            ++steps;
        }

        return steps;
    }
};

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29
