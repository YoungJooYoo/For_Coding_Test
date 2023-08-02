class Solution {
public:
    bool isStrobogrammatic(string num) 
    {
        unordered_map<char, int> dictionary = { {'6','9'},
                                                {'9','6'},
                                                {'8','8'},
                                                {'0','0'},
                                                {'1','1'}
                                              };
        
        string temp = num;
        reverse(temp.begin(), temp.end());
        
        // 180도 뒤집힌 문자 만들기
        for(size_t i = 0; i < num.size(); i++){  
            temp[i] = dictionary[temp[i]];
        }
        
        return (num == temp) ? true : false;
    }
};