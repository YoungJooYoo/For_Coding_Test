class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
    {
        vector<vector<int>> res;
        int  toBeRemoved_start = toBeRemoved[0];
        int toBeRemoved_end = toBeRemoved[1];
        
        for (const auto& interval : intervals) {
            if (interval[1] <= toBeRemoved_start || interval[0] >= toBeRemoved_end) { // toBeRomoved 배열에 속하지 않는 범위면, 정답 배열에 interval을 그대로 넣는다.
                res.push_back(interval);
            }
            else { // toBeRomoved 범위안에 intervals가 있는 경우라면, 겹치지 않는 부분만 잘라서 넣는다.
                if (interval[0] < toBeRemoved_start) {
                    res.push_back({interval[0], toBeRemoved_start});
                }
                if (interval[1] > toBeRemoved_end) {
                    res.push_back({toBeRemoved_end, interval[1]});
                }
            }
        }
        
        return res;
    }
};

/*
풀이법 :

1. 겹치지 않는 범위의 intervals의 원소들을 찾는다.
2. 겹치는 부분이 있는 것들은, 겹치지 않는 범위를 찾는다.

*/