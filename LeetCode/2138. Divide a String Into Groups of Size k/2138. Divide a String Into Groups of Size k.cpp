#include<cassert>

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector<string> result;
        int extra_length = s.size() % k;
        
        if (extra_length != 0) {
            for (size_t i = extra_length; i < k; ++i) { // 부족한 길이만큼 보충
                s += fill;
            } 
        }

        assert(s.size() % k == 0); // k의 배수로 떨어지는 s를 보장 검사

        for (size_t i = 0; i < s.size(); i = i + k) {
            string temp;
            for (size_t j = i; j < i + k; ++j) {
                temp += s[j];
            }
            result.push_back(temp);
        }

        return result;
    }
};

// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
