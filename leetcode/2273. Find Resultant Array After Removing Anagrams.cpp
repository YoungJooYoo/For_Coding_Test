class Solution {
public:
    bool isAnagram(string word1, string word2) 
    {
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        return (word1 == word2) ? true : false;
    }

    vector<string> removeAnagrams(vector<string>& words) 
    {
        const size_t LENGTH = words.size();
        vector<string> result;

        result.push_back(words[0]);
        for (size_t i = 1; i < LENGTH; ++i) {
            if (!isAnagram(words[i - 1], words[i])) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};


/*

소문자 영어 알파벳으로 구성된 0-인덱스 문자열 배열 words가 제공됩니다.
한 번의 작업에서, 0 < i < words.length 및 words[i - 1]과 words[i]가 애너그램인 인덱스 i를 선택하고, words[i]를 words에서 삭제합니다. 조건을 만족하는 인덱스를 선택할 수 있는 한 계속 이 작업을 수행합니다.

모든 작업을 수행한 후 words를 반환합니다. 임의의 순서로 각 작업에 대한 인덱스를 선택하더라도 같은 결과로 이끌어질 수 있음을 보여줍니다.

애너그램은 모든 원래 문자를 정확히 한 번만 사용하여 다른 단어나 구문의 문자를 재배열하여 형성된 단어 또는 구문입니다. 예를 들어, "dacb"는 "abdc"의 애너그램입니다.

예시 1:

입력: words = ["abba","baba","bbaa","cd","cd"]
출력: ["abba","cd"]
설명:
결과적인 배열을 얻을 수 있는 방법 중 하나는 다음과 같은 작업을 사용하는 것입니다:

words[2] = "bbaa"이고 words[1] = "baba"가 애너그램이므로, 인덱스 2를 선택하고 words[2]를 삭제합니다.
이제 words = ["abba","baba","cd","cd"]입니다.
words[1] = "baba"이고 words[0] = "abba"가 애너그램이므로, 인덱스 1을 선택하고 words[1]를 삭제합니다.
이제 words = ["abba","cd","cd"]입니다.
words[2] = "cd"이고 words[1] = "cd"가 애너그램이므로, 인덱스 2를 선택하고 words[2]를 삭제합니다.
이제 words = ["abba","cd"]입니다.
더 이상 어떤 작업도 수행할 수 없으므로, ["abba","cd"]가 최종 답변입니다.
예시 2:
입력: words = ["a","b","c","d","e"]
출력: ["a","b","c","d","e"]
설명:
words에서 인접한 두 개의 문자열이 서로 애너그램이 아니므로 작업이 수행되지 않습니다.

제한 사항:

1 <= words.length <= 100
1 <= words[i].length <= 10
words[i]는 소문자 영어 알파벳으로 구성됩니다.

문제 요약: 문자열 배열에서 서로 인접한 문자열이 애너그램인 경우에만 한 번의 작업으로 해당 문자열을 삭제하여 결과 배열을 반환합니다.
풀이 방향: 이 문제를 해결하기 위해서는 각 문자열이 인접한 문자열과 애너그램인지 확인하고, 만약 애너그램이면 해당 문자열을 삭제해야 합니다. 인접한 문자열을 비교하여 애너그램인지 확인하고, 애너그램이면 해당 문자열을 삭제하는 방법을 반복하면 됩니다.
*/

// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
