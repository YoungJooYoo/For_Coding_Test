class Solution {
public:
    bool isSameAfterReversals(int num) 
    {
        string number1 = to_string(num);
        string number2 = to_string(num);

	    reverse(number1.begin(), number1.end()); // 숫자를 뒤집는다
        int temp_num = atoi(number1.c_str()); // 뒤집은 숫자를 정수화 시킨다 - 앞자리가 0 이면 제거가 된다.
        number1 = to_string(temp_num); // 다시 문자로 변환 후
        reverse(number1.begin(), number1.end()); // 원래 숫자로 다시 리버스 한다.

	    return number1 == number2 ? true : false; // 위의 과정을 거치고도 서로 같다면 같은 숫자, 아님녀 다른 숫자
    }
};

// https://leetcode.com/problems/a-number-after-a-double-reversal/description/
