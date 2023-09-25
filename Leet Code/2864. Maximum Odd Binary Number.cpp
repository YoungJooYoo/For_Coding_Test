class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        const size_t  LEN = s.size();
        int count_one = 0;
    
        // 0과 1의 갯수를 카운트
        for (auto& binary : s) {
            if (binary == '1') ++count_one;
            binary = '0'; // 카운트 후 0으로 전부 초기화
        }
        
        // 맨뒤에 1을 채워 홀수로 만든다.
        if (count_one > 0) {
            s[LEN - 1] = '1';
            --count_one;
        }

        // 맨 앞 순서대로 남은 1을 넣어준다.
        for (auto& binary : s) {
            if (count_one > 0) {
                binary = '1';
                --count_one;
            }
        }
        
        return s;
    }
};

/*

풀이법 :

1의 개수를 카운트한다. 그와 동시에 주어진 인풋 문자열을 0으로 초기화한다.
1을 하나 맨 뒤로 보낸다 그래야 숫자가 무조건 호룻가 된다.
홀수화 작업이 끝난 문자열을 맨 앞에서부터 1을 넣어준다. 최대값이 나오게 된다.

*/

// https://leetcode.com/problems/maximum-odd-binary-number/description/
