class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        int rightMaxHeight = 0; // tallest building to the right of current index
        int i = heights.size() - 1; // i: current index
        vector<int> buildingIdx; // buildingIdx: the result vector to be returned
        
        /* 배열의 맨 뒤에서부터 작은 건물 순서대로 접근을 시작한다. */
        while (i >= 0) { // loop starts from the very end
            if (rightMaxHeight < heights[i]) { // 뒤에서부터 출발해 점점 건물이 커지는 조건이 맞다면 정답배열에 넣는다. 
                buildingIdx.push_back(i);
            }
            rightMaxHeight = max(rightMaxHeight, heights[i]); // update tallest building to the right to include current building
            i--; //decrease i by 1 to move left
        }
        
        reverse(buildingIdx.begin(), buildingIdx.end()); // reverse the building idices as we need it to be in increasing order
    
        return buildingIdx;
    }
};