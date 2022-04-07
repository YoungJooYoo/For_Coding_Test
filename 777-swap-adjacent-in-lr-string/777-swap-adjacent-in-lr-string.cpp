class Solution {
public:
    bool canTransform(string start, string end) 
    {
        size_t i = 0;
        size_t j = 0;
        
        for (; i < start.size() && j < end.size();) {
            if (start[i] == 'X') { // X가 먼너 나오면, 패스 이미 바뀐 것
                i++;
            }
            if (end[j] == 'X') {
                j++;
            }
            if (start[i] != 'X' && end[j] != 'X') {
                if (start[i] != end[j]) {
                    return false;
                }
                else if (start[i] == 'L' && j > i) {
                    return false;
                }
                else if (start[i] == 'R' && j < i) {
                    return false;
                }
                else {
                    i++;
                    j++;
                }
            }
        }
        
        while (i < start.size()) {
            if (start[i] != 'X') {
                return false;
            }
            i++;
        }
        
        while (j < end.size()) {
            if (end[j] != 'X') {
                return false;
            }
            j++;
        }
        
        return true;
    }
};