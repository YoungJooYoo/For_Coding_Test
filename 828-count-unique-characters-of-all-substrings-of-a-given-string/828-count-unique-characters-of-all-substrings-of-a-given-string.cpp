
class Solution {
 public:
    int uniqueLetterString(string s) 
    {
        int ans = 0;
        int count = 0;
        vector<int> lastCount(26, 0);
        vector<int> lastSeen(26, -1);

        for (size_t i = 0; i < s.length(); ++i) {
            const int c = s[i] - 'A'; // 0 ~ 26까지 숫자가 나온다. 알파벳 A ~ Z
            const int currentCount = i - lastSeen[c];
            count = count - lastCount[c] + currentCount;
            lastCount[c] = currentCount;
            lastSeen[c] = i;
            ans += count;
        }

        return ans;
     }
};