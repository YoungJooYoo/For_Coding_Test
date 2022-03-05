class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<int> cnt(26, INT_MAX); // 알파벳 26개, 배열 초기화
        vector<string> res;
        
        for (const auto& word : words) {
            vector<int> cnt1(26, 0);
            for (const auto& ch : word) {
                ++cnt1[ch - 'a']; // 문자열을 알파벳으로 분해해 얼마나 나오는지 빈도수 체크
            }
            for (size_t i = 0; i < 26; ++i) {
                cnt[i] = min(cnt[i], cnt1[i]); //
            }
        }
        
        for (size_t i = 0; i < 26; ++i) {
            for (size_t j = 0; j < cnt[i]; ++j) {
                res.push_back(string(1, i + 'a')); // 문자열 생성자, 1개 생성 그 내용은 i + a   
            }
        }
                
        return res;
    }
};