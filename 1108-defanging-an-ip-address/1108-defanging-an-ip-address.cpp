class Solution {
public:
    string defangIPaddr(string address) 
    {
        // 원소단위로 복사
        // . 나온순간 => [.] 붙이기
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