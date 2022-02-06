class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> map;

        for (const string& email : emails) {
            string temp_email;
            for (const char& c : email) {
                if (c == '+' or c == '@') {
                    break;
                }
                if (c == '.') {
                    continue;
                }
                temp_email = temp_email + c;
            }
            temp_email = temp_email + email.substr(email.find('@'));
            map.insert(temp_email);
        }
        
        return map.size();
    }
};