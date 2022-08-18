class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        for (const auto& word : words) {
            string curr = ""; // 모스부호 단어 만들 문자열
            for (const auto& ch : word) { // 문자열의 알파벳을 모스부호화 메칭하기
                curr += most_codes[ch - 97];
            }
            freq.insert(curr);
        }
        
        return freq.size();
    }
    
private:
    unordered_set<string> freq;
    vector<string> most_codes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",  "..", 
                                 ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                                 "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
};