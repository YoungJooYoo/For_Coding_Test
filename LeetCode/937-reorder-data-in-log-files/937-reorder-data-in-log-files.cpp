class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {    
        vector<string> diglog;
        vector<pair<string, string>> letlog;
        for (const string& log : logs) {
            size_t i = 0;
            while (log[i]!=' ') {
                i++;
            } 
            if (isalpha(log[i + 1])) { //  알파뱃인지 확인
                letlog.emplace_back(log.substr(0, i), log.substr(i + 1));
            }
            else {
                diglog.push_back(log);
            }
        }
        sort(letlog.begin(), letlog.end(), [&](auto& a, auto& b) {
            return a.second==b.second? a.first<b.first : a.second<b.second;
        });
        
        vector<string> ret;
        for(const auto& p : letlog) {
            ret.push_back(p.first + " " + p.second);
        }
        for(const string& s : diglog) {
            ret.push_back(s);
        }
        
        return ret;
    }
};