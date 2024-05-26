class Solution 
{
public:
    int maxScoreWords(const vector<string>& words, const vector<char>& letters, const vector<int>& score) 
    {
        unordered_map<char, int> letterCount;
        const int n = words.size();
        int maxScore = 0;

        for (const char letter : letters) 
        {
            letterCount[letter]++;
        }

        // 모든 부분 집합을 탐색
        for (int i = 1; i < (1 << n); ++i) 
        {
            unordered_map<char, int> currentCount(letterCount);
            int currentScore = 0;
            bool valid = true;

            for (int j = 0; j < n; ++j) 
            {
                if (i & (1 << j)) { // j번째 단어를 선택
                    for (const char c : words[j]) 
                    {
                        if (currentCount[c]-- <= 0) 
                        {
                            valid = false;
                        }
                        currentScore += score[c - 'a'];
                    }
                }
            }
            if (valid) 
            {
                maxScore = max(maxScore, currentScore);
            }
        }
        
        return maxScore;
    }
};

// https://leetcode.com/problems/maximum-score-words-formed-by-letters/?envType=daily-question&envId=2024-05-24


/*
문제 번역:

주어진 단어 목록, 문자 목록(중복 가능), 각 문자의 점수가 있습니다. 

주어진 문자들을 사용하여 만들 수 있는 단어 집합 중 최대 점수를 반환하세요. 단어는 두 번 이상 사용할 수 없습니다.

모든 문자를 사용할 필요는 없고, 각 문자는 한 번만 사용할 수 있습니다. 'a', 'b', 'c', ..., 'z'의 점수는 score, score[1], ..., score에 의해 주어집니다.

예시 1:
Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1][5][3][2]
Output: 23
설명: a=1, c=9, d=5, g=3, o=2 점수로 "dad"(5+1+5), "good"(3+2+2+5) 단어를 만들 수 있어 최대 점수는 23입니다.

예시 2: 
Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4][4][4][5]
Output: 27
설명: a=4, b=4, c=4, x=5, z=10 점수로 "ax"(4+5), "bx"(4+5), "cx"(4+5) 단어를 만들어 최대 27점입니다.  

예시 3:
Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [1][1][1][1][1][1]
Output: 0 
설명: 'e'는 한 번만 사용할 수 있어서 "leetcode"를 만들 수 없습니다.

제약 조건:
- 1 <= words.length <= 14
- 1 <= words[i].length <= 15  
- 1 <= letters.length <= 100
- letters[i].length == 1
- score.length == 26
- 0 <= score[i] <= 10
- words[i], letters[i]는 모두 소문자 영어 문자로 이루어져 있습니다.

Citations:
[1] https://programming4myself.tistory.com/m/147
[2] https://daslyee.tistory.com/104
[3] https://hailsong.github.io/algorithm%20-%20leetcode/LeetCode-0/
[4] https://blog.naver.com/PostView.nhn?blogId=junhwen&categoryNo=3&from=search&isShowPopularPosts=true&logNo=222117474138
[5] https://365waytobe-pro-grammer.tistory.com/38
*/
