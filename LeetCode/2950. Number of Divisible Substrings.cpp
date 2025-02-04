class KeypadMapper 
{
public:
    KeypadMapper() 
    : mCharToNum(ALPHABET_LENGTH, 0)
    {
        mCharToNum['a' - 'a'] = 1; mCharToNum['b' - 'a'] = 1;
        mCharToNum['c' - 'a'] = 2; mCharToNum['d' - 'a'] = 2; mCharToNum['e' - 'a'] = 2;
        mCharToNum['f' - 'a'] = 3; mCharToNum['g' - 'a'] = 3; mCharToNum['h' - 'a'] = 3;
        mCharToNum['i' - 'a'] = 4; mCharToNum['j' - 'a'] = 4; mCharToNum['k' - 'a'] = 4;
        mCharToNum['l' - 'a'] = 5; mCharToNum['m' - 'a'] = 5; mCharToNum['n' - 'a'] = 5;
        mCharToNum['o' - 'a'] = 6; mCharToNum['p' - 'a'] = 6; mCharToNum['q' - 'a'] = 6;
        mCharToNum['r' - 'a'] = 7; mCharToNum['s' - 'a'] = 7; mCharToNum['t' - 'a'] = 7;
        mCharToNum['u' - 'a'] = 8; mCharToNum['v' - 'a'] = 8; mCharToNum['w' - 'a'] = 8;
        mCharToNum['x' - 'a'] = 9; mCharToNum['y' - 'a'] = 9; mCharToNum['z' - 'a'] = 9;
    }

    int getNumber(const char c) const
    {
        return mCharToNum[c - 'a'];
    }

private:
    vector<int> mCharToNum;
    enum { ALPHABET_LENGTH = 26 };
};

class Solution 
{
public:
    int countDivisibleSubstrings(const string& word) 
    {
        const KeypadMapper keypadMapper;
        const size_t LENGTH = word.size();
        int totalCount = 0;
        
        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);
        for (size_t i = 0; i < LENGTH; ++i)
        {
            assert('a' <= word[i] && word[i] <= 'z');
            int sum = 0;
            for (size_t j = i; j < LENGTH; ++j)
            {
                sum += keypadMapper.getNumber(word[j]);
                const size_t subLength = (j - i + 1);
                if (sum % subLength == 0) ++totalCount;
            }
        }

        return totalCount;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 2000
    };
};



// https://leetcode.com/problems/number-of-divisible-substrings/description/

/*

2950. 나누어떨어지는 부분 문자열의 개수


영문 알파벳의 각 문자는 아래와 같이 숫자에 매핑되어 있습니다.

문자열의 각 문자의 매핑된 값의 합이 그 문자열의 길이로 나누어떨어지면, 해당 문자열은 divisible하다고 합니다.

문자열 s가 주어질 때, s의 divisible한 부분 문자열의 개수를 반환하세요.

부분 문자열이란, 문자열 내에서 연속적이며 비어있지 않은 문자들의 수열을 의미합니다.

Example 1:

Substring	Mapped	Sum	Length	Divisible?
a	1	1	1	Yes
s	7	7	1	Yes
d	2	2	1	Yes
f	3	3	1	Yes
as	1, 7	8	2	Yes
sd	7, 2	9	2	No
df	2, 3	5	2	No
asd	1, 7, 2	10	3	No
sdf	7, 2, 3	12	3	Yes
asdf	1, 7, 2, 3	13	4	No
Input: word = "asdf"
Output: 6
Explanation: 위 표는 단어의 모든 부분 문자열에 대한 세부 정보를 보여주며, 그 중 6개의 부분 문자열이 divisible함을 알 수 있습니다.

Example 2:

Input: word = "bdh"
Output: 4
Explanation: divisible한 4개의 부분 문자열은 "b", "d", "h", "bdh"입니다.
다른 divisible한 부분 문자열은 존재하지 않음을 보일 수 있습니다.

Example 3:

Input: word = "abcd"
Output: 6
Explanation: divisible한 6개의 부분 문자열은 "a", "b", "c", "d", "ab", "cd"입니다.
다른 divisible한 부분 문자열은 존재하지 않음을 보일 수 있습니다.

Constraints:

1 <= word.length <= 2000
word는 소문자 영문자로만 구성되어 있습니다.
*/
