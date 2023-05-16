class Solution {
public:
    bool isDecomposable(string s) {

        const size_t len = s.length();
        size_t count_2 = 0;
        size_t count_3 = 0;
        size_t curr_len = 0;

        if (len < 2) {
            return false;
        }

        char curr = s[0];

        for (size_t i = 0; i < len; ++i){
            if (s[i] == curr) {
                curr_len++;
            }
            else {
                if (curr_len == 1) return false;
                else if (curr_len % 3 == 0) ++count_3;
                else ++count_2;
                if (count_2 > 1) return false; // 문제 조건에 따라 길이 2는 1번만 나오면 된다.
                curr_len = 1;
                curr = s[i];
            }
            if (i == len - 1) { // 마지막 인덱스
                if (curr_len == 1) return false;
                else if (curr_len % 3 == 0) count_3++;
                else count_2++;
                if (count_2 > 1) return false;
                break;
            }
        }

        return count_2 == 1;
    }
};

// https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/description/
