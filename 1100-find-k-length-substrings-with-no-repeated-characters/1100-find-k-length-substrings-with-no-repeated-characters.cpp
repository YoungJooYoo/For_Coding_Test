#define ALPHABET_LENGTH (26)

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) 
    {
        if (k > ALPHABET_LENGTH) {
            return 0;
        }
        
        int answer = 0;
        const int n = s.size();
        
        for (int i = 0; i <= n - k; i++) { // k범위만큼 지속적으로 검사하는 로직
            int freq[ALPHABET_LENGTH] = {0};  // 알파벳 개수 26개, 알파벳 빈도수 체크용 배열
            bool isUnique = true;
            for (int j = i; j < i + k; j++) {
                freq[s[j] - 'a']++;
                if (freq[s[j] - 'a'] > 1) {
                    isUnique = false; // 중복을 찾을시 멈춤
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