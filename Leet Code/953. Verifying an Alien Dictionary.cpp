class Solution {
public:
    bool isAlienSorted(vector<string>& words, const string& order) 
    {
        int mapping[LENGTH];
        
        // 해시테이블로 알파벳 순위에 우선순위를  기입
        for (size_t i = 0 ; i < LENGTH; ++i) {
            mapping[order[i] - 'a'] = i;
        }

        // 배열속 문자열의 문자를, 사전에 우선순위의 숫자로 변경
        for (auto& word : words) {
            for (auto& ch : word) {
                ch = mapping[ch - 'a'];
            }
        }

        // 우선순위 숫자로 변환된 배열을 보고, 해당 숫자들이 정렬되었는지 아닌지로 판단.
        return is_sorted(words.begin(), words.end());
    }

private:
    enum { LENGTH = 26 };
};

/*

1. **번역**: 외계어에서도 놀랍게도 영어 소문자를 사용하지만, 알파벳 순서가 다를 수 있습니다. 알파벳 순서는 소문자들의 순열입니다. 외계어로 쓰인 단어들의 순서와 알파벳 순서가 주어졌을 때, 이 외계어에서 주어진 단어들이 사전순으로 정렬되었다면 true를 반환합니다.

   예시 1: 입력: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz", 출력: true (설명: 'h'가 이 언어에서 'l'보다 앞서므로, 이 순서는 정렬되어 있습니다.)
   예시 2: 입력: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz", 출력: false (설명: 'd'가 'l' 뒤에 오므로, words[0] > words[1], 따라서 순서가 정렬되지 않았습니다.)
   예시 3: 입력: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz", 출력: false (설명: "app"라는 세 문자가 일치하고 두 번째 문자열이 더 짧습니다. 사전순 규칙에 따르면 "apple" > "app" 입니다.)

2. **요약**: 이 문제는 외계어의 알파벳 순서에 따라 주어진 단어들이 사전순으로 정렬되었는지를 확인하는 것입니다.

3. **문제 풀이 방향**: 주어진 외계어의 알파벳 순서를 기반으로 각 문자에 순위를 부여합니다. 그런 다음 이 순위를 사용하여 단어들이 사전순으로 정렬되었는지를 확인합니다. 모든 단어들을 순회하면서 이전 단어와 비교하여 순서가 올바른지 확인하고, 만약 어떤 단어가 이전 단어보다 앞서면 false를 반환합니다.

*/

// https://leetcode.com/problems/verifying-an-alien-dictionary/description/
