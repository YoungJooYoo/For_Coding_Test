class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // needle 비었다면 return 0 
        if (needle.size() == 0) {
            return 0;
        }
        // aaa가 존재하지 않는다면 -1반환
         if (haystack.size() < needle.size() || haystack.empty() == true) {
            return -1;
        }
        
        return haystack.find(needle);;
    }
};