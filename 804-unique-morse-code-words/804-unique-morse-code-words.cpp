class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        for (const auto& word : words) {
            string curr = "";
            for (const auto& ch : word) {
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