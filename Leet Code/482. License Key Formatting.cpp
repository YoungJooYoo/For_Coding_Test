class Solution {
public:
    const string licenseKeyFormatting(const string& s, const int k) const
    {
        stack<char> st;
        string result;

        // 대시를 제거 후, 전부 대문자로 바꾸어 버림
        for (const auto& ch : s) {
            if (ch != '-') {
                st.push(toupper(ch));
            }
        }

        size_t count = 0;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
            ++count;
            if (count == k && !st.empty()) {
                result.push_back('-');
                count ^= count; // count == 0;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


/*
1. 첫번째 그룹은  k보다 짫을수 있다.
2. 전부 대문자로 변경할 것
*/

// https://leetcode.com/problems/license-key-formatting/description/
