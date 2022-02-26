class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int, char>> pq;
        string result = "";
        
        /* 알파벳 갯수 - 알파벳 매핑 */
        if(a > 0) {                      
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }
        
        int size = 0;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            if (size > 1 && result[size - 1] == it.second && result[size-2] == it.second) { 
                if (pq.empty()) {
                    return result;
                }
                
                result += pq.top().second;
                auto tp = pq.top();
                size++;
                pq.pop();
                
                if( tp.first >1) {
                    pq.push({tp.first-1, tp.second});           
                }
                pq.push({it.first, it.second});
            }
            else {                                  
                result += it.second;
                size++;
                if(it.first > 1) {
                    pq.push({it.first-1, it.second});
                }
            }   
        }
        
        
        return result;
    }
};