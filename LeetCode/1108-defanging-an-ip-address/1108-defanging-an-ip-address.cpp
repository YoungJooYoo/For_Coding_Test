class Solution {
public:
    string defangIPaddr(string address) 
    {
        for (size_t i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                ans = ans + "[.]";
            }
            else {
                ans = ans + address[i];
            }
        }
         
        return ans;
    }
private:
    string ans = "";
};