class Solution {
public:
    string removeTrailingZeros(string num) 
    {
        string result = "";
        bool is_tail_zero = true;

        for (int i = num.size() - 1;  i  >= 0; --i) {  // 꼬리쪽 0 제거하면서 숫자 붙이기
            if (num[i] != '0') {
                is_tail_zero = false;
                result += num[i];
            }
            else if (num[i] == '0' && is_tail_zero == false) result += num[i]; // 숫자 중간에 0이 나오는 경우 덧붙이기
        }

        reverse(result.begin(), result.end()); // 완성된 숫자는 거꾸로 되어있으므로, 리버스로 원래 숫자 만든다.
        return result;
    }
};

// https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/
