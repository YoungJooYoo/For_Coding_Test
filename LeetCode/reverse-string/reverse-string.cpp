class Solution {
public:
    void reverseString(vector<char>& s) {
        const size_t string_length = s.size();
        int begin_index = 0;
        int end_index = string_length - 1;
        char temp;
        
        while(begin_index < end_index) {
            temp = s.at(begin_index);
            s.at(begin_index) = s.at(end_index);
            s.at(end_index) = temp;
            begin_index++;
            end_index--;
        }
    }
};