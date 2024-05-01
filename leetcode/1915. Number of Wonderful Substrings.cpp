class Solution {
public:
    long long wonderfulSubstrings(const string& word) 
    {
        int count[LENGTH] = {1, }; // 비트마스크로 문자 빈도수를 저장하기 위한 배열
        long long result = 0;
        int bitmask = 0; // 현재까지의 비트마스크

        for (const char& ch : word) {
            bitmask ^= 1 << (ch - 'a'); // 비트마스크 업데이트
            result += count[bitmask]; // 현재 비트마스크까지의 원더풀한 부분 문자열 수 누적
            for (int i = 0; i < 10; ++i) {
                result += count[bitmask ^ (1 << i)]; // 현재 비트마스크와 1 비트를 바꾼 비트마스크까지의 원더풀한 부분 문자열 수 누적
            }
            ++count[bitmask]; // 현재 비트마스크를 배열에 저장
        }

        return result;
    }

private:
    enum { LENGTH = 1024 };
};


// https://leetcode.com/problems/number-of-wonderful-substrings/description/?envType=daily-question&envId=2024-04-30
