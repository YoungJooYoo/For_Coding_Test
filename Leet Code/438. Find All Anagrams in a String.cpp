class Solution {
public:
    vector<int> findAnagrams(const string& s, const string& p) 
    {
        const size_t S_LEN = s.length(); // s의 길이
        const size_t P_LEN = p.length(); // p의 길이
        vector<int> ans; // 결과를 저장할 벡터
        
        // s의 길이가 p보다 작으면 빈 벡터 반환
        if  (S_LEN < P_LEN) {
            return ans;
        }
        
        vector<int> freq_p(ALPHA_LEN, 0); // p의 각 알파벳 빈도 수
        vector<int> window(ALPHA_LEN, 0); // 현재 검사하는 창(window)의 각 알파벳 빈도 수
        
        // 초기화 P_LEN 길이까지만 탐색
        for (size_t i = 0; i < P_LEN; ++i) {
            freq_p[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        
        
        // 첫 번째 창이 p의 빈도와 일치하면 결과에 추가
        if (freq_p == window) ans.push_back(0);
        
        //P_LEN 길이부터 이어서 탐색, 순회하면서 window를 이동
        for (size_t i = P_LEN; i < S_LEN; ++i) {
            window[s[i - P_LEN] - 'a']--; // window의 시작 부분 제거
            window[s[i] - 'a']++; // window의 끝 부분 추가
            // 현재 창이 p의 빈도와 일치하면 결과에 추가
            const int idx = i - P_LEN;
            if (freq_p == window) ans.push_back(idx + 1);
        }

        return ans; // 결과 반환
    }

private:
    enum { ALPHA_LEN = 26 }; // 알파벳 개수
};

/*
이 코드는 슬라이딩 윈도우 기법을 사용하여 s에서 p의 아나그램을 효율적으로 찾습니다. 문자열 p의 각 문자 빈도와 현재 검사하는 창(window)의 문자 빈도를 비교하여 일치할 때마다 해당 시작 인덱스를 결과 벡터에 추가합니다

문제의 목적은 문자열 s 안에서 문자열 p의 아나그램(문자들을 재배열하여 만들 수 있는 다른 단어나 문구)을 찾는 것입니다. 여기서 사용된 방법은 '슬라이딩 윈도우'라는 기법입니다.

문자 빈도 계산: 먼저, 문자열 p의 각 문자가 몇 번 나타나는지 세어둡니다. 예를 들어, p가 "ab"라면, a가 1번, b가 1번 나타납니다.

슬라이딩 윈도우: 문자열 s를 한 문자씩 이동하면서 p의 길이만큼의 문자들을 '창(window)'으로 보고, 이 창 안의 문자들의 빈도를 계산합니다.

비교 및 결과 저장: 이 창의 문자 빈도가 p의 문자 빈도와 일치하는지 확인합니다. 일치하면, 그 창의 시작 인덱스를 결과에 저장합니다.

창 이동: 창을 한 칸씩 오른쪽으로 이동시키며 2번과 3번의 과정을 반복합니다.

이렇게 하여, s의 모든 부분을 검사하고, p의 아나그램이 시작되는 모든 인덱스를 찾아낼 수 있습니다.

*/

// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
