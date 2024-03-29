class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> map;

        for (const string& email : emails) {
            string temp_email;
            for (const char& ch : email) {
                if (ch == '+' or ch == '@') {
                    break; // + @ 나오면 뒤에 문자열을 붙이기 위해 break;
                }
                if (ch == '.') {
                    continue; // /. 패스함
                }
                temp_email = temp_email + ch;
            }
            temp_email = temp_email + email.substr(email.find('@')); // @ 찾은시점부터 뒤까지 문자열 반환
            map.insert(temp_email);
        }
        
        return map.size();
    }
};