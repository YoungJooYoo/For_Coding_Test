class Solution {
public:
    double average(vector<int>& salary) 
    {
        double sum = 0;
        sort(salary.begin(), salary.end());

        for (size_t i = 1; i < salary.size() - 1; i++) {
            sum += salary[i];
        }

        return sum / (salary.size() - 2);
    }
};

// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
