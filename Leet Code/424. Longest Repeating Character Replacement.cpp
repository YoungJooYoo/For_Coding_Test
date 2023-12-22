class Solution {
public:
    int characterReplacement(const string& s, const int k) 
    {
        unordered_map<char, int> freq; // 문자별 빈도수를 저장하는 해시 테이블
        const size_t LEN = s.size(); // 문자열 길이
        int max_freq = 0; // 현재 윈도우 내 가장 빈번한 문자의 빈도수
        int max_len = 0; // 최대 부분 문자열 길이
        int i = 0; // 슬라이딩 윈도우 시작 인덱스
        int j = 0; // 슬라이딩 윈도우 끝 인덱스

        while (j < LEN) { // 문자열 끝까지 반복
            ++freq[s[j]]; // 현재 문자 빈도수 증가
            max_freq = max(max_freq, freq[s[j]]); // 최대 빈도수 업데이트

            int substr_len = j - i + 1; // 현재 부분 문자열 길이 계산
            if (substr_len - max_freq > k) { // 변경 가능한 문자 수가 k 초과하는 경우
                --freq[s[i]]; // 시작 문자 빈도수 감소
                i++; // window 시작 인덱스 증가
            }
            substr_len = j - i + 1; // 업데이트된 부분 문자열 길이 재계산
            max_len = max(max_len, substr_len); // 최대 부분 문자열 길이 업데이트
            ++j; // 다음 문자로 이동
        }

        return max_len; // 계산된 최대 부분 문자열 길이 반환
    }
};

// https://leetcode.com/problems/longest-repeating-character-replacement/description/
