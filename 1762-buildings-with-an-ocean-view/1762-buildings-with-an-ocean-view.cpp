class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        int rightMaxHeight = 0; // tallest building to the right of current index
        int i = heights.size() - 1; // i: current index
        vector<int> buildingIdx; // buildingIdx: the result vector to be returned
        
        while (i >= 0) { // loop starts from the very end
            if (rightMaxHeight < heights[i]) {// if the tallest building to the right of current i is shorter
                buildingIdx.push_back(i);
            }
            rightMaxHeight = max(rightMaxHeight, heights[i]); // update tallest building to the right to include current building
            i--; //decrease i by 1 to move left
        }
        
        reverse(buildingIdx.begin(), buildingIdx.end()); // reverse the building idices as we need it to be in increasing order
    
        return buildingIdx;
    }
};