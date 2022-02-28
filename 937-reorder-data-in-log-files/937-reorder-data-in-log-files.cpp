class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {    
        vector<string> diglog;
        vector<pair<string, string>> letlog;
        for (const string& log : logs) {
            int i = 0;
            while (log[i]!=' ') {
                i++;
            } 
            if (isalpha(log[i+1])) {
                letlog.emplace_back(log.substr(0, i), log.substr(i+1));
            }
            else {
                diglog.push_back(log);
            }
        }
        sort(letlog.begin(), letlog.end(), [&](auto& a, auto& b) //comparator to check if second part of string, i.e. the string 
             //without identifier equal then compare identifier, or else compare second half and decide sorting on that
             {
                 return a.second==b.second? a.first<b.first : a.second<b.second;
             });
        
        vector<string> ret;
        for(auto &p:letlog) ret.push_back(p.first + " " + p.second);
        for(string &s:diglog) ret.push_back(s);
        return ret;
    }
};