class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        // tallest building to the right of current index
        int rightMaxHeight = 0;
        
        // i: current index
        int i = heights.size()-1;
        
        // buildingIdx: the result vector to be returned
        vector<int> buildingIdx;
        
        // loop starts from the very end
        while(i >= 0)
        {
            // if the tallest building to the right of current i is shorter
            if(rightMaxHeight < heights[i])
                buildingIdx.push_back(i);
            
            // update tallest building to the right to include current building
            rightMaxHeight = max(rightMaxHeight, heights[i]);
            
            //decrease i by 1 to move left
            i--;
        }
        
        // reverse the building idices as we need it to be in increasing order
        reverse(buildingIdx.begin(), buildingIdx.end());
    
        return buildingIdx;
    }
};