class Solution {
public:
    vector<string> generatePossibleNextMoves(const string& currentState) 
    {
        const size_t STR_LENGTH = currentState.size();
        vector<string> result;
        
        for (size_t i = 0; i < STR_LENGTH - 1; ++i) {
            string temp = currentState;
            if (temp[i] == '+' && temp[i + 1] == '+') {
                temp[i] = '-';
                temp[i + 1] = '-';
                result.push_back(temp);
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/flip-game/description/
