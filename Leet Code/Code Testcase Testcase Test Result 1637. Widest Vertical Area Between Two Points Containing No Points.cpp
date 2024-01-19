class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> x;
        for(auto& coord: points)
            x.insert(coord[0]);
        int mdiff=0,  prev=*x.begin();
        for (int x1: x){
            mdiff=max(mdiff, x1-prev);
            prev=x1;
        }
        return mdiff;       
    }
};
