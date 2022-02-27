#define ALPHABET_LENGTH (26)

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > ALPHABET_LENGTH) {
            return 0;
        }
        
        int answer = 0;
        int n = s.size();
        
        for (int i = 0; i <= n - k; i++) {
            int freq[ALPHABET_LENGTH] = {0};
            bool isUnique = true;
            
            for (int j = i; j < i + k; j++) {
                freq[s[j] - 'a']++;
                
                if (freq[s[j] - 'a'] > 1) {
                    isUnique = false;
                    break;
                }
            }
            
            if (isUnique) {
                answer++;
            }
        }
        
        return answer;
    }
};