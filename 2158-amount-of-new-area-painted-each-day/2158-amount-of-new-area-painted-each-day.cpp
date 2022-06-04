class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) 
    {
        map<int, int> inter; // begin->end
        vector<int> res;
        
        for (const auto& element : paint) {
            int start = element[0];
            int end = element[1];
            int size = end - start;
            
            if (!inter.empty()) {
                auto bit = inter.upper_bound(start);
                auto eit = inter.upper_bound(end);
                
                if (bit != inter.begin()) {
                    bit--;
                }
                if (bit->second < start) {
                    bit++;
                }
                for (; bit != eit;) {     // from before begin to after end
                    size -= min(end, bit->second) - max(start, bit->first);
                    start = min(start, bit->first);
                    end = max(end, bit->second);
                    bit = inter.erase(bit);                                        
                }
            }
            inter[start] = end;
            res.push_back(size);
        }
        
        return res;
    }
    
private:
    enum { MAX_LENGTH = 100000 + 4 };
};