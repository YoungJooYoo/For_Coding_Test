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

/*
n the given string start, 
L can move to the left but can't pass through R, 
R can move to the right but can't pass through L. 
Basically, there are 4 situations (when start[i] != 'X' and end[j] != 'X'):

start[i] != end[j] return false, cause L and R can't pass through each other.
start[i] == 'L' && j > i return false, cause L can't move to the right.
start[i] == 'R' && j < i return false cause R can't move to the left.
*/