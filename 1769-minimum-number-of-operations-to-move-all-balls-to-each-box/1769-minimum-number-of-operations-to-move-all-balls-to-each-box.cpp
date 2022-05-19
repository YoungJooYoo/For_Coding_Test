class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        const size_t BOXES_LENGTH = boxes.size();
        vector<int> res(BOXES_LENGTH);
        
        for (size_t i = 0, ops = 0, cnt = 0; i < BOXES_LENGTH; ++i) {
           res[i] += ops;
           cnt += boxes[i] == '1' ? 1 : 0;
           ops += cnt;
        }
        for (int i = BOXES_LENGTH - 1, ops = 0, cnt = 0; i >= 0; --i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        
        return res;
    }
};