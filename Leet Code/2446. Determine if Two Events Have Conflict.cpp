class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) 
    {
        vector<int> time1;
        vector<int> time2;
        
        // 시간을 정수화 시킨다.
        for (const auto& t1 : event1) {
            string temp = "";
            for (const auto& ch : t1) {
                if (ch != ':') temp += ch;
            }
            time1.push_back(stoi(temp));
        }
        for  (const auto& t2 : event2) {
            string temp = "";
            for (const auto& ch : t2) {
                if (ch != ':') temp += ch;
            }
            time2.push_back(stoi(temp));
        }
        
        // 정수화 된 시간을 통해 겹치는 구간을 찾는다.
        int time1_begin = time1[0];
        int time1_end = time1[1];

        int time2_begin = time2[0];
        int time2_end = time2[1];

        if (time1_begin <= time2_begin && time2_begin <= time1_end) return true;
        else if (time1_begin <= time2_end && time2_end <= time1_end) return true;
        else if (time2_begin <= time1_end && time1_end <= time2_end) return true;

        return false;
    }
};

// https://leetcode.com/problems/determine-if-two-events-have-conflict/description/
