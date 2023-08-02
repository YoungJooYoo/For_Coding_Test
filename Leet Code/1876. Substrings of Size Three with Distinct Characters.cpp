public:
    int countGoodSubstrings(string s) 
    {
        vector<string> sub_str;
        const size_t n = s.size();
        int count = 0;

        if (n < GOOD_LENGTH) {
            return count;
        }
        
        // get sub_str, 중복을 허용하니 배열로 사용
        for (size_t i = 0; i < n - 2; ++i) {
            sub_str.push_back(s.substr(i, GOOD_LENGTH));
        }

        // set을 사용해 중복체크, 중복이 없다면 길이가 3이다.
        for (const auto& elem : sub_str) {
            set<char> temp;
            for (const auto& ch : elem) {
                temp.insert(ch);
            }
            if (temp.size() == GOOD_LENGTH) {
                ++count;
            }
        }

        return count;
    }

private:
    enum { GOOD_LENGTH = 3 };
    
// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/
