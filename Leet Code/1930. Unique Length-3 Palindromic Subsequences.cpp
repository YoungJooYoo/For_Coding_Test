class Solution {
public:
    int countPalindromicSubsequence(const string& s) 
    {
        // 각 알파벳 문자에 대해 처음과 마지막 인덱스를 기록할 배열을 초기화
        int first[ALPHABET_LENGTH] = {[0 ... 25] = INT_MAX};
        int last[ALPHABET_LENGTH] = {};
        int result = 0;
        
        // 문자열을 순회하며 각 문자의 처음과 마지막 인덱스를 업데이트
        for (int i = 0; i < s.size(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i); // 최소 인덱스 업데이트
            last[s[i] - 'a'] = i; // 최대 인덱스 업데이트
        }
        
        // 알파벳의 개수만큼 반복하여 길이 3의 유일한 회문 부분 수열의 개수를 계산
        for (int i = 0; i < ALPHABET_LENGTH; ++i)
            // 해당 문자의 처음 인덱스가 마지막 인덱스보다 작으면 회문 가능성 있음
            if (first[i] < last[i])
                // 첫 번째와 마지막 인덱스 사이에 있는 고유한 문자들의 개수를 결과에 추가
                result += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
        
        // 계산된 결과 반환
        return result;
    }

private:
    enum { ALPHABET_LENGTH = 26 };
};

// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
