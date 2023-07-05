class Solution {
public:
    int partitionString(string s) 
    {
        const size_t LENGTH = s.size();
        int result = 0;
        vector<int> hash(ALPHA_LEN, 0);

        for (size_t i = 0; i < LENGTH; ++i) {
            if (hash[s[i] - 'a'] > 0) { // 이미 존재하지 않는다면
                ++result;
                fill(hash.begin(), hash.end(), 0);
                ++hash[s[i] - 'a'];
            }
            else { // 해시 테이블에 존재 안하면 추가
                ++hash[s[i] - 'a'];
            }
        }

        return ++result; //add 1 to store last string partition
    }

private: 
    enum { ALPHA_LEN = 26 };
};

// https://leetcode.com/problems/optimal-partition-of-string/description/
