class Solution {
public:
    int splitNum(int num) 
    {
        string number = to_string(num);
        string num1 = "";
        string num2 = "";

        sort(number.begin(), number.end()); // 오름차순으로 숫자 정렬
        
        for (size_t i = 0; i < number.size(); ++i) { 
            if (i % 2 == ODD) {
                num1.push_back(number[i]);
            }
            else if (i % 2 == EVEN) {
                num2.push_back(number[i]);
            }
        }

        return stoi(num1) + stoi(num2);
    }

private:
    enum { 
        EVEN = 0,
        ODD = 1
    };
};

/*

풀이해설 :

앞자리수가 작을수록 작은수이니, 문자열로 숫자를 변경후 오름차순으로 정렬한다.
인덱스 홀수짝수 순서대로 취합하며 정수를 만든다.

*/


// https://leetcode.com/problems/split-with-minimum-sum/description/
