class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        int rightMaxHeight = 0; // tallest building to the right of current index
        int i = heights.size() - 1; // i: current index
        vector<int> result; 
        
        /* 배열의 맨 뒤에서부터 작은 건물 순서대로 접근을 시작한다. */
        while (i >= 0) { // loop starts from the very end
            if (rightMaxHeight < heights[i]) { // 뒤에서부터 출발해 점점 건물이 커지는 조건이 맞다면 정답배열에 넣는다. 
                result.push_back(i);
            }
            rightMaxHeight = max(rightMaxHeight, heights[i]); // update tallest building to the right to include current building
            i--; //decrease i by 1 to move left
        }
        
        reverse(result.begin(), result.end()); // reverse the building idices as we need it to be in increasing order
    
        return result;
    }
};

/*
풀이법 :
건물이 이미 어느정도 정렬이 되어, 내림채순으로 되어있다.
주어진 배열의 맨뒤부터 접근하면, 건물은 점점 커지게 된다.

건물이 커지게 되면 가장 최근에 높은 값을 저장하면서
높아지지 않는 건물은 제외하고 정답배열에 인덱스를 넣는다.

문제는 정렬이된 배열을 원하므로, reverse로 정렬 후 반환하면 된다.

*/