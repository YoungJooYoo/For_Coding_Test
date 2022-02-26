class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> pq;
        if(a> 0)                         // Pushing all non-zero occurances in queue
        pq.push({a, 'a'});
        if(b>0)
        pq.push({b, 'b'});
        if(c>0)
        pq.push({c, 'c'});
        string ans = "";
        int size = 0;                    //size of resultant string
        while(!pq.empty()){
            auto it = pq.top();          //pop character with higest occurance
            pq.pop();
            if(size>1 && ans[size-1] == it.second && ans[size-2] == it.second){  //if there are already two consecutive occurances hold that character and pop the next character and put it 
                if(pq.empty())return ans;
                ans += pq.top().second;
                //cout<<ans<<"\n";
                auto tp = pq.top();
                size++;
                pq.pop();
                if(tp.first >1)
                pq.push({tp.first-1, tp.second});               // push the characters back into queue
                pq.push({it.first, it.second});
            }
            else {                                   //otherwise put the character and push it again.
                ans += it.second;
                size++;
                if(it.first > 1)
                pq.push({it.first-1, it.second});
            }
            
        }
        return ans;
        
    }
};