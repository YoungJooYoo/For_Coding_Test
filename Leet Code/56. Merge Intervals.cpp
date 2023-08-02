class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		vector<vector<int>> result;

		sort(intervals.begin(), intervals.end());

		for (const auto& interval : intervals) {
			// result를 다음과 같이 가정하면 [1, 2], [3, 4]
			// if문이 1과 3을 채우고, else 문이 2,4를 채운다.
			if (result.empty() == true || result.back()[1] < interval[0]) {
				result.push_back(interval); // [1,4] [5,6] 상황에서 [1,4]을 선택해 넣겠다.
				// 완성본 : [1 , 6]
			}
			else { // result.back()[1] >= interval[0])
				result.back()[1] = max(result.back()[1], interval[1]); // [1,4] [5,6] 중 4,6 둘에서 큰거 선택하겠다
			}
		}
		
		return result;
    }
};




// soulution 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> result;
        const size_t n = intervals.size();

        if (n <= 1) return intervals;
        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);
        for (size_t i = 1; i < n; ++i) {
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);

            }
        }

        return result;
    }
};

// https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency
