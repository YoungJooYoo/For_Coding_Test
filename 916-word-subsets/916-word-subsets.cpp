class Solution 
{
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string> result;
        vector<int> words2_max_freq(MAX, 0);
        
        for (const auto& word : words2) {
            vector<int> words2_freq(MAX, 0);
            for (const auto& ch : word) {  // 비교해야할 단어 word2를 해시테이블에 담아 빈도를 체크한다.
                words2_freq[ch - 'a']++;
            }
            for (size_t i = 0; i < MAX; i++) { // words2에서 각 알파벳의 모든 빈도를 다 구한다.
                words2_max_freq[i] = max(words2_max_freq[i], words2_freq[i]);    
            }
        }
        
        
        for (const auto& word : words1) {
            vector<int> words1_freq(MAX, 0);
            bool b_is_all = true;
            
            for (const auto& ch : word) {  // 비교해야할 단어 word1를 해시테이블에 담아 빈도를 체크한다.
                words1_freq[ch - 'a']++;
            }
            
            for (size_t i = 0; i < MAX; i++) {
                if (words1_freq[i] < words2_max_freq[i]) { // words2의 원소를 모두 가지고 있지 않다면, false로
                    b_is_all = false;
                    break;
                }
            }
            
            if (b_is_all == true) {
                result.push_back(word);    
            }
        } 
        
        return result;
    }
    
private:
    enum { MAX = 26 };
};