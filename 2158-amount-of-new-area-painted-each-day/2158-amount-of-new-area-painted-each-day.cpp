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
                auto start_idx = inter.upper_bound(start);
                auto end_idx = inter.upper_bound(end);
                
                if (start_idx != inter.begin()) {
                    start_idx--;
                }
                if (start_idx->second < start) {
                    start_idx++;
                }  
                while (start_idx != end_idx) { // from before begin to after end
                    size -= min(end, start_idx->second) - max(start, start_idx->first);
                    start = min(start, start_idx->first);
                    end = max(end, start_idx->second);
                    start_idx = inter.erase(start_idx);                                        
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