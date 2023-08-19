class Solution {
public:
    bool isVowel(const char w)
    {
        return (w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u');
    }

    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int count = 0;
        
        // left right 범위 안에서  시작과 끝이 모두 모음인 문자열을 찾는다.
        for(int i = left; i <= right; ++i) {
            if(isVowel(words[i][0]) && isVowel(words[i].back())) ++count;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/
