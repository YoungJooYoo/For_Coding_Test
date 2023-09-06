class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        unordered_set<int> st;
        int result = -1;

        for (const auto& num : nums) {
            st.insert(num);
        }

        for (const auto& elem : st) { // 음수값을 넣어보며 존재한다면, 그 값으로 최대값 찾기
            if(st.find(-elem) != st.end()) {
                int temp = abs(elem);
                result = max(result, temp);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
