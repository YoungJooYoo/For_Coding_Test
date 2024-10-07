class Solution 
{
public:
    char kthCharacter(const int k) 
    {
        string word = "a";

        while (word.size() < k) 
        {
            string generated = "";
            // 현재 word의 각 문자를 다음 문자로 변경하여 생성
            for (const char ch : word) 
            {
                if (ch == 'z') 
                {
                    generated += 'a';
                }
                else 
                {
                    generated += (ch + 1);
                }
            }
            word += generated;
        }

        // k번째 문자 반환 (1-based index)
        return word[k - 1];
    }
};

// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/

/*

3304. 문자열 게임 I에서 K번째 문자 찾기
쉬움

주제

앨리스와 밥이 게임을 하고 있습니다. 처음에 앨리스는 문자열 word = "a"를 가지고 있습니다.

양의 정수 k가 주어집니다.

이제 밥은 앨리스에게 다음과 같은 작업을 무한히 수행하도록 요청할 것입니다:

각 문자를 영어 알파벳의 다음 문자로 변경하여 새로운 문자열을 생성하고, 이를 원래의 word에 추가합니다. 예를 들어, "c"에 대해 작업을 수행하면 "cd"가 생성되고, "zb"에 대해 작업을 수행하면 "zbac"가 생성됩니다.

word에 적어도 k개의 문자가 될 때까지 충분한 작업을 수행한 후, word의 k번째 문자의 값을 반환하세요.

참고: 작업에서 문자 'z'는 'a'로 변경될 수 있습니다.

예제 1:
makefile
코드 복사
입력: k = 5
출력: "b"
설명:

처음에 word = "a"입니다. 작업을 세 번 수행해야 합니다:

생성된 문자열은 "b"이며, word는 "ab"가 됩니다.
생성된 문자열은 "bc"이며, word는 "abbc"가 됩니다.
생성된 문자열은 "bccd"이며, word는 "abbcbccd"가 됩니다.
예제 2:
makefile
코드 복사
입력: k = 10
출력: "c"
제약 사항:
1 <= k <= 500


*/
