class Solution {
public:
    string originalDigits(string s) 
    {    
        const size_t str_length = s.length();
        int num[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        
        string word[]={"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        char hint[]={'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        vector<int> cnt(26, 0); // 알파벳 개수 26개
        string ans = "";
        
        if (str_length == 0) {
            return "";
        }
        
        for (const auto& it : s) {
            cnt[it - 'a']++;
        }
        
        for (size_t i = 0; i <= 9; i++) {
            int idx = hint[i] - 'a';
            int count = cnt[idx];
            
            for (size_t j = 0; j < word[i].length(); j++) {
                cnt[word[i][j]-'a']-=count;
            }
            while (count) {    
                ans+=to_string(num[i]);
                count--;
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};