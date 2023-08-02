class Solution {
public:
    string interpret(string command) 
    {
        string result = "";
        size_t i = 0;

        while (i < command.size()) {
            if (command[i] == 'G') {
                result += 'G';
                ++i;
            }
            else if (command[i] == '(' && command[i + 1] == ')') {
                result += "o";
                i = i + 2;
            }
            else {
                result += "al";
                i = i + 4;
            }
        } 

        return result;
    }
};

// https://leetcode.com/problems/goal-parser-interpretation/description/
