class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) 
    {
        vector<int> result = {first, };

        for (const auto& elem : encoded) {
            first ^= elem; 
            result.push_back(first);
        }

        return result;
    }
};
