class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k > 26)
            return 0;
        
        int answer = 0;
        int n = s.size();
        
        for (int i = 0; i <= n - k; i++) {
            // Initializing an empty frequency array
            int freq[26] = {0};
            bool isUnique = true;
            
            for (int j = i; j < i + k; j++) {
                // Incrementing the frequency of current character
                freq[s[j] - 'a']++;
                
                // If a repeated character is found, we stop the loop
                if (freq[s[j] - 'a'] > 1) {
                    isUnique = false;
                    break;
                }
            }
            
            // If the substring does not have any repeated characters,
            // we increment the answer
            if (isUnique) {
                answer++;
            }
        }
        
        return answer;
    }
};