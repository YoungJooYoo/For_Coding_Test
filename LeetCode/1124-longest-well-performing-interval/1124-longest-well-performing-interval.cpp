class Solution {
public:
     int longestWPI(vector<int>& hours) 
     {
        const size_t hours_length = hours.size();
        unordered_map<int, int> mp;
        int res = 0; 
        int score = 0; 
        
        for (int i = 0; i < hours_length; ++i) {
            hours[i] = hours[i] > 8 ? 1 : -1;
            score = score + hours[i];
            if (score > 0) {
                res = i + 1; // day = index + 1;
            } 
            else { // score  <= 0;
                if (mp.find(score) == mp.end()) { // 최종결과(새 최소값) score를 key로 삼아 인덱스와 매칭
                   mp[score] = i; // match score to index after caculated.
                }
                if (mp.find(score - 1) != mp.end()) { // 양수의 score 최초발생 지점
                    res = max(res, i - mp[score - 1]);
                } 
            }
        }
         
        return res;
    }
};