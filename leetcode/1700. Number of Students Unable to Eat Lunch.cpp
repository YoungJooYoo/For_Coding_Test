class Solution 
{
public:
    int countStudents(const vector<int>& students, const vector<int>& sandwiches) 
    {
        queue<int> studnetsQue;

        for (const auto& student : students)
        {
            studnetsQue.push(student);
        }


        int count = 0;
        int idx = 0;
        while (!studnetsQue.empty() && count < studnetsQue.size())
        {
            const int student = studnetsQue.front();
            studnetsQue.pop();
            const int sandwiche = sandwiches[idx];
            

            if (student == sandwiche)
            {
                ++idx;
                count = 0;
            }
            else
            {
                studnetsQue.push(student);
                ++count;
            }
        }
        
        return studnetsQue.size();
    }
};

// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
