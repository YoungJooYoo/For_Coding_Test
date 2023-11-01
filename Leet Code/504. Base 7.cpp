class Solution {
public:
    string convertToBase7(int num) 
    {
        if (num == 0) {
            return "0";
        }

        string base_7 = "";
        bool minus_flag = false;

        if (num < 0) { // 음수면 양수로 만들고 flag에 체크
            num *= -1;
            minus_flag = true;
        }

        while (num != 0) {
            base_7 += to_string(num % DIVISOR);
            num /= DIVISOR;
        }

        if (minus_flag == true) { // - 플래그가 yes면 문자열 마지막에 -를 붙인다.
            base_7 += "-";
        }
        reverse(base_7.begin(), base_7.end()); // 7진수 변환과정 중 역순으로 숫자가 구해져서 리버스를 해줘 원래 나와야할  숫자로 만든다.

        return base_7;
    }

private :
    enum { DIVISOR = 7 };
};

// https://leetcode.com/problems/base-7/description/
