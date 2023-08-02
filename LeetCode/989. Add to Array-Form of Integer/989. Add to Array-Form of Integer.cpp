class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int> result;
        int i = num.size() - 1;
        int carry = 0;

        while (k != 0 || i >= 0 || carry > 0) { // 계산순서는 맨 뒷자리부터 하나씩 더한다.
            if (k != 0) {
                carry += k % 10; // 올림수 처리
                k = k / 10; // k의 자리수 삭제
            }
            if (i >= 0) {
                carry += num[i]; // carry와 num을 누적해서 결과 배열에 넣는다.
                i--;
            }
            result.push_back(carry % 10);
            carry /= 10;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

// https://leetcode.com/problems/add-to-array-form-of-integer/description/
