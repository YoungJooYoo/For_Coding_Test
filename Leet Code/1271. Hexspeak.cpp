class Solution {
public:
    string toHexspeak(const string& num) 
    {
        return toHex(stoll(num));
    }

private:
    string toHex(long long number) 
    {
        if (number == 0) {
            return "O"; // 0일 경우 바로 반환
        }

        string hex;
        while (number != 0) {
            const int rem = number % 16; // 16진수에서의 자릿수를 얻기 위해 16으로 나눈 나머지를 구함
            if (rem == 0) hex.push_back('O');
            else if (rem == 1) hex.push_back('I');
            else if (2 <= rem && rem <= 9) {
                return "ERROR";
            }
            else hex.push_back('A' + rem - 10); // 10부터 15까지는 A부터 F까지의 문자에 대응하여 추가
            number /= 16; // 다음 자릿수로 이동
        }

        reverse(hex.begin(), hex.end()); // 문자열을 뒤집어서 반환해야 함
        return hex;
    }
};

// https://leetcode.com/problems/hexspeak/description/
